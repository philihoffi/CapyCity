#include "Material.h"

void Material::setPrice(int price)
{
	this->price = price;
}

Material::Material(int price)
{
	setPrice(price);
}

int Material::getPrice()
{
	return this->price;
}
