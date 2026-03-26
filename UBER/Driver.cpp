#include<string>
#include "Driver.hpp"
#include "Location.hpp"
#include "Enums.hpp"
using namespace std;

Driver::Driver(string pName, RATING pRating, Location pLocation) : name(pName),avail(true), rating(pRating), location(pLocation) {};
void Driver::updateavalil(bool pAvail) {
	avail = pAvail;
}
bool Driver::isavail() const {
	return avail;
}
string Driver::getDriverName() const {
	return name;
}
RATING Driver::getDriverRating() const {
	return rating;
}
Location Driver::getDriverLocation() const {
	return location;
}