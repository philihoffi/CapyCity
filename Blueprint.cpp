#include "Blueprint.h"

Building*** Blueprint::getBuildSpace()
{
	return this->buildSpace;
}

Blueprint::Blueprint(int length, int width)
{
	this->length = length;
	this->width = width;

	buildSpace = new Building * *[length];
	for (int i = 0; i < length; i++)
	{
		buildSpace[i] = new Building * [width];
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			buildSpace[i][j] = new EmptySpace();
		}
	}
}

Blueprint::~Blueprint()
{
	//To-DO überprüfen stimmt evtl nicht
	for (int i = 0; i < width; ++i)
	{
		delete buildSpace[i];
	}
	delete buildSpace;
}
