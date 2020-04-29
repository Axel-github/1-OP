#include "checker.h"
#include <iostream>
using namespace std;

int Checker::getValue()
{
    int c;

    while (true)
    {
        cin >> c;
        if (cin.fail() || (c < 0)) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Недопустимое значение. Введите снова:";

        }
        else
            return c;
    }
}


int Checker::getValue(string msg)
{
    cout << endl << "Введите " + msg + ":" << endl;
    return getValue();
}

string Checker::getStrValue(string msg)
{
    cout << endl << "Введите " + msg + ":" << endl;
    string text;
    cin >> text;
    return text;
}

float Checker::getFLValue()
{
    float c;

    while (true)
    {
        cin >> c;
        if (cin.fail() || (c < 0)) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Недопустимое значение. Введите снова:";

        }
        else
            return c;
    }
}
float Checker::getFLValue(string msg)
{
    cout << endl << "Введите " + msg + ":" << endl;
    return getFLValue();
}