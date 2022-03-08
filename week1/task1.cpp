// task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
using namespace std;

const int NAME_SIZE = 128;
const int DESCRIPTION_SIZE = 512;

enum Brand {
    VW,
    Audi,
    BMW,
    Mercedes,
    Seat
};

enum Engine {
    V8,
    V10,
    V12
};

enum Fuel {
    Gasoline,
    Diesel,
    LPG
};


struct Car {
    int km;
    double avgFuelBurn;
    char name[NAME_SIZE], description[DESCRIPTION_SIZE];
    Brand brand;
    Engine engine;
    Fuel fuel;

    void enterCar() {
        cout << "Enter car:";
        cin.ignore();
        cout << "Enter name:";
        cin.getline(name, NAME_SIZE);
        cout << "Enter description";
        cin.getline(description, DESCRIPTION_SIZE);
        cout << "Enter km:";
        cin >> km; cout << endl;
        cout << "Enter average fuel burn";
        cin >> avgFuelBurn; cout << endl;
    }

    // конструктор с параметри
    Car(int _km, double _avgFuelBurn, const char* _name = "Volvo", const char* _description = "The best car") {
        km = _km;
        avgFuelBurn = _avgFuelBurn;
    }

    void getFuel() {
        switch (fuel) {
        case Gasoline: {
            cout << "Na benzin sme" << endl;
            break;
        }
        case Diesel: {
            cout << "Na dizel sme" << endl;
            break;
        }
        case LPG: {
            cout << "Na gaz sme" << endl;
            break;
        }
        }
    }
};

int main()
{
    Car* myCar = new Car(120, 7.8);

    Car myCar1(150, 7.8);
    Car myCar2(99, 7.8);
    Car myCar3(200, 7.8);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
