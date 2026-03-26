#include "StrategyMgr.hpp"
#include <iostream>
using namespace std;

StrategyMgr* StrategyMgr::strategyMgrInstance = nullptr;
mutex StrategyMgr::mtx;

StrategyMgr::StrategyMgr() {}

StrategyMgr* StrategyMgr::getStrategyMgr() {
	if (strategyMgrInstance == nullptr) {
		lock_guard<mutex>lock(mtx);
		if (strategyMgrInstance == nullptr) {
			strategyMgrInstance = new StrategyMgr();
		}
	}
	return strategyMgrInstance;
}

PricingStrategy* StrategyMgr::determinePricingStrategy(TripMetaData* metaData) {
	if ((int)metaData->getRiderRating() >= 4) {
		return new RatingBasedPricingStrategy();
	}
	return new DefaultPricingStrategy();
}

DriverMatchingStrategy* StrategyMgr::determineMatchingStrategy(TripMetaData* metaData) {
	return new LeastTimeBasedStrategy();
}