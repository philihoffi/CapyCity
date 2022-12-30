#include "Windmill.h"

Windmill::Windmill()
{
	std::vector<Material> Materials;
	Materials.push_back(Wood());
	Materials.push_back(Wood());
	Materials.push_back(Metal());
	Materials.push_back(Metal());
	Materials.push_back(Plastic());

Windmill: Building(100, 'R', Materials);
}
