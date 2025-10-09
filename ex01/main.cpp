#include "RPN.hpp"

int	main(int argc, char **argv) {
	if (argc != 2)
		cout << "Argument error!!" << endl;
	else {
		try {
			Rpn::exec(argv[1]);
		} catch (exception &e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}
