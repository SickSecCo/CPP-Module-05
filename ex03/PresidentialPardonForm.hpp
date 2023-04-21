#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {

	public:
		PresidentialPardonForm(void);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(PresidentialPardonForm const& src);
		PresidentialPardonForm &operator=(PresidentialPardonForm const& src);
		void action(Bureaucrat const &executor) const;
	
	class FormRefused : public std::exception {
		public:
			const char* what() const throw() {
				return ("the pardon's request has been refused due to low execute grade");
			}
	};
};

#endif