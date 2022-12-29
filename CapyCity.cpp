// CapyCity.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <string>

using namespace std;

enum buildingType
{
	nix = 'x',
	haus = 'h'
};

buildingType** buildSpace;
int length;
int width;

string printCharMultipleTimes(char c, int times)
{
	string s = "";
	for (int i = 0; i < times; ++i)
		s += c;
	return s;
}

bool validBuildspace(int buildingWidth, int buildingLength, int posWidth, int posLength)
{
	if (buildingWidth < 1 || buildingLength < 1 || posWidth < 0 || posLength < 0)
	{
		cout << "value was either too large or too smalll" << endl;
		return false;
	}
	if (buildingWidth + posWidth > width || buildingLength + posLength > length)
	{
		cout << "value was either too large or too small" << endl;
		return false;
	}
	return true;
}

bool collidingWithOtherBuilding(int buildingWidth, int buildingLength, int posWidth, int posLength)
{
	for (int i = posWidth; i < width && buildingWidth > 0; i++, buildingWidth--)
	{
		int buildingLengthSave = buildingLength;
		for (int j = posLength; j < length && buildingLength > 0; j++, buildingLength--)
			if (buildSpace[i][j] != nix)
			{
				cout << "colliding with other Building" << endl;
				return false;
			}
		buildingLength = buildingLengthSave;
	}
	return true;
}

bool validMaterial(char input)
{
	// TO-DO
	return true;
}

void changeBuildSpace(int buildingWidth, int buildingLength, int posWidth, int posLength, buildingType buildType)
{
	for (int i = posWidth; i < width && buildingWidth > 0; i++, buildingWidth--)
	{
		int buildingLengthSave = buildingLength;
		for (int j = posLength; j < length && buildingLength > 0; j++, buildingLength--)
			buildSpace[i][j] = buildType;
		buildingLength = buildingLengthSave;
	}
}

int buildBuilding()
{
	int buildingLength;
	int buildingWidth;
	int posWidth;
	int posLength;
	buildingType buildType;
	do
	{
		cout << "exit = -1" << endl;
		cout << "Bitte breite(Y) des Gebäudes eingeben -> ";
		cin >> buildingWidth;
		cout << "Bitte länge(X) des Gebäudes eingeben -> ";
		cin >> buildingLength;
		cout << "posY -> ";
		cin >> posWidth;
		cout << "posX -> ";
		cin >> posLength;

		if (buildingWidth == -1 || buildingLength == -1 || posWidth == -1 || posLength == -1)
			return 1;

	} while (!validBuildspace(buildingWidth, buildingLength, posWidth, posLength) || !collidingWithOtherBuilding(buildingWidth, buildingLength, posWidth, posLength));

	char userInput;
	do
	{
		cout << "Gebäudeart : haus = 'h' ";
		cin >> userInput;
	} while (!validMaterial(userInput));
	buildType = (buildingType)userInput;
	changeBuildSpace(buildingWidth, buildingLength, posWidth, posLength, buildType);

	return 1;
}
int deleteBuilding()
{
	int deletLength;
	int deletWidth;
	int posWidth;
	int posLength;
	buildingType buildType;

	do
	{
		cout << "exit = -1" << endl;
		cout << "Bitte breite(Y) des Abriss eingeben -> ";
		cin >> deletWidth;
		cout << "Bitte länge(X) des Abriss eingeben -> ";
		cin >> deletLength;
		cout << "posY -> ";
		cin >> posWidth;
		cout << "posX -> ";
		cin >> posLength;

		if (deletWidth == -1 || deletLength == -1 || posWidth == -1 || posLength == -1)
			return 1;
	} while (!validBuildspace(deletWidth, deletLength, posWidth, posLength));

	changeBuildSpace(deletWidth, deletWidth, posWidth, posLength, nix);

	return 1;
}
int showMap()
{
	cout << "+" << printCharMultipleTimes('-', length * 2 + 1) << '+' << endl;
	for (int i = width - 1; i >= 0; i--)
	{
		cout << "| ";
		for (int j = 0; j < length; j++)
		{
			cout << (char)buildSpace[i][j] << ' ';
		}
		cout << '|' << endl;
	}
	cout << "+" << printCharMultipleTimes('-', length * 2 + 1) << '+' << endl;
	cout << "Legende einfügen WIP" << endl;

	return 1;
}
int endProgram()
{
	for (int i = 0; i < width; ++i)
	{
		delete buildSpace[i];
	}
	delete buildSpace;
	return -1;
}

int menu()
{
	cout << "+" << printCharMultipleTimes('-', 30) << '+' << endl;
	cout << "|" << printCharMultipleTimes(' ', 30) << '|' << endl;
	cout << "|" << printCharMultipleTimes(' ', 5) << "0 -> build Building" << printCharMultipleTimes(' ', 6) << '|' << endl;
	cout << "|" << printCharMultipleTimes(' ', 5) << "1 -> delete Building" << printCharMultipleTimes(' ', 5) << '|' << endl;
	cout << "|" << printCharMultipleTimes(' ', 5) << "2 -> show map" << printCharMultipleTimes(' ', 12) << '|' << endl;
	cout << "|" << printCharMultipleTimes(' ', 5) << "3 -> end Program" << printCharMultipleTimes(' ', 9) << '|' << endl;
	cout << "|" << printCharMultipleTimes(' ', 30) << '|' << endl;
	cout << "|" << printCharMultipleTimes(' ', 12) << "input?" << printCharMultipleTimes(' ', 12) << '|' << endl;
	cout << "+" << printCharMultipleTimes('-', 30) << '+' << endl;

	int menuUserInput = -1;
	while (menuUserInput < 0 || menuUserInput > 3)
	{
		cin >> menuUserInput;
	}

	switch (menuUserInput)
	{
	case 0:
		return buildBuilding();
		break;
	case 1:
		return deleteBuilding();
		break;
	case 2:
		return showMap();
		break;
	case 3:
		return endProgram();
		break;
	default:
		cout << "HOW DID I GET HERE?" << endl;
		return 1;
	}
}

int main(int argc, char* argv[])
{
	if (argc < 3) {
		std::cout << "Bitte geben Sie Länge und Breite als Argumente an" << std::endl;
		return 1;
	}

	length = std::stoi(argv[1]);
	width = std::stoi(argv[2]);


	buildSpace = new buildingType * [width];
	for (int i = 0; i < width; ++i)
	{
		buildSpace[i] = new buildingType[length];
		for (int j = 0; j < length; ++j)
		{
			buildSpace[i][j] = nix;
		}
	}

	int end = 1;
	while (end != -1)
	{
		end = menu();
	}
	return 1;
}
