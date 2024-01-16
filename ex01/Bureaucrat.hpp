#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class  Bureaucrat 
{
private:
	const	std::string _name;
	int					_grade;
public:
	Bureaucrat(/* args */);
	Bureaucrat(const Bureaucrat& bureaucrat);
	Bureaucrat(const std::string name, int grade);
	Bureaucrat	&operator=(const Bureaucrat & bureaucrat);
	void		getName(void) const;
	void		getGrade(void) const;
	void		incrementGrade(void);
	void		decrementGrade(void);
	~Bureaucrat();





	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

#endif // BUREAUCRAT_HPP
