// CapyCity.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <string>
#include "CapycitySim.h"

using namespace std;


int main(int argc, char* argv[])
{
	

	if (argc < 3) {
		std::cout << "Bitte geben Sie Länge und Breite als Argumente an" << std::endl;
		return 1;
	}


	int length = std::stoi(argv[1]);
	int width = std::stoi(argv[2]);

	CapycitySim c1(length, width);

	c1.start();
}
