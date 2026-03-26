#include<iostream>
#include<cmath>
#include "Location.hpp"
using namespace std;

//encapsulation used for accessing x and y
Location::Location(double px,double py):x(px),y(py) {}

double Location::getX() const {
	return x;
}

double Location::getY() const {
	return y;
}

double Location::distanceTo(const Location& other) const{
	return abs(x - other.getX()) + abs(y - other.getY());
}

void Location::display() const {
	cout << "(" << x << "," << y << ")";
}