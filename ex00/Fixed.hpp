#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#define cout std::cout
#define endl std::endl

class Fixed 
{
	private:
		int	integer;
		static const int INTEGER = 8;
	public:
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed& operator=(const Fixed &other);
		~Fixed(void);
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
