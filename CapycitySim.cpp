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

int CapycitySim::showMap()
{
	cout << "+" << printCharMultipleTimes('-', length * 2 + 1) << '+' << endl;
	for (int i = width - 1; i >= 0; i--)
	{
		cout << "| ";
		for (int j = 0; j < length; j++)
		{
			cout << (char)currentblueprint->getBuildSpace()[i][j]->getLabel() << ' ';
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
	int totalPower = 0;


	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (currentblueprint->getBuildSpace()[i][j]->getLabel() != ' ') {
				Building* tmp = currentblueprint->getBuildSpace()[i][j];
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

	cout << "Total Wood required:\t" << totalWood<<endl;
	cout << "Total Metal required:\t" << totalMetal << endl;
	cout << "Total Plastic required:\t" << totalPlastic << endl;
	cout << printCharMultipleTimes('-', 20) << endl;
	cout << "Total Plastic required:\t" << totalPower << endl;
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
		return currentblueprint->buildBuilding();
		break;
	case 1:
		return currentblueprint->deleteBuilding();
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


CapycitySim::CapycitySim(int length, int width)
{
	this->length = length;
	this->width = width;

	this->blueprints.push_back(new Blueprint(length, width));
	currentblueprint = blueprints.front();

	allBuildingTypes[0] = Building(*new EmptySpace());
	allBuildingTypes[1] = Building(*new Windmill());
	allBuildingTypes[2] = Building(*new Residential());
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

