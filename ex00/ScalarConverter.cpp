#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {*this = copy;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter(void) {}

void	ScalarConverter::convert(std::string str) {
	if (str.length() == 1 && (str[0] < '0' || str[0] > '9')) {
		if (str[0] < 32 || str[0] == 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << str[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
		return ;
	}
	if (str != "inf" && str != "+inf" && str != "-inf")
		str = str.substr(0, str.length() - (str[str.length() - 1] == 'f'));
	if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
		return ;
	}
	double	num = 0;
	double	num2 = 1;
	int		sign = - (str[0] == '-') + (str[0] != '-');
	size_t	i;
	for (i = (str[0] == '+' || str[0] == '-'); i < str.length(); i++) {
		if (str[i] == '.')
			break ;
		if (str[i] < '0' || str[i] > '9')
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return ;
		}
		num = 10 * num + str[i] - 48;
	}
	for (i++; i < str.length(); i++) {
		if (str[i] < '0' || str[i] > '9')
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return ;
		}
		num2 *= 10;
		num += (str[i] - 48) / num2;
	}
	num *= sign;
	if (static_cast<char>(num) < 32 || static_cast<char>(num) == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(num) << std::endl;
	if (static_cast<int>(num) == num && num < 1000000)
		std::cout << "float: " << static_cast<float>(num) << ".0f" << std::endl
				  << "double: " << num << ".0" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(num) << "f" << std::endl
				  << "double: " << num << std::endl;
}
