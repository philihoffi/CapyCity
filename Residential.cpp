#include "Residential.h"

Residential::Residential()
{
	std::vector<Material> Materials;
	Materials.push_back(Wood());
	Materials.push_back(Wood());
	Materials.push_back(Metal());
	Materials.push_back(Metal());
	Materials.push_back(Plastic());

	Residential: Building(100,'R',Materials);
}

