#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Form one("Porto d'armi", 140, 75, 0);
		Bureaucrat john("john", 130);
		std::cout << one;
		john.signForm(one);
		one.beSigned(john);
		john.signForm(one);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}