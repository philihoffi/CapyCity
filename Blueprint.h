#pragma once
#include "Building.h"

class Blueprint
{
private:
	Building*** buildSpace;
	int length;
	int width;

public:
	Building*** getBuildSpace();
	Blueprint(int length, int width);
	~Blueprint();

	Building allBuildingTypes[3];

	bool validBuildspace(int buildingWidth, int buildingLength, int posWidth, int posLength);
	bool collidingWithOtherBuilding(int buildingWidth, int buildingLength, int posWidth, int posLength);
	bool validBuilding(char input);
	void changeBuildSpace(int buildingWidth, int buildingLength, int posWidth, int posLength, Building* buildType);
	int buildBuilding();
	int deleteBuilding();

	Building* getBuilding(char label);
};

