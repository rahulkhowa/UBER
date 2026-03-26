#ifndef TRIP_HPP
#define TRIP_HPP

#include "Rider.hpp"
#include "Driver.hpp"
#include "Location.hpp"
#include "Enums.hpp"

class Trip {
private:
	Rider* rider;
	Driver* driver;
	Location* srcLoc;
	Location* dstLoc;
	TRIP_STATUS status;
	int tripId;
	double price;
public:
	Trip(int pTripId,Rider* pRider, Driver* pDriver, Location* pSrcLoc, Location* pDstLoc, double pPrice);
	int getTripId() const;
	void assignDriver(Driver* pDriver);
	void startTrip();
	void completeTrip();
	void cancelTrip();
	void displayTripsDetails() const;
};
#endif // !TRIP_HPP
