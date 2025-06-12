/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:29:53 by lorey             #+#    #+#             */
/*   Updated: 2025/06/12 14:27:02 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default namme"),  _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name),  _grade(grade)
{
	if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat): _name(bureaucrat._name), _grade(bureaucrat._grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	this->_grade = bureaucrat._grade;
	//we cannot copy the name because it is const. Btw overload = operator is dumb here
	return (*this);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

void	Bureaucrat::incrementGrade()
{
	this->_grade--;
	if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
}


void	Bureaucrat::decrementGrade()
{
	this->_grade++;
	if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

void	Bureaucrat::signForm(AForm &form)
{
	form.beSigned(*this);
}

char const* Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

char const* Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << " bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
