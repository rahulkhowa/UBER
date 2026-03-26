#include "DriverMgr.hpp"

DriverMgr* DriverMgr::driverMgrInstance = nullptr;
mutex DriverMgr::mtx;

DriverMgr::DriverMgr() {}

DriverMgr* DriverMgr::getDriverMgr() {
    if (driverMgrInstance == nullptr) {
        lock_guard<mutex> lock(mtx);
        if (driverMgrInstance == nullptr) {
            driverMgrInstance = new DriverMgr();
        }
    }
    return driverMgrInstance;
}

void DriverMgr::addDriver(string pDriverName, Driver* pDriver) {
    driverMap[pDriverName] = pDriver;
}

Driver* DriverMgr::getDriver(string pDriverName) {
    if (driverMap.count(pDriverName)) return driverMap[pDriverName];
    return nullptr;
}

vector<Driver*>DriverMgr::getAllDrivers() {
    vector<Driver*>drivers;
    for (auto& it : driverMap) {
        drivers.push_back(it.second);
    }
    return drivers;
}