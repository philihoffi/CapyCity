#include "Blueprint.h"
#include <iostream>
using namespace std;

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

bool Blueprint::collidingWithOtherBuilding(int buildingWidth, int buildingLength, int posWidth, int posLength)
{
	for (int i = posWidth; i < width && buildingWidth > 0; i++, buildingWidth--)
	{
		int buildingLengthSave = buildingLength;
		for (int j = posLength; j < length && buildingLength > 0; j++, buildingLength--)
			if (getBuildSpace()[i][j]->getLabel() != ' ')
			{
				cout << "colliding with other Building" << endl;
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
		cout << "exit = -1" << endl;
		cout << "Bitte breite(Y) des Gebäudes eingeben -> ";
		cin >> buildingWidth;
		cout << "Bitte länge(X) des Gebäudes eingeben -> ";
		cin >> buildingLength;
		cout << "posY -> ";
		cin >> posWidth;
		cout << "posX -> ";
		cin >> posLength;

		if (buildingWidth == -1 || buildingLength == -1 || posWidth == -1 || posLength == -1)
			return 1;

	} while (!validBuildspace(buildingWidth, buildingLength, posWidth, posLength) || !collidingWithOtherBuilding(buildingWidth, buildingLength, posWidth, posLength));

	char userInput;
	cout << "Gebäudeart :" << endl;
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

int Blueprint::deleteBuilding()
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
		cout << "Bitte länge(X) des Abriss eingeben -> ";
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

Building* Blueprint::getBuilding(char label)
{
	for (Building x : allBuildingTypes)
		if (x.getLabel() == label)
			return new Building(x);
}