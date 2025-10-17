#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;
public:
	Fixed(); // 생성자
	Fixed(const Fixed &other); // 복사 생성자
	Fixed& operator=(const Fixed &other); // 복사 대입연산자
	~Fixed();// 소멸자

	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif
