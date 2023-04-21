#include "Form.hpp"

Form::Form(void): name("Licenza caccia"), signgrade(75), executegrade(45), is_signed(0) {
	std::cout << "Form default costructor called" << std::endl;
}

Form::Form(std::string const name, const int signgrade, const int executegrade, bool is_signed): name(name), signgrade(signgrade), executegrade(executegrade), is_signed(is_signed) {
	std::cout << "Form costructor with parameter called" << std::endl;
	if (this->executegrade < 1 || this->signgrade < 1)
		throw Form::GradeTooHighException();
	else if (this->executegrade > 150 || this->signgrade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form(void) {
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(Form const& src): signgrade(75), executegrade(45) {
	std::cout << "Form copy costructor called" << std::endl;
	*this = src;
}

Form &Form::operator=(Form const& src) {
	std::cout << "Form overload assignment called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

void Form::beSigned(Bureaucrat const& src) {
	if (src.getGrade() <= this->getsignGrade())
		this->is_signed = 1;
	else
		throw Form::GradeTooLowException();
}

std::string Form::getName() const {
	return (this->name);
}

int Form::getsignGrade() const {
	return (this->signgrade);
}

int Form::getexecuteGrade() const {
	return (this->executegrade);
}

bool Form::getIs_signed() {
	return (this->is_signed);
}

std::ostream& operator<<(std::ostream &output, const Form &src) {
    output << src.getName() << ", form grade required to sign it: " << src.getsignGrade() << ", form grade required to execute it: " << src.getexecuteGrade() << std::endl;
    return (output);
}