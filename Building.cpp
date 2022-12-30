#include "Building.h"

int Building::getPrice()
{
    return this->baseprice;
}

int Building::getLabel()
{
    return this->label;
}

std::vector<Material> Building::getMaterials()
{
    return this->Materials;
}

Building::Building(int baseprice, char label, std::vector<Material> Materials)
{
    setLabel(label);
    setPrice(baseprice);

    for (Material m : Materials)
        addMaterial(m);
}

void Building::setPrice(int price)
{
    this->baseprice = price;
}

void Building::setLabel(char label)
{
    this->label = label;
}

void Building::addMaterial(Material material)
{
    this->Materials.push_back(material);
}
