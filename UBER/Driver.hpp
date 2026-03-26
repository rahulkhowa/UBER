#ifndef DRIVER_HPP
#define DRIVER_HPP

#include<string>
#include "Enums.hpp"
#include "Location.hpp"
using namespace std;

class Driver {
private:
	string name;
	RATING rating;
	Location location;
	bool avail;
public:
	Driver(string pName, RATING pRating, Location pLocation);
	void updateavalil(bool pAvail);

	bool isavail() const;

	string getDriverName() const;
	RATING getDriverRating() const;
	Location getDriverLocation() const;
};
#endif // !DRIVER_HPP
