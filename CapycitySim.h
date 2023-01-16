#pragma once
#include <iostream>
#include <string>
#include "Building.h"
#include "Blueprint.h"



using namespace std;
class CapycitySim
{
	
private:
	Building allBuildingTypes[3];

	std::vector<Blueprint*> blueprints;
	Blueprint* currentblueprint;

	int length;
	int width;

	string printCharMultipleTimes(char c, int times);
	
	int endProgram();
	int menu();

public:
	CapycitySim(int length, int width);
	~CapycitySim();
	int start();
};

