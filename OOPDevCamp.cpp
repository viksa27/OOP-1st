#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

class Shape {
public:
	virtual double getSurface() { return 0; }
	virtual double getPerimeter() { return 0; }
};

class Shape3D : public Shape {
public:
	virtual double getVolume() { return 0; }
};

class Triangle : public Shape {
public:
	Triangle(double x, double y, double z) {
		side1 = x;
		side2 = y;
		side3 = z;
		s = (x + y + z) / 2;
	}
	virtual double getPerimeter() {
		return calculatePerimeter();
	}
	virtual double getSurface() {
		return calculateSurface();
	}
	bool getIfValidTriangle() {
		return isValidTriangle();
	}
	string getTypeOfTriangle() {
		return typeOfTriangle();
	}
private:
	bool isValidTriangle();
	virtual double calculatePerimeter();
	virtual double calculateSurface();
	string typeOfTriangle();
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
	virtual double getSurface() {
		return calculateSurface();
	}
	virtual double getPerimeter() {
		return calculatePerimeter();
	}
private:
	virtual double calculatePerimeter();
	virtual double calculateSurface();
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
	Square(double x) {
		side = x;
	}
	virtual double getPerimeter() {
		return calculatePerimeter();
	}
	virtual double getSurface() {
		return calculateSurface();
	}
private:
	virtual double calculatePerimeter();
	virtual double calculateSurface();
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
	virtual double getPerimeter() {
		return calculatePerimeter();
	}
	virtual double getSurface() {
		return calculateSurface();
	}
private:
	virtual double calculatePerimeter();
	virtual double calculateSurface();
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
	virtual double getPerimeter() {
		return calculatePerimeter();
	}
	virtual double getSurface() {
		return calculateSurface();
	}
	virtual double getVolume() {
		return calculateVolume();
	}
private:
	virtual double calculatePerimeter();
	virtual double calculateSurface();
	virtual double calculateVolume();
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

void printMenu() {
	cout << "1 - Triangle" << endl;
	cout << "2 - Rectangle" << endl;
	cout << "3 - Square" << endl;
	cout << "4 - Circle" << endl;
	cout << "5 - Cube" << endl;
}

int getUserChoice() {
	int index; cout << "Enter shape index: "; cin >> index;
	return index;
}

Triangle getTriangle() {
	double side1, side2, side3;
	cout << "Enter first side: "; cin >> side1;
	cout << "Enter second side: "; cin >> side2;
	cout << "Enter third side: "; cin >> side3;
	return Triangle(side1, side2, side3);
}

void printTriangleInfo(Triangle t) {
	if (t.getIfValidTriangle()) {
		cout << "Perimeter: " << t.getPerimeter() << endl;
		cout << "Surface: " << t.getSurface() << endl;
		cout << "Type of triangle: " << t.getTypeOfTriangle() << endl;
	}
	else cout << "Not a valid triangle!" << endl;
}

Rectangle getRectangle() {
	double side1, side2;
	cout << "Enter first side: "; cin >> side1;
	cout << "Enter second side: "; cin >> side2;
	return Rectangle(side1, side2);
}

void printRectangleInfo(Rectangle r) {
	cout << "Perimeter: " << r.getPerimeter() << endl;
	cout << "Surface: " << r.getSurface() << endl;
}

Square getSquare() {
	double side;
	cout << "Enter side: "; cin >> side;
	return Square(side);
}

void printSquareInfo(Square s) {
	cout << "Perimeter: " << s.getPerimeter() << endl;
	cout << "Surface: " << s.getSurface() << endl;
}

Circle getCircle() {
	double radius;
	cout << "Enter radius: "; cin >> radius;
	return Circle(radius);
}

void printCircleInfo(Circle c) {
	cout << "Perimeter: " << c.getPerimeter() << endl;
	cout << "Surfce: " << c.getSurface() << endl;
}

Cube getCube() {
	double side;
	cout << "Enter side: "; cin >> side;
	return Cube(side);
}

void printCubeInfo(Cube c) {
	cout << "Perimeter: " << c.getPerimeter() << endl;
	cout << "Surfce: " << c.getSurface() << endl;
	cout << "Volume: " << c.getVolume() << endl;
}

int main()
{
	printMenu();
	int index = getUserChoice();
	if (index < 1 || index > 5) { cout << "Index out of range"; return 0; }
	switch (index) {
	case 1:	printTriangleInfo(getTriangle()); break;
	case 2: printRectangleInfo(getRectangle()); break;
	case 3: printSquareInfo(getSquare()); break;
	case 4: printCircleInfo(getCircle()); break;
	case 5: printCubeInfo(getCube()); break;
	}
}