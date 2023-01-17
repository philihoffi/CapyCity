#include "Blueprint.h"
#include <iostream>


std::string Blueprint::printCharMultipleTimes(char c, int times)
{
	std::string s = "";
	for (int i = 0; i < times; ++i)
		s += c;
	return s;
}

Building*** Blueprint::getBuildSpace()
{
	return this->buildSpace;
}

Blueprint::Blueprint(int length, int width)
{
	this->length = length;
	this->width = width;

	buildSpace = new Building * *[length];
	for (int i = 0; i < length; i++)
	{
		buildSpace[i] = new Building * [width];
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			buildSpace[i][j] = new EmptySpace();
		}
	}

	allBuildingTypes[0] = Building(*new EmptySpace());
	allBuildingTypes[1] = Building(*new Windmill());
	allBuildingTypes[2] = Building(*new Residential());
}

Blueprint::~Blueprint()
{
	//To-DO überprüfen stimmt evtl nicht
	for (int i = 0; i < width; ++i)
	{
		delete buildSpace[i];
	}
	delete buildSpace;
}


bool Blueprint::validBuildspace(int buildingWidth, int buildingLength, int posWidth, int posLength)
{
	if (buildingWidth < 1 || buildingLength < 1 || posWidth < 0 || posLength < 0)
	{
		std::cout << "value was either too large or too smalll" << std::endl;
		return false;
	}
	if (buildingWidth + posWidth > width || buildingLength + posLength > length)
	{
		std::cout << "value was either too large or too small" << std::endl;
		return false;
	}
	return true;
}

bool Blueprint::collidingWithOtherBuilding(int buildingWidth, int buildingLength, int posWidth, int posLength)
{
	for (int i = posWidth; i < width && buildingWidth > 0; i++, buildingWidth--)
	{
		int buildingLengthSave = buildingLength;
		for (int j = posLength; j < length && buildingLength > 0; j++, buildingLength--)
			if (getBuildSpace()[i][j]->getLabel() != ' ')
			{
				std::cout << "colliding with other Building" << std::endl;
				return false;
			}
		buildingLength = buildingLengthSave;
	}
	return true;
}

bool Blueprint::validBuilding(char input)
{
	for (Building x : allBuildingTypes)
		if (x.getLabel() == input)
			return true;
	return false;
}

void Blueprint::changeBuildSpace(int buildingWidth, int buildingLength, int posWidth, int posLength, Building* buildType)
{
	for (int i = posWidth; i < width && buildingWidth > 0; i++, buildingWidth--)
	{
		int buildingLengthSave = buildingLength;
		for (int j = posLength; j < length && buildingLength > 0; j++, buildingLength--) {
			delete getBuildSpace()[i][j];
			getBuildSpace()[i][j] = new Building(*buildType);
		}
		buildingLength = buildingLengthSave;
	}
	delete buildType;
}

int Blueprint::buildBuilding()
{
	int buildingLength;
	int buildingWidth;
	int posWidth;
	int posLength;
	Building* buildType;
	do
	{
		std::cout << "exit = -1" << std::endl;
		std::cout << "Bitte breite(Y) des Gebäudes eingeben -> ";
		std::cin >> buildingWidth;
		std::cout << "Bitte länge(X) des Gebäudes eingeben -> ";
		std::cin >> buildingLength;
		std::cout << "posY -> ";
		std::cin >> posWidth;
		std::cout << "posX -> ";
		std::cin >> posLength;

		if (buildingWidth == -1 || buildingLength == -1 || posWidth == -1 || posLength == -1)
			return 1;

	} while (!validBuildspace(buildingWidth, buildingLength, posWidth, posLength) || !collidingWithOtherBuilding(buildingWidth, buildingLength, posWidth, posLength));

	char userInput;
	std::cout << "Gebäudeart :" << std::endl;
	for (Building x : allBuildingTypes)
		if (x.getLabel() != ' ')
			std::cout << "\t" << (char)x.getLabel() << ": " << x.getClassname() << std::endl;
	do
	{
		std::cin >> userInput;
	} while (!validBuilding(userInput));

	buildType = getBuilding(userInput);
	changeBuildSpace(buildingWidth, buildingLength, posWidth, posLength, buildType);

	return 1;
}

int Blueprint::deleteBuilding()
{
	int deletLength;
	int deletWidth;
	int posWidth;
	int posLength;

	do
	{
		std::cout << "exit = -1" << std::endl;
		std::cout << "Bitte breite(Y) des Abriss eingeben -> ";
		std::cin >> deletWidth;
		std::cout << "Bitte länge(X) des Abriss eingeben -> ";
		std::cin >> deletLength;
		std::cout << "posY -> ";
		std::cin >> posWidth;
		std::cout << "posX -> ";
		std::cin >> posLength;

		if (deletWidth == -1 || deletLength == -1 || posWidth == -1 || posLength == -1)
			return 1;
	} while (!validBuildspace(deletWidth, deletLength, posWidth, posLength));

	changeBuildSpace(deletWidth, deletWidth, posWidth, posLength, new EmptySpace());

	return 1;
}

Building* Blueprint::getBuilding(char label)
{
	for (Building x : allBuildingTypes)
		if (x.getLabel() == label)
			return new Building(x);
}

bool Blueprint::operator()(Blueprint* other)
{
	if (other == nullptr)
		return false;
	if (other == this)
		return false;
	for (int i = width - 1; i >= 0; i--)
	{
		for (int j = 0; j < length; j++)
		{
			if (getBuildSpace()[i][j]->getLabel() == other->getBuildSpace()[i][j]->getLabel())
				return false;
		}
	}
	return true;
}

int Blueprint::showMap()
{
	std::cout << "Indicator: " << getIndicator() << std::endl;
	std::cout << getBuildSpaceAsString() << std::endl;

	for (Building x : allBuildingTypes)
		if (x.getLabel() != ' ')
			std::cout << x.toString() << std::endl;
	std::cout << printCharMultipleTimes('-', 20) << std::endl;
	int totalCost = 0;
	int totalWood = 0;
	int totalPlastic = 0;
	int totalMetal = 0;
	int totalPower = 0;


	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (getBuildSpace()[i][j]->getLabel() != ' ') {
				Building* tmp = getBuildSpace()[i][j];
				totalCost += tmp->getTotalPrice();

				for (auto& m : tmp->getMaterials()) {
					if (m.first->getClassName() == "Metal") {
						totalMetal += m.second;
					}
					else if (m.first->getClassName() == "Plastic") {
						totalPlastic += m.second;
					}
					else if (m.first->getClassName() == "Wood") {
						totalWood += m.second;
					}
				}



			}
		}
	}

	std::cout << "Total Wood required:\t" << totalWood << std::endl;
	std::cout << "Total Metal required:\t" << totalMetal << std::endl;
	std::cout << "Total Plastic required:\t" << totalPlastic << std::endl;
	std::cout << printCharMultipleTimes('-', 20) << std::endl;
	std::cout << "Total Plastic required:\t" << totalPower << std::endl;
	std::cout << printCharMultipleTimes('-', 20) << std::endl;
	std::cout << "Total Cost:\t" << totalCost << std::endl;
	return 1;
}

std::string Blueprint::getBuildSpaceAsString()
{
	std::ostringstream result;

	result << "+" << printCharMultipleTimes('-', length * 2 + 1) << '+' << std::endl;
	for (int i = width - 1; i >= 0; i--)
	{
		result << "| ";
		for (int j = 0; j < length; j++)
		{
			result << (char)getBuildSpace()[i][j]->getLabel() << ' ';
		}
		result << '|' << std::endl;
	}
	result << "+" << printCharMultipleTimes('-', length * 2 + 1) << '+' << std::endl;

	return result.str();
}

float Blueprint::getIndicator()
{
	float k=0, totalPower = 0, totalPrice=0, totalArea=0;

	for (int i = width - 1; i >= 0; i--)
	{
		for (int j = 0; j < length; j++)
		{
			totalPower+=getBuildSpace()[i][j]->getPower();
			totalPrice+=getBuildSpace()[i][j]->getTotalPrice();
			totalArea++;
			//std::cout << "totalPower" << totalPower << "totalPrice" << totalPrice << "totalArea" << totalArea << std::endl;
		}
	}

	std::cout << "totalPower:" << totalPower << " totalPrice:" << totalPrice << " totalArea:" << totalArea << std::endl;
	if (totalPrice != 0){
		k = totalPower / (totalPrice * totalArea);
		std::cout << k << std::endl;
	}
	else
		return 0;

	return k;
}

