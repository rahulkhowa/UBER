#include <iostream>
#include "TripMgr.hpp"
using namespace std;

TripMgr* TripMgr::tripMgrInstance = nullptr;
mutex TripMgr::mtx;

TripMgr::TripMgr() {
	riderMgr = RiderMgr::getRiderMgr();
	driverMgr = DriverMgr::getDriverMgr();
}

TripMgr* TripMgr::getTripMgr() {
	if (tripMgrInstance == nullptr) {
		lock_guard<mutex>lock(mtx);
		if (tripMgrInstance == nullptr) {
			tripMgrInstance = new TripMgr();
		}
	}
	return tripMgrInstance;
}

//sabse important logic
Trip* TripMgr::CreateTrip(Rider* pRider,Location* pSrcLoc, Location* pDstLoc) {
	static int tripCounter = 1;
	int tripId = tripCounter++;

	TripMetaData* metaData = new TripMetaData(pRider->getRiderRating(), pSrcLoc, pDstLoc);
	StrategyMgr* strategyMgr = StrategyMgr::getStrategyMgr();
	PricingStrategy* pricingStrategy = strategyMgr->determinePricingStrategy(metaData);
	DriverMatchingStrategy* matchingStrategy = strategyMgr->determineMatchingStrategy(metaData);
	Driver* matchedDriver = matchingStrategy->matchDriver(metaData, driverMgr->getAllDrivers());

	if (matchedDriver == nullptr) {
		cout << "No driver available for trip" << tripId << endl;
		return nullptr;
	}

	matchedDriver->updateavalil(false);
	metaData->setDriverRating(matchedDriver->getDriverRating());

	double price = pricingStrategy->calculatePrice(metaData);

	Trip* trip = new Trip(tripId,pRider, matchedDriver, pSrcLoc, pDstLoc, price);
	tripMetaDataInfo[tripId] = metaData;
	tripInfo[tripId] = trip;

	return trip;
}

unordered_map<int, Trip*>TripMgr::getTripMap() {
	return tripInfo;
}

