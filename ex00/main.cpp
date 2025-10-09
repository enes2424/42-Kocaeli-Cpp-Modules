#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {
	try {
		BitcoinExchange bitcoinExchange;
		if (argc > 2) {
			cout << "Num of argumants is too many!!" << endl;
			return 0;
		}
		bitcoinExchange.exec(argv[1]);
	} catch (exception &e) {
		cout << e.what() << endl;
	}
	return 0;
}
