#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form {
	public:
		~RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(RobotomyRequestForm const& src);
		RobotomyRequestForm &operator=(RobotomyRequestForm const& src);
		void action(Bureaucrat const &executor) const;

	class FormRefused : public std::exception {
		public:
			const char* what() const throw() {
				return ("The robotomy failed due to low execute grade");
			}
	};
};

#endif