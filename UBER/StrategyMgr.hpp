#ifndef STRATEGYMGR_HPP
#define STRATEGYMGR_HPP

#include "PricingStrategy.hpp"
#include "DriverMatchingStrategy.hpp"
#include <mutex>

class StrategyMgr {
private:
	static StrategyMgr* strategyMgrInstance;
	static mutex mtx;

	StrategyMgr();
public:
	static StrategyMgr* getStrategyMgr();

	PricingStrategy* determinePricingStrategy(TripMetaData* metaData);
	DriverMatchingStrategy* determineMatchingStrategy(TripMetaData* metaData);
};
#endif // !STRATEGYMGR_HPP
