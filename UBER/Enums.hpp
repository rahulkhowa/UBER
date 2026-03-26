#ifndef ENUMS_HPP
#define ENUMS_HPP

enum class RATING {
	ONE=1,
	TWO,
	THREE,
	FOUR,
	FIVE
};

enum class TRIP_STATUS {
   REQUESTED,
   DRIVER_ASSIGNED,
   IN_PROGRESS,
   COMPLETED,
   CANCELLED
};
#endif // !ENUMS_HPP
