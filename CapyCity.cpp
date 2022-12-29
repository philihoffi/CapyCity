// CapyCity.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "iostream"

using namespace std;

enum buildingType
{
    nix,
    ein,
    zwe,
    dre
};

string printCharMultipleTimes(char c, int times)
{
    string s = "";
    for (int i = 0; i < times; ++i)
        s += c;
    return s;
}

int menuUserInput()
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

    int r = -1;
    while (r < 0 || r > 3)
    {
        cin >> r;
    }
    return r;
}

int buildBuilding()
{
    // TO-DO
}
int deleteBuilding()
{
    // TO-DO
}
int showMap()
{
    // TO-DO
}
int endProgram()
{
    // TO-DO
}

void menu()
{
    switch (menuUserInput())
    {
    case 0:
        buildBuilding();
        break;
    case 1:
        deleteBuilding();
        break;
    case 2:
        showMap();
        break;
    case 3:
        endProgram();
        break;
    default:
        cout << "HOW DID I GET HERE?" << endl;
    }
}

int main()
{
    //ohne kommandozeilenargumente (einfacher zu debuggen)
    int length;
    int width;

    cout << "Bitte länge des Baubereichs eingeben";
    cin >> length;
    cout << "Bitte breite des Baubereichs eingeben";
    cin >> width;

    buildingType** buildSpace = new buildingType * [width];
    for (int i = 0; i < width; ++i)
        buildSpace[i] = new buildingType[length];

    menu();
    return 1;
}
