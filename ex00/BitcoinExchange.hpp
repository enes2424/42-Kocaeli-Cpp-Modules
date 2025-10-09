#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <iostream>
#include <fstream>
#include <map>

using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::string;
using std::map;
using std::ifstream;
using std::runtime_error;
using std::exception;

class BitcoinExchange {
	private:
		map<double, double> datas;
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange	&operator=(const BitcoinExchange &other);
		~BitcoinExchange(void);
		double	stod(string str);
		double	getDateToInt(string date, string ctrl);
		void	controlAndAddDay(double &num, double day, bool &is_valid, int upperLimit);
		void	exec(char *str);
		int		doubleMod(double num, int mod);
};

#endif
