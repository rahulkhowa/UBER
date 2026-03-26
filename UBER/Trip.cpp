#include "Trip.hpp"
#include <iostream>
using namespace std;

Trip::Trip(int pTripId,Rider* pRider, Driver* pDriver, Location* pSrcLoc, Location* pDstLoc, double pPrice) :tripId(pTripId),rider(pRider), driver(pDriver), srcLoc(pSrcLoc), dstLoc(pDstLoc), price(pPrice) {};

int Trip::getTripId() const {
	return tripId;
}

void Trip::assignDriver(Driver* pDriver) {
	driver = pDriver;
	status = TRIP_STATUS::DRIVER_ASSIGNED;
}

void Trip::startTrip() {
	status = TRIP_STATUS::IN_PROGRESS;
}

void Trip::completeTrip() {
	status = TRIP_STATUS::COMPLETED;
}

void Trip::cancelTrip() {
	status = TRIP_STATUS::CANCELLED;
}

void Trip::displayTripsDetails() const {
	cout << "\nTrip ID: " << tripId << endl;
	cout << "Rider: " << rider->getRiderName() << endl;
	cout << "Driver: " << driver->getDriverName() << endl;
	cout << "Source: ";
	srcLoc->display();
	cout << "\nDestination: ";
	dstLoc->display();
	cout << "\nPrice: " << price << endl;
	cout << "Status: ";
	switch (status) {
	    case TRIP_STATUS::REQUESTED: cout << "REQUESTED"; break;
		case TRIP_STATUS::DRIVER_ASSIGNED: cout << "DRIVER_ASSIGNED"; break;
		case TRIP_STATUS::IN_PROGRESS: cout << "IN_PROGRESS"; break;
		case TRIP_STATUS::COMPLETED: cout << "COMPLETED"; break;
		case TRIP_STATUS::CANCELLED: cout << "CANCELLED"; break;
	}
	cout << "\n";
}