#ifndef TRIPMGR_HPP
#define TRIPMGR_HPP

#include <iostream>
#include <unordered_map>
#include <mutex>
#include "Trip.hpp"
#include "TripMetaData.hpp"
#include "RiderMgr.hpp"
#include "DriverMgr.hpp"
#include "StrategyMgr.hpp"
using namespace std;

class TripMgr {
private:
	static TripMgr* tripMgrInstance;
	static mutex mtx;

	RiderMgr* riderMgr;
	DriverMgr* driverMgr;

	unordered_map<int, TripMetaData*>tripMetaDataInfo;
	unordered_map<int, Trip*>tripInfo;

	TripMgr();
public:
	static TripMgr* getTripMgr();

	Trip* CreateTrip(Rider* pRider,Location* pSrcLoc, Location* pDstLoc);
	unordered_map<int, Trip*>getTripMap();
};
#endif // !TRIPMGR_HPP
