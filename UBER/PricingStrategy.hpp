#ifndef PRICINGSTRATEGY_HPP
#define PRICINGSTRATEGY_HPP

#include "TripMetaData.hpp"
using namespace std;

//abstraction will be used so this is interface because of the virtual
//and polymorphism will occur
class PricingStrategy {
public:
	virtual double calculatePrice(TripMetaData* pTripMetaData) = 0;
	virtual ~PricingStrategy() {}
};

class DefaultPricingStrategy :public PricingStrategy {
public:
	double calculatePrice(TripMetaData* pTripMetaData) override;
};

class RatingBasedPricingStrategy :public PricingStrategy {
public:
	double calculatePrice(TripMetaData* pTripMetaData) override;
};
#endif // !PRICINGSTRATEGY_HPP
