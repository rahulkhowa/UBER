#ifndef DRIVERMGR_HPP
#define DRIVERMGR_HPP
#include <unordered_map>
#include <string>
#include <vector>
#include <mutex>
#include "Driver.hpp"
using namespace std;

class DriverMgr {
private:
	static DriverMgr* driverMgrInstance;
	static mutex mtx;
	unordered_map<string, Driver*>driverMap;
	DriverMgr();
public:
	static DriverMgr* getDriverMgr();
	void addDriver(string pDriverName, Driver* pDriver);
	Driver* getDriver(string pDriverName);
	vector<Driver*>getAllDrivers();
};
#endif // !DRIVERMGR_HPP