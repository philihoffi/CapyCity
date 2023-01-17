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



int CapycitySim::showAllMaps()
{
	std::ostringstream result;
	for (Blueprint* x : blueprints)
		result<< "Indicator:"<< x->getIndicator()<<std::endl << x->getBuildSpaceAsString() << std::endl;

	std::cout << result.str() << std::endl;
	return 1;
}

int CapycitySim::newBlueprint()
{
	for (Blueprint* x : blueprints){
		cout << " . " << endl;
		if (!(*currentblueprint)(x)) {
			blueprints.push_back(currentblueprint);
		}
	}

	if (blueprints.empty())
		blueprints.push_back(currentblueprint);

	currentblueprint = new Blueprint(length, width);
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
	cout << "|" << printCharMultipleTimes(' ', 5) << "3 -> new Blueprint" << printCharMultipleTimes(' ', 7) << '|' << endl;
	cout << "|" << printCharMultipleTimes(' ', 5) << "4 -> show all maps" << printCharMultipleTimes(' ', 7) << '|' << endl;
	cout << "|" << printCharMultipleTimes(' ', 5) << "5 -> end Program" << printCharMultipleTimes(' ', 9) << '|' << endl;
	cout << "|" << printCharMultipleTimes(' ', 30) << '|' << endl;
	cout << "|" << printCharMultipleTimes(' ', 12) << "input?" << printCharMultipleTimes(' ', 12) << '|' << endl;
	cout << "+" << printCharMultipleTimes('-', 30) << '+' << endl;

	int menuUserInput = -1;
	while (menuUserInput < 0 || menuUserInput > 5)
	{
		cin >> menuUserInput;
	}

	switch (menuUserInput)
	{
	case 0:
		return currentblueprint->buildBuilding();
		break;
	case 1:
		return currentblueprint->deleteBuilding();
		break;
	case 2:
		return currentblueprint->showMap();
		break;
	case 3:
		return newBlueprint();
		break;
	case 4:
		return showAllMaps();
		break;
	case 5:
		return endProgram();
		break;
	default:
		cout << "HOW DID I GET HERE?" << endl;
		return 1;
	}
}


CapycitySim::CapycitySim(int length, int width)
{
	this->length = length;
	this->width = width;

	//this->blueprints.push_back();
	currentblueprint = new Blueprint(length, width);

}

CapycitySim::~CapycitySim()
{

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

