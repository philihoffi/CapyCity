#pragma once
#include <vector>
#include "Material.h"
#include <string>
#include <sstream>
#include <map>


class Building
{
private:
	int power;
	int baseprice;
	char label;
	std::string classname;
	//std::vector<Material> Materials;
	std::map<Material*, int> Materials;

public:
	int getPrice();
	int getTotalPrice();
	int getLabel();
	int getPower();
	std::string getClassname();

	std::map<Material*, int> getMaterials();

	Building();
	Building(int baseprice,char label, std::map<Material*,int> Materials, std::string classname, int power);
	~Building();

	Building(Building& other);

	std::string toString();

protected:
	void setPrice(int price);
	void setLabel(char label);
	void setPower(int power);
	void setClassname(std::string classname);
};


class Windmill :public Building
{
public:
	Windmill();
	~Windmill();
};

class Solar :public Building
{
public:
	Solar();
	~Solar();
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

