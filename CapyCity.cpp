// CapyCity.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "iostream"

using namespace std;

enum buildingType
{
    nix = 'x',
    haus = 'h'
};

buildingType **buildSpace;
int length;
int width;

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
    return 1;
}
int deleteBuilding()
{
    // TO-DO
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

int main()
{
    do
    {
        cout << "Bitte länge des Baubereichs eingeben -> ";
        cin >> length;
        cout << "Bitte breite des Baubereichs eingeben -> ";
        cin >> width;
    } while (length < 1 || width < 1);

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
