#pragma once
#include <iostream>
#include <string>
#include "Building.h"



using namespace std;
class CapycitySim
{
	
private:
	Building*** buildSpace;
	int length;
	int width;

	Building allBuildingTypes[3];

	string printCharMultipleTimes(char c, int times);
	bool validBuildspace(int buildingWidth, int buildingLength, int posWidth, int posLength);
	bool collidingWithOtherBuilding(int buildingWidth, int buildingLength, int posWidth, int posLength);
	bool validBuilding(char input);
	void changeBuildSpace(int buildingWidth, int buildingLength, int posWidth, int posLength, Building* buildType);
	int buildBuilding();
	int deleteBuilding();
	int showMap();
	int endProgram();
	int menu();
	Building* getBuilding(char label);

public:
	CapycitySim(int length, int width);
	~CapycitySim();
	int start();
};

