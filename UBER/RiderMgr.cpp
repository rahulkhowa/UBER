#include "RiderMgr.hpp"
#include <iostream>
using namespace std;

RiderMgr* RiderMgr::riderMgrInstance = nullptr;
mutex RiderMgr::mtx;

RiderMgr::RiderMgr(){}

RiderMgr* RiderMgr::getRiderMgr() {
	if (riderMgrInstance == nullptr) {
		lock_guard<mutex>lock(mtx);
		if (riderMgrInstance == nullptr) {
			riderMgrInstance = new RiderMgr();
		}
	}
	return riderMgrInstance;
}

void RiderMgr::addRider(string pRiderName, Rider* pRider) {
	riderMap[pRiderName] = pRider;
}

Rider* RiderMgr::getRider(string pRiderName) {
	if (riderMap.count(pRiderName)) return riderMap[pRiderName];
	return nullptr;
}