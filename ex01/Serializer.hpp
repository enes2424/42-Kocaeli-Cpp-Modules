#ifndef SERIALIZER
#define SERIALIZER
#include <iostream>
#include <stdint.h>

struct Data {
	std::string	s;
	char		c;
	int			i;
	float		f;
	double		d;
};

class Serializer {
	private:
		Serializer(void);
		Serializer(const Serializer &copy);
		Serializer& operator=(const Serializer &other);
	public:
		~Serializer(void);
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
