#pragma once
#include <string>
using namespace std;
class CapycitySim
{
	enum buildingType
	{
		nix = nullptr,
		haus = 'h'
	};
private:
	buildingType** buildSpace;
	int length;
	int width;

	string printCharMultipleTimes(char c, int times);
	bool validBuildspace(int buildingWidth, int buildingLength, int posWidth, int posLength);
	bool collidingWithOtherBuilding(int buildingWidth, int buildingLength, int posWidth, int posLength);
	bool validMaterial(char input);
	void changeBuildSpace(int buildingWidth, int buildingLength, int posWidth, int posLength, buildingType buildType);
	int buildBuilding();
	int deleteBuilding();
	int showMap();
	int endProgram();
	int menu();

public:
	CapycitySim(int length, int width);
	~CapycitySim();
	int start();
};

