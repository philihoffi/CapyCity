#pragma once
#include "Building.h"
class Blueprint
{
private:
	Building*** buildSpace;
	int length;
	int width;

public:
	Building*** getBuildSpace();
	Blueprint(int length, int width);
	~Blueprint();
};

