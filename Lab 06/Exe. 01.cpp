#include <iostream>
using namespace std;

class Shape {
protected:
    int numberOfSides;
    double area;
public:
    Shape(int sides) : numberOfSides(sides), area(0.0) {}
    
    // Accessors and Mutators
    void setSides(int s) { numberOfSides = s; }
    int getSides() const { return numberOfSides; }
    double getArea() const { return area; }
};

class Rectangle : public Shape {
protected:
    double length, width;
public:
    Rectangle(double l, double w) : Shape(4), length(l), width(w) {}
    
    void generateArea() {
        area = length * width;
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}

    void checkSides() {
        if (length == width) 
            cout << "Square check: Sides are equal." << endl;
        else 
            cout << "Square check: Sides are not equal." << endl;
    }

    void generateArea() {
        area = length * length;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : Shape(0), radius(r) {}
    
    void generateArea() {
        area = 3.14159 * radius * radius;
    }
};

class Triangle : public Shape {
private:
    double height, base;
public:
    Triangle(double h, double b) : Shape(3), height(h), base(b) {}
    
    void generateArea() {
        area = (height * base) / 2.0;
    }
};

int main() {
    Square s(10);
    s.checkSides();
    s.generateArea();
    cout << "Square Area: " << s.getArea() << endl;

    Circle c(5);
    c.generateArea();
    cout << "Circle Area: " << c.getArea() << endl;

    Triangle t(10, 5);
    t.generateArea();
    cout << "Triangle Area: " << t.getArea() << endl;

    return 0;
}
