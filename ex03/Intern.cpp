#include "Intern.hpp"

Intern::Intern(void) {}

Intern::~Intern(void) {}

Intern::Intern(Intern const& src)
{
	std::cout << "Intern copy costructor called" << std::endl;
	*this = src;
}

Intern &Intern::operator=(Intern const& src)
{
	std::cout << "Intern Overload assignment called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

Form* Intern::makeForm(std::string const form_name, std::string const target)
{
	std::string forms[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	int k = 5;
	Form *tmp;
	for (int i = 0; i < 3; i++)
	{
		if (!forms[i].compare(form_name))
			k = i;
	}
	switch (k)
	{
		case 0:
			tmp = new RobotomyRequestForm(target);
			break;
		case 1:
			tmp = new ShrubberyCreationForm(target);
			break;
		case 2:
			tmp = new PresidentialPardonForm(target);
			break;
		default:
			throw Intern::WrongName();
	}
	return (tmp);
}