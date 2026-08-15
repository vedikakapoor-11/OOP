#include <iostream>
using namespace std;

class Circle;
class Rectangle;

// Friend class
class ShapeHelper
{
public:
    void showCircleRadius(Circle c);
};

// Circle class
class Circle
{
private:
    double radius;

public:
    // Constructor
    Circle(double r)
    {
        radius = r;
    }

    // Calculate area
    double area()
    {
        return 3.14 * radius * radius;
    }

    // Calculate perimeter
    double perimeter()
    {
        return 2 * 3.14 * radius;
    }

    // Friend class
    friend class ShapeHelper;

    // Friend function
    friend void compare(Circle c, Rectangle r);
};


// Rectangle class
class Rectangle
{
private:
    double length;
    double width;

public:
    // Constructor
    Rectangle(double l, double w)
    {
        length = l;
        width = w;
    }

    // Calculate area
    double area()
    {
        return length * width;
    }

    // Calculate perimeter
    double perimeter()
    {
        return 2 * (length + width);
    }

    // Friend function
    friend void compare(Circle c, Rectangle r);
};


// Friend class function
void ShapeHelper::showCircleRadius(Circle c)
{
    cout << "Radius of Circle: " << c.radius << endl;
}


// Friend function
void compare(Circle c, Rectangle r)
{
    cout << "\n--- Comparing Areas ---" << endl;

    if (c.area() > r.area())
        cout << "Circle has larger area." << endl;

    else if (r.area() > c.area())
        cout << "Rectangle has larger area." << endl;

    else
        cout << "Both have equal area." << endl;
}


int main()
{
    // Creating Circle object
    Circle c1(5);

    // Creating Rectangle object
    Rectangle r1(10, 6);

    cout << "===== CIRCLE =====" << endl;
    cout << "Area: " << c1.area() << endl;
    cout << "Perimeter: " << c1.perimeter() << endl;

    cout << "\n===== RECTANGLE =====" << endl;
    cout << "Area: " << r1.area() << endl;
    cout << "Perimeter: " << r1.perimeter() << endl;

    // Friend class
    ShapeHelper helper;

    cout << "\n===== FRIEND CLASS =====" << endl;
    helper.showCircleRadius(c1);

    // Friend function
    compare(c1, r1);

    return 0;
}