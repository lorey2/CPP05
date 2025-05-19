/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:25:59 by lorey             #+#    #+#             */
/*   Updated: 2025/05/19 22:44:32 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("Default name"),  _isSigned(false), _gradToSign(1), _gradToExec(1)
{
}

Form::Form(std::string name, bool isSigned, int gradToSign, int gradToexec): _name(name),  _isSigned(isSigned), _gradToSign(gradToSign), _gradToExec(gradToexec)
{
	if (this->_gradToExec < 1 || this->_gradToSign < 1)
		throw (Form::GradeTooHighException());
	if (this->_gradToExec > 150 || this->_gradToSign > 150)
		throw (Form::GradeTooLowException());
}

Form::~Form()
{
}

Form::Form(const Form &form): _name(form._name), _isSigned(form._isSigned), _gradToSign(form._gradToSign), _gradToExec(form._gradToExec)
{
}

Form& Form::operator=(const Form &form)
{
	this->_isSigned = form._isSigned;
	//we cannot copy the name and gradTo because it is const. Btw overload = operator is dumb here
	return (*this);
}

int	Form::getGradToSign() const
{
	return (this->_gradToSign);
}

int	Form::getGradToExec() const
{
	return (this->_gradToExec);
}

std::string Form::getName() const
{
	return (this->_name);
}

bool	Form::getIsSigned() const
{
	return (this->_isSigned);
}

void	Form::beSigned(Bureaucrat &bureaucrat) const
{
	
}

char const* Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

char const* Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << form.getName() << "" << form.getGradToExec();
    return os;
}
