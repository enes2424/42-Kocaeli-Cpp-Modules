#include <iostream>

class Harl
{
	private:
		void (Harl::*functions[4])(void);
		std::string	arr[4];
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	public:
		Harl(void);
		~Harl(void);
		void complain( std::string level );
};
