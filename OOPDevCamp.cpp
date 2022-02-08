#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

class Shape {
public:
	virtual double calculateSurface() = 0;
	virtual double calculatePerimeter() = 0;
};

class Shape3D : public Shape {
	virtual double calculateVolume() = 0;
};

class Triangle : public Shape {
public:
	Triangle(double x, double y, double z) {
		side1 = x;
		side2 = y;
		side3 = z;
		s = (x + y + z) / 2;
	}
	bool isValidTriangle();
	virtual double calculatePerimeter();
	virtual double calculateSurface();
	string typeOfTriangle();
private:
	double side1, side2, side3, s;
};

double Triangle::calculatePerimeter() {
	return side1 + side2 + side3;
}

double Triangle::calculateSurface() {
	return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

bool Triangle::isValidTriangle() {
	if (side1 + side2 > side3 && side2 + side3 > side1 && side1 + side3 > side2)
		return true;
	else 
		return false;
}

string Triangle::typeOfTriangle() {
	if (side1 == side2 && side2 == side3) {
		return "Equilateral triangle";
	}
	else if (side1 == side2 || side2 == side3 || side1 == side3) {
		return "Isosceles triangle";
	}
	else {
		return "Scalene Triangle";
	}
}

class Rectangle : public Shape {
public:
	Rectangle(double x, double y) {
		side1 = x;
		side2 = y;
	}
	virtual double calculatePerimeter();
	virtual double calculateSurface();
private:
	double side1, side2;
};

double Rectangle::calculatePerimeter() {
	return 2 * side1 + 2 * side2;
}

double Rectangle::calculateSurface() {
	return side1 * side2;
}

class Square : public Shape {
public:
	Square (double x) {
		side = x;
	}
	virtual double calculatePerimeter();
	virtual double calculateSurface();
private:
	double side;
};

double Square::calculatePerimeter() {
	return side * 4;
}

double Square::calculateSurface() {
	return side * side;
}

class Circle : public Shape {
public:
	Circle(double x) {
		radius = x;
	}
	virtual double calculatePerimeter();
	virtual double calculateSurface();
private:
	double radius;
};

double Circle::calculatePerimeter() {
	return radius * 2 * M_PI;
}

double Circle::calculateSurface() {
	return M_PI * pow(radius, 2);
}

class Cube : public Shape3D {
public:
	Cube(double x) {
		side = x;
	}
	virtual double calculatePerimeter();
	virtual double calculateSurface();
	virtual double calculateVolume();
private:
	double side;
};

double Cube::calculatePerimeter() {
	return 12 * side;
}

double Cube::calculateSurface() {
	return 6 * pow(side, 2);
}

double Cube::calculateVolume() {
	return pow(side, 3);
}
int main()
{
	Triangle firstTriangle(2, 4, 3);
	Triangle secondTriangle(4, 5, 6);
	Rectangle Rec(3, 5);
	Square sq(4);
	Circle cr(7.1);
	Cube kocka(5);
	cout << "First triangle perimeter: " << firstTriangle.calculatePerimeter() << endl;
	cout << "Second triangle perimeter: " << secondTriangle.calculatePerimeter() << endl;
	cout << "First triangle area: " << firstTriangle.calculateSurface() << endl;
	cout << "Second triangle area: " << secondTriangle.calculateSurface() << endl;
	cout << firstTriangle.typeOfTriangle() << endl;
	cout << "Rectangle perimeter: " << Rec.calculatePerimeter() << endl;
	cout << "Rectangle area: " << Rec.calculateSurface() << endl;
	cout << "Square perimeter: " << sq.calculatePerimeter() << endl;
	cout << "Square area: " << sq.calculateSurface() << endl;
	cout << "Circle perimeter: " << cr.calculatePerimeter() << endl;
	cout << "Circle area: " << cr.calculateSurface() << endl;
	cout << "Cube perimeter: " << kocka.calculatePerimeter() << endl;
	cout << "Cube area: " << kocka.calculateSurface() << endl;
	cout << "Cube volume: " << kocka.calculateVolume() << endl;
}