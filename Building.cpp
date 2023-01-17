#include "Building.h"
#include <iostream>

int Building::getPrice()
{
	return this->baseprice;
}

int Building::getTotalPrice()
{
	int toalprice = baseprice;
	for (auto& m : getMaterials())
		toalprice += m.first->getPrice()*m.second;

	return toalprice;
}

int Building::getLabel()
{
	return this->label;
}

int Building::getPower()
{
	return this->power;
}

std::string Building::getClassname()
{
	return this->classname;
}

std::map<Material*, int> Building::getMaterials()
{
	return this->Materials;
}

Building::Building()
{
}

Building::Building(int baseprice, char label, std::map<Material*,int> Materials, std::string classname, int power)
{
	setLabel(label);
	setPrice(baseprice);
	setClassname(classname);
	setPower(power);

	this->Materials = Materials;
}

Building::~Building()
{
}

Building::Building(Building& other)
{
	this->classname = other.classname;
	this->baseprice = other.baseprice;
	this->label = other.label;
	this->power = other.power;
	this->Materials = other.Materials;
}

std::string Building::toString()
{
	int totalPriceMaterials = 0;
	for (auto& m : Materials)
		totalPriceMaterials += m.first->getPrice();

	std::ostringstream result;
	result << label << " : " << classname <<"\t\npower: " << power << "\nprice = " << baseprice << "\tTotal Materrial Price = " << totalPriceMaterials << "\t\nmaterials = [";

	for (auto& m : Materials)
		result <<" " << m.first->toString() << " : " << m.second << " ";
		
	result << "]";
	return result.str();
}

void Building::setPrice(int price)
{
	this->baseprice = price;
}

void Building::setLabel(char label)
{
	this->label = label;
}

void Building::setPower(int power)
{
	//std::cout << this->power << " " << power << std::endl;
	this->power = power;
	//std::cout << this->power << " " << power << std::endl;
}

void Building::setClassname(std::string classname)
{
	this->classname = classname;
}

Windmill::Windmill() : Building(10, 'W', std::map<Material*, int>{{new Wood(), 10}, { new Plastic(), 5}, { new Metal(), 5 }}, "Windmill",100)
{
	this->setPower(100);
}

Residential::Residential() : Building(100, 'R', std::map<Material*, int>{ {new Wood(), 1}, { new Plastic(), 11 }, { new Metal(), 8 }}, "Residential",0)
{

}

EmptySpace::EmptySpace() : Building(0, ' ', { }, "EmptySpace",0)
{

}
