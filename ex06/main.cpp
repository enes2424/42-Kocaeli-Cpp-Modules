#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Please give me LEVEL (DEBUG, INFO, WARNING OR ERROR)" << std::endl, 0);
	Harl	harl;
	int		i;
	for (i = 0; i < 4; i++)
		if (argv[1] == harl.getStr(i))
			break;
	switch (i)
	{
		case 0:
			std::cout << "[DEBUG]" << std::endl;
			harl.complain("DEBUG");
		case 1:
			std::cout << "[INFO]" << std::endl;
			harl.complain("INFO");
		case 2:
			std::cout << "[WARNING]" << std::endl;
			harl.complain("WARNING");
		case 3:
			std::cout << "[ERROR]" << std::endl;
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}
