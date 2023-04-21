#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat john("Ciccio", 149);
    	std::cout << john;
		john.decrementGrade();
		std::cout << john;
		john.incrementGrade();
		std::cout << john;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}