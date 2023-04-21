#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
	public:
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(ShrubberyCreationForm const& src);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const& src);
		void action(Bureaucrat const &executor) const;

	class FormRefused : public std::exception {
		public:
			const char* what() const throw() {
				return ("the shrubbery creation failed due to low execute grade");
			}
	};
};

#endif