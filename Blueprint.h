#pragma once
#include "Building.h"

class Blueprint
{
private:
	

public:
	Building*** buildSpace;
	int length;
	int width;

	std::string printCharMultipleTimes(char c, int times);


	Building*** getBuildSpace();
	Blueprint(int length, int width);
	~Blueprint();

	Building allBuildingTypes[4];

	bool validBuildspace(int buildingWidth, int buildingLength, int posWidth, int posLength);
	bool collidingWithOtherBuilding(int buildingWidth, int buildingLength, int posWidth, int posLength);
	bool validBuilding(char input);
	void changeBuildSpace(int buildingWidth, int buildingLength, int posWidth, int posLength, Building* buildType);
	int buildBuilding();
	int deleteBuilding();
	int showMap();
	std::string getBuildSpaceAsString();

	double getIndicator();

	Building* getBuilding(char label);

	bool operator()(Blueprint* other);
};

