/*
Create a class called "Rectangle" that has the following private member variables:

length (an integer)
width (an integer)
The class should have the following public member functions:

A constructor that takes in two integers representing the length and width of the rectangle and initializes the corresponding instance variables.
A function called "getLength" that returns the length of the rectangle.
A function called "getWidth" that returns the width of the rectangle.
A function called "setLength" that takes in an integer representing the new length of the rectangle and sets the length instance variable to the new value.
A function called "setWidth" that takes in an integer representing the new width of the rectangle and sets the width instance variable to the new value.
A function called "getArea" that returns the area of the rectangle (which is the length times the width).
In your main function, create an instance of the Rectangle class, set its length and width, and output its area.

*/

#include <string>
#include <iostream>

using namespace std;

class Rectangle
{
private:
    int length;
    int width;
    int area;

public:
    int getLength()
    {
        return length;
    }

    int getWidth()
    {
        return width;
    }

    void setLength()
    {
        cout << "Enter Length: ";
        cin >> length;
    }

    void setWidth()
    {
        cout << "Enter Width: ";
        cin >> width;
    }
    int getArea()
    {
        return length * width;
    }
};

int main()
{
    Rectangle rectangle1;
    rectangle1.setLength();
    rectangle1.setWidth();
    cout << "Area: " << rectangle1.getArea();
    return 0;
}