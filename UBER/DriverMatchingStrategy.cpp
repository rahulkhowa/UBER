#include "Driver.hpp"
#include "DriverMatchingStrategy.hpp"
#include<iostream>
#include<vector>
using namespace std;

Driver* LeastTimeBasedStrategy::matchDriver(TripMetaData* pTripMetaData, vector<Driver*>driver) {
	Driver* bestDriver = nullptr;
	double minDist = 1e18;

	for (auto d : driver) {
		if (!d->isavail()) continue;
		double dist = d->getDriverLocation().distanceTo(*(pTripMetaData->getSrcLoc()));
		if (dist < minDist) {
			minDist = dist;
			bestDriver = d;
		}
	}

	return bestDriver;
}