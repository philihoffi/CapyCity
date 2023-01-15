#pragma once
#include <vector>
#include "Material.h"
#include <string>
#include <sstream>
#include <map>


class Building
{
private:
	int baseprice;
	char label;
	std::string classname;
	//std::vector<Material> Materials;
	std::map<Material*, int> Materials;

public:
	int getPrice();
	int getLabel();
	std::string getClassname();

	std::map<Material*, int> getMaterials();

	Building();
	Building(int baseprice,char label, std::map<Material*,int> Materials, std::string classname);
	~Building();

	Building(Building& other);

	std::string toString();

protected:
	void setPrice(int price);
	void setLabel(char label);
	void setClassname(std::string classname);
};


class Windmill :public Building
{
public:
	Windmill();
	~Windmill();
};


class Residential :public Building
{
private:
public:
	Residential();
	~Residential();
};

class EmptySpace :public Building
{
public:
	EmptySpace();
	~EmptySpace();
};

