#pragma once
#include <vector>
#include "Material.h"
#include "Wood.h"
#include "Plactic.h"
#include "Metal.h"
#include <string>


class Building
{
private:
	int baseprice;
	char label;
	std::string classname;
	std::vector<Material> Materials;

public:
	int getPrice();
	int getLabel();
	std::string getClassname();

	std::vector<Material> getMaterials();

	Building();
	Building(int baseprice,char label, std::vector<Material> Materials, std::string classname);
	~Building();

	Building(Building& other);

protected:
	void setPrice(int price);
	void setLabel(char label);
	void setClassname(std::string classname);
	void addMaterial(Material material);
};

