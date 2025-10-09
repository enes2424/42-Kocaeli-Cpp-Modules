#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#define cout std::cout
#define endl std::endl

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
};

std::ostream	&operator<<(std::ostream &o, const Fixed &fixed);

#endif
