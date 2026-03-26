#ifndef LOCATION_HPP
#define LOCATION_HPP

class Location {
private:
	double x, y;

public:
	Location(double px = 0, double py = 0);

	double getX() const;
	double getY() const;

	double distanceTo(const Location& other) const;
	void display() const;
};
#endif // !LOCATION_HPP
