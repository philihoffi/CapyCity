#pragma once
#include <string>
#include <sstream>

class Material
{
private:
	
public:
	int price;
	std::string className;

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

