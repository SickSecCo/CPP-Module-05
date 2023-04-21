#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form {

	private:
		std::string const name;
		const int signgrade;
		const int executegrade;
		bool is_signed;

	public:
		Form(void);
		~Form(void);
		Form(Form const& src);
		Form(std::string const name, const int signgrade, const int executegrade, bool is_signed);
		Form &operator=(Form const& src);

		void beSigned(Bureaucrat const& src);
		std::string getName() const;
		int getsignGrade() const;
		int getexecuteGrade() const;
		bool getIs_signed();

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
};

std::ostream& operator<<(std::ostream &output, const Form &src);

#endif