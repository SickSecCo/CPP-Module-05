#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default"), grade(150) {
    std::cout << "Default costructor called" << std::endl;
    if (this->grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (this->grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(grade) {
    std::cout << "Bureaucrat costructor called" << std::endl;
    if (this->grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (this->grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& src) {
    this->grade = src.grade;
    (std::string)this->name = src.name;
    return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) {
    *this = src;
}

std::string Bureaucrat::getName() const{
    return (this->name);
}

int Bureaucrat::getGrade() const{
    return (this->grade);
}

void Bureaucrat::incrementGrade() {
    this->grade = this->grade - 1;
    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
    this->grade = this->grade + 1;
    if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(Form& src) {
    if (src.getIs_signed() == 1)
        std::cout << this->getName() << " signed " << src.getName() << std::endl;
    else if (this->grade <= src.getsignGrade() && src.getIs_signed() == 0)
        std::cout << "You have to call beSigned() function to check if the Bureaucrat can sign or not the form!!!" << std::endl;
    else
        std::cout << this->getName() << " couldn't sign " << src.getName() << " because the Bureaucrat's grade (" << this->getGrade() << ") is lower than sign grade (" << src.getsignGrade() << ")" << std::endl;

}