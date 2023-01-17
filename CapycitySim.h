#pragma once
#include <iostream>
#include <string>
#include "Building.h"
#include "Blueprint.h"



using namespace std;
class CapycitySim
{
	
private:
	std::vector<Blueprint*> blueprints;
	Blueprint* currentblueprint;

	int length;
	int width;

	string printCharMultipleTimes(char c, int times);
	
	int showAllMaps();
	int newBlueprint();
	int endProgram();
	int menu();

public:
	CapycitySim(int length, int width);
	~CapycitySim();
	int start();
};

