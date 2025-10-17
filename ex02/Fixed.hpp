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

	//산술 연산
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	// 비교 연산
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	// 증감 연산
	Fixed& operator++(void); // 전위 증가
	Fixed  operator++(int); // 후위 증가
	Fixed& operator--(void); // 전위 감소
	Fixed  operator--(int); // 후위 감소

	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a,const Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a,const Fixed &b);
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif
