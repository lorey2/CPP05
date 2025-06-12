/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:25:59 by lorey             #+#    #+#             */
/*   Updated: 2025/06/12 15:04:50 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("Default name"),  _isSigned(false), _gradToSign(1), _gradToExec(1)
{
}

AForm::AForm(std::string name, bool isSigned, int gradToSign, int gradToexec): _name(name),  _isSigned(isSigned), _gradToSign(gradToSign), _gradToExec(gradToexec)
{
	if (this->_gradToExec < 1 || this->_gradToSign < 1)
		throw (AForm::GradeTooHighException());
	if (this->_gradToExec > 150 || this->_gradToSign > 150)
		throw (AForm::GradeTooLowException());
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &form): _name(form._name), _isSigned(form._isSigned), _gradToSign(form._gradToSign), _gradToExec(form._gradToExec)
{
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (_isSigned == false)
		throw IsNotSignedException();
	if (this->_gradToSign < executor.getGrade())
		throw GradeTooLowException();

	performAction();
}

AForm& AForm::operator=(const AForm &form)
{
	this->_isSigned = form._isSigned;
	//we cannot copy the name and gradTo because it is const. Btw overload = operator is dumb here
	return (*this);
}

int	AForm::getGradToSign() const
{
	return (this->_gradToSign);
}

int	AForm::getGradToExec() const
{
	return (this->_gradToExec);
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getIsSigned() const
{
	return (this->_isSigned);
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{

	if(this->_isSigned)
		throw(IsAlreadySignedException());
	else if (bureaucrat.getGrade() > this->getGradToSign())
		throw(GradeTooLowException());
	else
	{
		this->_isSigned = true;
		std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
	}
}

char const* AForm::IsAlreadySignedException::what(void) const throw()
{
	return ("the form is alreay signed");
}

char const* AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

char const* AForm::GradeTooLowException::what(void) const throw()
{
	return ("grade too low");
}

char const* AForm::IsNotSignedException::what(void) const throw()
{
	return ("form needs to be signed to be executed");
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os	<< form.getName() << " is a form... " 
		<< form.getGradToExec() << " is the minimum grade to execute it "
		<< form.getGradToSign() << " is the minimum grade to sign it. "
		<< "Is it signed? : " << form.getIsSigned();
    return os;
}
