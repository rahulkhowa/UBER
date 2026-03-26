#include "TripMetaData.hpp"
#include "PricingStrategy.hpp"
#include<iostream>
using namespace std;

double DefaultPricingStrategy::calculatePrice(TripMetaData* pTripMetaData) {
	double dist = pTripMetaData->getSrcLoc()->distanceTo(*(pTripMetaData->getDstLoc()));
	return 50 + dist * 10;
}

double RatingBasedPricingStrategy::calculatePrice(TripMetaData* pTripMetaData) {
	double dist = pTripMetaData->getSrcLoc()->distanceTo(*(pTripMetaData->getDstLoc()));
	double mult = 1.0;

	if ((int)pTripMetaData->getRiderRating() >= 4) {
		mult = 0.9;
	}
	return (50 + dist * 10) * mult;
}