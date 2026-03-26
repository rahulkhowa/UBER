#ifndef RIDER_HPP
#define RIDER_HPP

//#include <iostream>
#include <string>
#include "Enums.hpp"
using namespace std;

class Rider {
private:
	string name;
	RATING rating;
public:
	Rider(string pName, RATING pRating);

	string getRiderName() const;
	RATING getRiderRating() const;
};
#endif // !RIDER_HPP
