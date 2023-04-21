#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): Form("Pardon", target, 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src): Form(src) {
	*this = src;
	std::cout << "PresidentialPardonForm Copy Costructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const& src) {
	std::cout << "PresidentialPardonForm Overload assignment called" << std::endl;
    if (this == &src)
		return (*this);
	return (*this);
}

void PresidentialPardonForm::action(Bureaucrat const& target) const {
    if (target.getGrade() <= this->getexecuteGrade())
	{
		std::cout << target.getName() << " executed " << this->getName() << std::endl;
        std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
    else
        throw PresidentialPardonForm::FormRefused();
}