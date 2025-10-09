#ifndef SCALAR_CONVERTER
#define SCALAR_CONVERTER
#include <iostream>

class ScalarConverter {
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter& operator=(const ScalarConverter &other);
	public:
		~ScalarConverter(void);
		static void	convert(std::string str);
};

#endif
