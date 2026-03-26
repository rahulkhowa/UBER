#ifndef TRIPMETADATA_HPP
#define TRIPMETADATA_HPP
#include "Enums.hpp"
#include "Location.hpp"

class TripMetaData {
private:
    RATING riderRating;
    RATING driverRating;
    Location* srcLoc;
    Location* dstLoc;
public:
    TripMetaData(RATING pRiderRating, Location* pSrcloc, Location* pDstloc);

    RATING getRiderRating() const;
    RATING getDriverRating() const;
    void setDriverRating(RATING pDriverRating);

    Location* getSrcLoc() const;
    Location* getDstLoc() const;
};
#endif // !TRIPMETADATA_HPP
