#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"
class Form;

class Bureaucrat {

    private:
        std::string const name;
        int grade;

    public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat& src);
		Bureaucrat(const Bureaucrat& src);

		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form& src);
		void executeForm(Form const& form);

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw() {
				return ("Grade too high, can't instantiate the object");
			}
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw() {
				return ("Grade too low, can't instantiate the object");
			}
	};
};

std::ostream& operator<<(std::ostream &output, const Bureaucrat &src);

#endif