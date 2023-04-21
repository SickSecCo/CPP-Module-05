#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): Form("Robotomy", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src): Form(src) {
	*this = src;
	std::cout << "RobotomyRequestForm Copy Costructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const& src) {
	std::cout << "RobotomyRequestForm Overload assignment called" << std::endl;
    if (this == &src)
		return (*this);
	return (*this);
}

void RobotomyRequestForm::action(Bureaucrat const& target) const {
	if (target.getGrade() <= this->getexecuteGrade())
	{
		std::cout << target.getName() << " executed " << this->getName() << std::endl;
        std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	}
	else
		throw RobotomyRequestForm::FormRefused();
}