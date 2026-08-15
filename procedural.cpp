#include <iostream>
using namespace std;

const float PI = 3.14;

void circle()
{
    int radius;
    float area;

    cout << "Enter radius: ";
    cin >> radius;

    area = PI * radius * radius;

    cout << "Area of Circle = " << area << endl;
}

void triangle()
{
    int base, height;
    float area;

    cout << "Enter base: ";
    cin >> base;

    cout << "Enter height: ";
    cin >> height;

    area = (base * height) / 2.0;

    cout << "Area of Triangle = " << area << endl;
}

void rectangle()
{
    int length, width;
    float area;

    cout << "Enter length: ";
    cin >> length;

    cout << "Enter width: ";
    cin >> width;

    area = length * width;

    cout << "Area of Rectangle = " << area << endl;
}

int main()
{
    int choice;

    while (true)
    {
        cout << "\n===== AREA CALCULATOR =====\n";
        cout << "1. Circle\n";
        cout << "2. Triangle\n";
        cout << "3. Rectangle\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            circle();
            break;

        case 2:
            triangle();
            break;

        case 3:
            rectangle();
            break;

        case 4:
            cout << "Thank You!\n";
            return 0;

        default:
            cout << "Invalid Choice!\n";
        }
    }
}