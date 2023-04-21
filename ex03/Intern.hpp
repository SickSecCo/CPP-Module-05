#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern(void);
		~Intern(void);
		Intern(Intern const& src);
		Intern &operator=(Intern const& src);
		
		Form* makeForm(std::string const name, std::string const target);
		
		class WrongName : public std::exception {
			const char *what() const throw(){
				return ("WrongName exception");
			}
		};
};

#endif