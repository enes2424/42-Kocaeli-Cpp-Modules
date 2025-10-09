#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int	integer;
		static const int INTEGER;
	public:
		Fixed(void);
		Fixed(const int integer);
		Fixed(const float f);
		Fixed(const Fixed &copy);
		Fixed& operator=(const Fixed &other);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		Fixed operator+(const Fixed &other);
		Fixed operator-(const Fixed &other);
		Fixed operator*(const Fixed &other);
		Fixed operator/(const Fixed &other);
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);
		static const Fixed &min(const Fixed &first, const Fixed &second);
		static Fixed &min(Fixed &first, Fixed &second);
		static const Fixed &max(const Fixed &first, const Fixed &second);
		static Fixed &max(Fixed &first, Fixed &second);
};

std::ostream	&operator<<(std::ostream &o, const Fixed &fixed);

#endif
