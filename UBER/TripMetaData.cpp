#include<iostream>
#include "Enums.hpp"
#include "Location.hpp"
#include "TripMetaData.hpp"
using namespace std;

TripMetaData::TripMetaData(RATING pRiderRating, Location* pSrcLoc, Location* pDstLoc) :riderRating(pRiderRating), srcLoc(pSrcLoc), dstLoc(pDstLoc) {};

RATING TripMetaData::getRiderRating() const {
	return riderRating;
}
RATING TripMetaData::getDriverRating() const {
	return driverRating;
}
Location* TripMetaData::getSrcLoc() const {
	return srcLoc;
}
Location* TripMetaData::getDstLoc() const {
	return dstLoc;
}
void TripMetaData::setDriverRating(RATING pDriverRating) {
	driverRating = pDriverRating;
}