#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
	ifstream	input("data.csv");
	if (!input.is_open())
		throw runtime_error("data.csv file is not found or not opened!!");
	else {
		string	line;
		getline(input, line);
		while (getline(input, line))
			datas[getDateToInt(line.substr(0, line.find(",")), ",")] = stod(line.substr(line.find(",") + 1));
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other) {
	this->datas = other.datas;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void) {
}

double	BitcoinExchange::stod(string str) {
	int		len = str.length(), i = 0;

	for (; i < len && str[i] == ' '; i++);

	if (i == len)
		throw runtime_error("invalid format");

	double	num = 0, tmp = 1;
	int		sign = -(str[i] == '-') + (str[i] != '-');

	if (str[i] == '-' || str[i] == '+') {
		if (len == 1)
		{
			if (str[i + 1] == '.')
			{
				if (i + 2 == len || str[i + 2] < '0' || str[i + 2] > '9')
					throw runtime_error("invalid format");
			} else if (str[i + 1] < '0' || str[i + 1] > '9')
				throw runtime_error("invalid format");
		}
		i++;
	} else if (str[i] == '.' && (i + 1 == len || str[i + 1] < '0' || str[i + 1] > '9'))
		throw runtime_error("invalid format");

	for (; i < len; i++) {
		if (str[i] == '.' || str[i] == ' ')
			break ;
		if (str[i] < '0' || str[i] > '9')
			throw runtime_error("invalid format");
		num = 10 * num + str[i] - 48;
	}

	if (i < len && str[i] == '.')
		for (i++; i < len; i++) {
			if (str[i] == ' ')
				break;
			if (str[i] < '0' || str[i] > '9')
				throw runtime_error("invalid format");
			tmp *= 10;
			num += (str[i] - 48) / tmp;
		}

	for (i++; i < len; i++)
		if (str[i] != ' ')
			throw runtime_error("invalid format");

	return sign * num;
}

double		BitcoinExchange::getDateToInt(string date, string ctrl) {
	double	num, year, month, day;
	if (date.find("-") == string::npos || date.substr(0, date.find("-")).find(".") != string::npos)
		throw runtime_error("invalid format");
	try {
		year = stod(date.substr(0, date.find("-"))) - 1;
		if (year < 0)
			throw runtime_error("invalid format");
	} catch (exception &e) {
		throw runtime_error(e.what());
	}
	num = year * 365.25 - doubleMod(year, 4) / 4.0;
	date = date.substr(date.find("-") + 1);
	if (date.find("-") == string::npos || date.substr(0, date.find("-")).find(".") != string::npos)
		throw runtime_error("invalid format");
	try {
		month = stod(date.substr(0, date.find("-")));
	} catch (exception &e) {
		throw runtime_error(e.what());
	}
	if (month < 1 || month > 12)
		throw runtime_error("invalid format");
	date = date.substr(date.find("-") + 1);
	if (date.substr(0, date.find(ctrl)).find(".") != string::npos)
		throw runtime_error("invalid format");
	try {
		day = stod(date.substr(0, date.find(ctrl)));
	} catch (exception &e) {
		throw runtime_error(e.what());
	}
	bool	is_valid = true;
	switch(static_cast<int>(month) - 1) {
		case 11:
			num += 30;
			controlAndAddDay(num, day, is_valid, 31);
		case 10:
			num += 31;
			controlAndAddDay(num, day, is_valid, 30);
		case 9:
			num += 30;
			controlAndAddDay(num, day, is_valid, 31);
		case 8:
			num += 31;
			controlAndAddDay(num, day, is_valid, 30);
		case 7:
			num += 31;
			controlAndAddDay(num, day, is_valid, 31);
		case 6:
			num += 30;
			controlAndAddDay(num, day, is_valid, 31);
		case 5:
			num += 31;
			controlAndAddDay(num, day, is_valid, 30);
		case 4:
			num += 30;
			controlAndAddDay(num, day, is_valid, 31);
		case 3:
			num += 31;
			controlAndAddDay(num, day, is_valid, 30);
		case 2:
			num += 28 + (doubleMod(year + 1, 4) == 0);
			controlAndAddDay(num, day, is_valid, 31);
		case 1:
			num += 31;
			controlAndAddDay(num, day, is_valid, 28 + (doubleMod(year + 1, 4) == 0));
		default:
			controlAndAddDay(num, day, is_valid, 31);
	}
	return num;
}
void	BitcoinExchange::controlAndAddDay(double &num, double day, bool &is_valid, int upperLimit) {
	if (is_valid) {
		if (day >= 1 && day <= upperLimit)
			num += day;
		else
			throw runtime_error("invalid format");
		is_valid = false;
	}
}

void	BitcoinExchange::exec(char *str) {
	ifstream	input(str);
	if (!input.is_open()) {
		cout << "Error: could not open file." << endl;
		return ;
	}
	string	line;
	double	num, num2;
	getline(input, line);
	while (getline(input, line)) {
		if (line.find("|") == string::npos) {
			cout << "Error: bad input => " << line << endl;
			continue ;
		}
		try {
			num = getDateToInt(line, "|");
			num2 = stod(line.substr(line.find("|") + 1));
		} catch (exception &e) {
			cout << "Error: bad input => " << line << endl;
			continue ;
		}
		if (num2 < 0) {
			cout << "Error: not a positive number." << endl;
			continue ;
		}
		else if (num2 > 2147483647) {
			cout << "Error: too large a number." << endl;
			continue ;
		}
		if (datas[num])
			cout << line.substr(0, line.find("|")) << "=> " << num2 << " = " << num2 * datas[num] << endl;
		else {
			datas.erase(datas.find(num));
			map<double, double>::iterator it = datas.begin();
			for (; it != datas.end() && num > it->first; it++);
			if (it == datas.begin()) {
				cout << line.substr(0, line.find("|")) << "=> " << num2 << " = " << 0 << endl;
				continue ;
			}
			--it;
			cout << line.substr(0, line.find("|")) << "=> " << num2 << " = " << num2 * it->second << endl;
		}
	}
}

int		BitcoinExchange::doubleMod(double num, int mod) {
	if (num <= 2147483647)
		return (int)num % mod;
	int	tmp = 2147483647;
	while (tmp % mod != 0)
		tmp--;
	while (num > 2147483647)
		num -= tmp;
	return (int)num % mod;
}
