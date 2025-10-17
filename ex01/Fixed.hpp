#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int                 _fixedPointValue;
    static const int    _fractionalBits = 8;
public:
	Fixed();
    Fixed(const Fixed &other);
    Fixed& operator=(const Fixed &other);
    ~Fixed();

	//생성자
	Fixed(const int intValue);
	Fixed(const float floatValue);
	float toFloat(void) const;
	int   toInt(void) const;

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif
