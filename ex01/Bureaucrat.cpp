#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(/* args */) : _name("bureaucrat")
{
	_grade = 42;
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		exit(1);
	}
	_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
	if (this != &bureaucrat)
	{
		_grade = bureaucrat._grade;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat) 
{
	*this = bureaucrat;
}

void	Bureaucrat::getName(void) const
{
	std::cout << this->_name << std::endl;
}

void	Bureaucrat::getGrade(void) const
{
	std::cout << this->_grade << std::endl;
}

void	Bureaucrat::incrementGrade(void)
{
	try
	{
		if (this->_grade == 1)
			throw GradeTooHighException();
		else
			this->_grade--;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		exit(1);
	}
}

const char *	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

void	Bureaucrat::decrementGrade(void)
{
	try
	{
		if (this->_grade == 150)
			throw GradeTooLowException();
		else
			this->_grade++;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		exit(1);
	}
}

const char * Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}
