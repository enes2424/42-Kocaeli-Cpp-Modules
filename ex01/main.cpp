#include "Serializer.hpp"

int	main(void) {
	Data data = {"42Kocaeli", 'c', 42, 42.42f, 42.42};
	std::cout << &data << std::endl <<
	data.s << std::endl << data.c << std::endl <<
	data.i << std::endl << data.f << std::endl <<
	data.d << std::endl;
	uintptr_t conversion = Serializer::serialize(&data);
	std::cout << "---------------------------" << std::endl;
	std::cout << "Conversion = " << conversion << std::endl;
	std::cout << "---------------------------" << std::endl;
	Data *data2 = Serializer::deserialize(conversion);
	std::cout << data2 << std::endl <<
	data2->s << std::endl << data2->c << std::endl <<
	data2->i << std::endl << data2->f << std::endl <<
	data2->d << std::endl;
	return 0;
}
