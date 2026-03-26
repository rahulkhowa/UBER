#ifndef DRIVERMATCHINGSTRATEGY_HPP
#define DRIVERMATCHINGSTRATEGY_HPP

#include<vector>
#include "Driver.hpp"
#include "TripMetaData.hpp"

class DriverMatchingStrategy {
public:
	virtual Driver* matchDriver(TripMetaData* pTripMetaData, vector<Driver*>driver) = 0;
	virtual ~DriverMatchingStrategy() {};
};

class LeastTimeBasedStrategy :public DriverMatchingStrategy {
public:
	Driver* matchDriver(TripMetaData* pTripMetaData, vector<Driver*>driver) override;
};

#endif // !DRIVERMATCHINGSTRATEGY_HPP
