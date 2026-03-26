#include <iostream>
#include "RiderMgr.hpp"
#include "DriverMgr.hpp"
#include "TripMgr.hpp"
using namespace std;

int main()
{
	RiderMgr* riderMgr = RiderMgr::getRiderMgr();
	DriverMgr* driverMgr = DriverMgr::getDriverMgr();
	TripMgr* tripMgr = TripMgr::getTripMgr();

    Rider* rider1 = new Rider("Rahul", RATING::FIVE);
    riderMgr->addRider("Rahul", rider1);

    Driver* driver1 = new Driver("Aman", RATING::FOUR, Location(1, 1));
    Driver* driver2 = new Driver("Rohit", RATING::FIVE, Location(10, 10));
    Driver* driver3 = new Driver("Kunal", RATING::THREE, Location(3, 2));

    driverMgr->addDriver("Aman", driver1);
    driverMgr->addDriver("Rohit", driver2);
    driverMgr->addDriver("Kunal", driver3);

    Location* src = new Location(2, 2);
    Location* dst = new Location(8, 9);

    Trip* trip = tripMgr->CreateTrip(rider1, src, dst);

    if (trip != nullptr) {
        trip->displayTripsDetails();
    }

    return 0;
}
