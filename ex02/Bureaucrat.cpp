#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default"), grade(150) {
    if (this->grade < 1) {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (this->grade > 150) {
        throw Bureaucrat::GradeTooLowException();
    }
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(grade) {
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
    
    try 
    {
        src.beSigned(*this);
        std::cout << this->getName() << " signed " << src.getName() << std::endl;
    }
    catch(const std::exception &err)
    {
        std::cerr << this->getName() << " couldn’t sign " << src.getName() << " because the grade is lower than sign's grade" << std::endl;
    }
}

void Bureaucrat::executeForm(Form const& form) {
    try
    {
        form.execute(*this);
    }
    catch(const std::exception &err)
    {
        std::cerr << this->getName() << " cannot execute " << form.getName() << " because " << err.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream &output, const Bureaucrat &src) {
    output << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
    return (output);
}