#include "Building.h"

int Building::getPrice()
{
	return this->baseprice;
}

int Building::getLabel()
{
	return this->label;
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

Building::Building(int baseprice, char label, std::map<Material*,int> Materials, std::string classname)
{
	setLabel(label);
	setPrice(baseprice);
	setClassname(classname);

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
	this->Materials = other.Materials;
}

std::string Building::toString()
{
	int totalPriceMaterials = 0;
	for (auto& m : Materials)
		totalPriceMaterials += m.first->getPrice();

	std::ostringstream result;
	result << label << " : " << classname << "\tprice = " << baseprice << "\tTotal Materrial Price = " << totalPriceMaterials << "\tmaterials = [";

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

void Building::setClassname(std::string classname)
{
	this->classname = classname;
}

Windmill::Windmill() : Building(10, 'W', std::map<Material*, int>{{new Wood(), 10}, { new Plastic(), 5}, { new Metal(), 5 }}, "Windmill")
{

}

Residential::Residential() : Building(100, 'R', std::map<Material*, int>{ {new Wood(), 1}, { new Plastic(), 11 }, { new Metal(), 8 }}, "Residential")
{

}

EmptySpace::EmptySpace() : Building(0, ' ', { }, "EmptySpace")
{

}
