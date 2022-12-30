#pragma once
#include <vector>
#include "Material.h"

class Building
{
private:
	int baseprice;
	char label;
	std::vector<Material> Materials;

public:
	int getPrice();
	int getLabel();
	std::vector<Material> getMaterials();

	Building(int baseprice,char label, std::vector<Material> Materials);
	~Building();

protected:
	void setPrice(int price);
	void setLabel(char label);
	void addMaterial(Material material);
};

