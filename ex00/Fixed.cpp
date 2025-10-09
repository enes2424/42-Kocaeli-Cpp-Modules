#include "Fixed.hpp"

Fixed::Fixed(void)
{
	integer = 0;
	cout << "Default constructor called" << endl;
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
	cout << "getRawBits member function called" << endl;
	return integer;
}

void Fixed::setRawBits(int const raw)
{
	integer = raw;
}
