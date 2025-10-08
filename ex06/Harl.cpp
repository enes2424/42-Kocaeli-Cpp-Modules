#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "7XL-çift peynirli-üçlü turşu-özel-ketçaplı burgerime fazladan domuz pastır-ması yemeyi seviyorum. Gerçekten seviyorum!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "Ekstra domuz pastırması eklemenin daha fazla paraya mal olduğuna inanamıy-orum. Burgerime yeterince pastırma koymadınız! Yapsaydınız, daha fazlasını iste-mezdim!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "Bence bedavaya fazladan pastırma yemeyi hak ediyorum.  Ben yıllardırgeliyorum, sen geçen aydan beri burada çalışmaya başladın." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "Bu kabul edilemez! Şimdi müdürle konuşmak istiyorum." << std::endl;
}


Harl::Harl(void)
{
	functions[0] = &Harl::debug;
	functions[1] = &Harl::info;
	functions[2] = &Harl::warning;
	functions[3] = &Harl::error;
	arr[0] = "DEBUG";
	arr[1] = "INFO";
	arr[2] = "WARNING";
	arr[3] = "ERROR";
}

Harl::~Harl(void)
{
}

void	Harl::complain( std::string level )
{
	for (int i = 0; i < 4; i++)
		if (level == arr[i])
			return ((this->*functions[i])());
	std::cout << "Error!!" << std::endl;
}

std::string Harl::getStr(int index)
{
	return arr[index];
}
