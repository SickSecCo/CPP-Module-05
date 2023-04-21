#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {

	private:
		std::string const name;
		std::string const target;
		const int signgrade;
		const int executegrade;
		bool is_signed;

	public:
		~Form(void);
		Form(std::string const name, std::string const target, const int signgrade, const int executegrade);
		Form(Form const& src);
		Form &operator=(Form const& src);

		void beSigned(Bureaucrat const& src);
		std::string getName() const;
		std::string getTarget() const;
		int getsignGrade() const;
		int getexecuteGrade() const;
		bool getIs_signed();
		void execute(Bureaucrat const &executor) const;
		virtual void action(Bureaucrat const &executor) const = 0;

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw() {
				return ("Grade too high, can't sign the Bureaucrat");
			}
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw() {
				return ("Grade too low, can't sign the Bureaucrat");
			}
	};

	class FormNotSigned : public std::exception {
		public:
			const char* what() const throw() {
				return("Form not signed, call the signForm() function and retry");
			}
	};

};

std::ostream& operator<<(std::ostream &output, const Form &src); 

#endif