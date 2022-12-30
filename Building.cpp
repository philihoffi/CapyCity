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

std::vector<Material> Building::getMaterials()
{
	return this->Materials;
}

Building::Building()
{
}

Building::Building(int baseprice, char label, std::vector<Material> Materials, std::string classname)
{
	setLabel(label);
	setPrice(baseprice);
	setClassname(classname);

	for (Material m : Materials)
		addMaterial(m);
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

void Building::addMaterial(Material material)
{
	this->Materials.push_back(material);
}
