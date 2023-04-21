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

std::ostream& operator<<(std::ostream &output, const Bureaucrat &src) {
    output << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
    return (output);
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