#include "Fixed.hpp"

Fixed::Fixed(){
	this -> _fixedPointValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other){

	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
	{
		this ->_fixedPointValue = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return this -> _fixedPointValue;
}
//getter의 느낌

void Fixed::setRawBits( int const raw )
{
	this -> _fixedPointValue = raw;
}
//setter의 느낌

Fixed::Fixed(const int intValue){
	std::cout << "Int constructor called" << std::endl;
	this -> _fixedPointValue = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue){
	std::cout << "Float constructor called" << std::endl;
	this -> _fixedPointValue = roundf(floatValue * (1 << _fractionalBits));
}

int Fixed::toInt(void) const{
	return this -> _fixedPointValue >> _fractionalBits;
}

float Fixed::toFloat(void) const{
	return (float)this -> _fixedPointValue / (1 << _fractionalBits);
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
