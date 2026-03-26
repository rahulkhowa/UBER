#include<iostream>
#include<string>
#include "Rider.hpp"
#include "Enums.hpp"
using namespace std;

Rider::Rider(string pName, RATING pRating) : name(pName), rating(pRating) {};

string Rider::getRiderName() const{
	return name;
}

RATING Rider::getRiderRating() const {
	return rating;
}