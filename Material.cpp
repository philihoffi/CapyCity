#include "Material.h"


void Material::setPrice(int price)
{
	this->price = price;
}

void Material::setClassname(std::string className)
{
	this->className = className;
}

Material::Material(int price, std::string className)
{
	setPrice(price);
	setClassname(className);
}

int Material::getPrice()
{
	return this->price;
}

std::string Material::getClassName()
{
	return this->className;
}

std::string Material::toString()
{
	std::ostringstream result;
	result << className;
	return result.str();
}

Wood::Wood() :Material(2, "Wood")
{
}

Plastic::Plastic() :Material(1, "Plastic")
{
}

Metal::Metal() :Material(3, "Metal")
{
}

