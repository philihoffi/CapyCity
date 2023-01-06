#pragma once
#include <string>
#include <sstream>

class Material
{
private:
	int price;
	std::string className;
public:
	Material(int price, std::string className);
	int getPrice();
	std::string getClassName();

	std::string toString();
protected:
	void setPrice(int price);
	void setClassname(std::string className);
	
};

class Wood :public Material
{
public:
	Wood();
};

class Plastic :public Material
{
public:
	Plastic();
};

class Metal :public Material
{
public:
	Metal();
};

