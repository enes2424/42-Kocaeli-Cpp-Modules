#include "Fixed.hpp"
#include <cmath>

const int Fixed::INTEGER = 8;

Fixed::Fixed(void)
{
	integer = 0;
}

Fixed::Fixed(const int integer)
{
	this->integer = integer << INTEGER;
}

Fixed::Fixed(const float f)
{
	this->integer = roundf(f * (1 << INTEGER));
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed(void)
{
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

bool Fixed::operator>(const Fixed &other) const
{
	return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const
{
	return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const
{
	return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const
{
	return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const
{
	return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const
{
	return this->getRawBits() != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed &other)
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other)
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other)
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other)
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++(void) // ++a
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator++(int) // a++
{
	Fixed	tmp(*this);
	this->setRawBits(this->getRawBits() + 1);
	return tmp;
}

Fixed &Fixed::operator--(void) // --a
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator--(int) // a--
{
	Fixed	tmp(*this);
	this->setRawBits(this->getRawBits() - 1);
	return tmp;
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.getRawBits() > second.getRawBits())
		return second;
	return first;
}

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	if (first.getRawBits() > second.getRawBits())
		return second;
	return first;
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.getRawBits() < second.getRawBits())
		return second;
	return first;
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	if (first.getRawBits() > second.getRawBits())
		return second;
	return first;
}
