#include "CapycitySim.h"
#include <iostream>

using namespace std;

string CapycitySim::printCharMultipleTimes(char c, int times)
{
	string s = "";
	for (int i = 0; i < times; ++i)
		s += c;
	return s;
}

bool CapycitySim::validBuildspace(int buildingWidth, int buildingLength, int posWidth, int posLength)
{
	if (buildingWidth < 1 || buildingLength < 1 || posWidth < 0 || posLength < 0)
	{
		cout << "value was either too large or too smalll" << endl;
		return false;
	}
	if (buildingWidth + posWidth > width || buildingLength + posLength > length)
	{
		cout << "value was either too large or too small" << endl;
		return false;
	}
	return true;
}

bool CapycitySim::collidingWithOtherBuilding(int buildingWidth, int buildingLength, int posWidth, int posLength)
{
	for (int i = posWidth; i < width && buildingWidth > 0; i++, buildingWidth--)
	{
		int buildingLengthSave = buildingLength;
		for (int j = posLength; j < length && buildingLength > 0; j++, buildingLength--)
			if (buildSpace[i][j]->getLabel() != ' ')
			{
				cout << "colliding with other Building" << endl;
				return false;
			}
		buildingLength = buildingLengthSave;
	}
	return true;
}

bool CapycitySim::validBuilding(char input)
{
	for (Building x : allBuildingTypes)
		if (x.getLabel() == input)
			return true;
	return false;
}

void CapycitySim::changeBuildSpace(int buildingWidth, int buildingLength, int posWidth, int posLength, Building* buildType)
{
	for (int i = posWidth; i < width && buildingWidth > 0; i++, buildingWidth--)
	{
		int buildingLengthSave = buildingLength;
		for (int j = posLength; j < length && buildingLength > 0; j++, buildingLength--) {
			delete buildSpace[i][j];
			buildSpace[i][j] = new Building(*buildType);
		}
		buildingLength = buildingLengthSave;
	}
	delete buildType;
}

int CapycitySim::buildBuilding()
{
	int buildingLength;
	int buildingWidth;
	int posWidth;
	int posLength;
	Building* buildType;
	do
	{
		cout << "exit = -1" << endl;
		cout << "Bitte breite(Y) des Geb�udes eingeben -> ";
		cin >> buildingWidth;
		cout << "Bitte l�nge(X) des Geb�udes eingeben -> ";
		cin >> buildingLength;
		cout << "posY -> ";
		cin >> posWidth;
		cout << "posX -> ";
		cin >> posLength;

		if (buildingWidth == -1 || buildingLength == -1 || posWidth == -1 || posLength == -1)
			return 1;

	} while (!validBuildspace(buildingWidth, buildingLength, posWidth, posLength) || !collidingWithOtherBuilding(buildingWidth, buildingLength, posWidth, posLength));

	char userInput;
	cout << "Geb�udeart :" << endl;
	for (Building x : allBuildingTypes)
		if (x.getLabel() != ' ')
			cout << "\t" << (char)x.getLabel() << ": " << x.getClassname() << endl;
	do
	{
		cin >> userInput;
	} while (!validBuilding(userInput));

	buildType = getBuilding(userInput);
	changeBuildSpace(buildingWidth, buildingLength, posWidth, posLength, buildType);

	return 1;
}

int CapycitySim::deleteBuilding()
{
	int deletLength;
	int deletWidth;
	int posWidth;
	int posLength;

	do
	{
		cout << "exit = -1" << endl;
		cout << "Bitte breite(Y) des Abriss eingeben -> ";
		cin >> deletWidth;
		cout << "Bitte l�nge(X) des Abriss eingeben -> ";
		cin >> deletLength;
		cout << "posY -> ";
		cin >> posWidth;
		cout << "posX -> ";
		cin >> posLength;

		if (deletWidth == -1 || deletLength == -1 || posWidth == -1 || posLength == -1)
			return 1;
	} while (!validBuildspace(deletWidth, deletLength, posWidth, posLength));

	changeBuildSpace(deletWidth, deletWidth, posWidth, posLength, new EmptySpace());

	return 1;
}

int CapycitySim::showMap()
{
	cout << "+" << printCharMultipleTimes('-', length * 2 + 1) << '+' << endl;
	for (int i = width - 1; i >= 0; i--)
	{
		cout << "| ";
		for (int j = 0; j < length; j++)
		{
			cout << (char)buildSpace[i][j]->getLabel() << ' ';
		}
		cout << '|' << endl;
	}
	cout << "+" << printCharMultipleTimes('-', length * 2 + 1) << '+' << endl;


	for (Building x : allBuildingTypes)
		if (x.getLabel() != ' ')
			cout << x.toString() << endl;
	cout << printCharMultipleTimes('-', 20) << endl;

	int totalCost = 0;
	int totalWood = 0;
	int totalPlastic = 0;
	int totalMetal = 0;


	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (buildSpace[i][j]->getLabel() != ' ') {
				Building* tmp = buildSpace[i][j];
				totalCost += tmp->getPrice();
				for (Material x : tmp->getMaterials()) {
					totalCost += x.getPrice();
					if (x.getClassName() == "Metal") {
						totalMetal += 1;
					}
					else if (x.getClassName() == "Plastic") {
						totalPlastic += 1;
					}
					else if (x.getClassName() == "Wood") {
						totalWood += 1;
					}
				}



			}
		}
	}

	cout << "Total Wood required:\t" << totalWood<<endl;
	cout << "Total Metal required:\t" << totalMetal << endl;
	cout << "Total Plastic required:\t" << totalPlastic << endl;
	cout << printCharMultipleTimes('-', 20) << endl;
	cout << "Total Cost:\t" << totalCost << endl;
	return 1;
}

int CapycitySim::endProgram()
{
	return -1;
}

int CapycitySim::menu()
{
	cout << "+" << printCharMultipleTimes('-', 30) << '+' << endl;
	cout << "|" << printCharMultipleTimes(' ', 30) << '|' << endl;
	cout << "|" << printCharMultipleTimes(' ', 5) << "0 -> build Building" << printCharMultipleTimes(' ', 6) << '|' << endl;
	cout << "|" << printCharMultipleTimes(' ', 5) << "1 -> delete Building" << printCharMultipleTimes(' ', 5) << '|' << endl;
	cout << "|" << printCharMultipleTimes(' ', 5) << "2 -> show map" << printCharMultipleTimes(' ', 12) << '|' << endl;
	cout << "|" << printCharMultipleTimes(' ', 5) << "3 -> end Program" << printCharMultipleTimes(' ', 9) << '|' << endl;
	cout << "|" << printCharMultipleTimes(' ', 30) << '|' << endl;
	cout << "|" << printCharMultipleTimes(' ', 12) << "input?" << printCharMultipleTimes(' ', 12) << '|' << endl;
	cout << "+" << printCharMultipleTimes('-', 30) << '+' << endl;

	int menuUserInput = -1;
	while (menuUserInput < 0 || menuUserInput > 3)
	{
		cin >> menuUserInput;
	}

	switch (menuUserInput)
	{
	case 0:
		return buildBuilding();
		break;
	case 1:
		return deleteBuilding();
		break;
	case 2:
		return showMap();
		break;
	case 3:
		return endProgram();
		break;
	default:
		cout << "HOW DID I GET HERE?" << endl;
		return 1;
	}
}

Building* CapycitySim::getBuilding(char label)
{
	for (Building x : allBuildingTypes)
		if (x.getLabel() == label)
			return new Building(x);
}

CapycitySim::CapycitySim(int length, int width)
{
	this->length = length;
	this->width = width;

	buildSpace = new Building **[length];
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

CapycitySim::~CapycitySim()
{
	//To-DO �berpr�fen stimmt evtl nicht
	for (int i = 0; i < width; ++i)
	{
		delete buildSpace[i];
	}
	delete buildSpace;
}

int CapycitySim::start()
{
	int end = 1;
	while (end != -1)
	{
		end = menu();
	}
	return 1;
}
