#include "Fixed.hpp"
#include <cmath>

const int Fixed::INTEGER = 8;

Fixed::Fixed(void)
{
	integer = 0;
	cout << "Default constructor called" << endl;
}

Fixed::Fixed(const int integer)
{
	this->integer = integer << INTEGER;
	cout << "Int constructor called" << endl;
}

Fixed::Fixed(const float f)
{
	this->integer = roundf(f * (1 << INTEGER));
	cout << "Float constructor called" << endl;
}

Fixed::Fixed(const Fixed &copy)
{
	cout << "Copy constructor called" << endl;
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	cout << "Copy assignment operator called" << endl;
	this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed(void)
{
	cout << "Destructor called" << endl;
}

int Fixed::getRawBits(void) const
{
	return integer;
}

void Fixed::setRawBits(int const raw)
{
	integer = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float) integer / (1 << INTEGER));
}

int Fixed::toInt( void ) const
{
	return (integer >> INTEGER);
}

std::ostream	&operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
	return o;
}
