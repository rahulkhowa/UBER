#ifndef  RIDERMGR_HPP
#define RIDERMGR_HPP

#include "Rider.hpp"
#include<string>
#include<mutex>
#include<unordered_map>
using namespace std;

class RiderMgr {
private:
	static RiderMgr* riderMgrInstance;
	static mutex mtx;
	unordered_map<string, Rider*>riderMap;
	RiderMgr();
public:
	static RiderMgr* getRiderMgr();
	void addRider(string pRiderName, Rider* pRider);
	Rider* getRider(string pRiderName);
};
#endif // ! RIDERMGR_HPP
