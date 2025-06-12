/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:19:45 by lorey             #+#    #+#             */
/*   Updated: 2025/06/12 15:40:04 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm{
	protected:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradToSign;
		const int			_gradToExec;
		std::string			_target;
	public:
		AForm();
		AForm(std::string name, bool isSigned, int gradToSign, int gradToExec);
		AForm(const AForm &form);
		~AForm();
		AForm& operator=(const AForm &form);
		std::string		getName() const;
		bool			getIsSigned() const;
		int				getGradToSign() const;
		int				getGradToExec() const;
		void			beSigned(Bureaucrat &bureaucrat);
		void			execute(Bureaucrat const & executor) const;
		virtual void	performAction() const = 0;

		class GradeTooHighException: public std::exception{
			public:
				virtual char const	*what(void) const throw();
		};

		class GradeTooLowException: public std::exception{
			public:
				virtual char const	*what(void) const throw();
		};

		class IsAlreadySignedException: public std::exception{
			public:
				virtual char const	*what(void) const throw();
		};

		class IsNotSignedException: public std::exception{
			public:
				virtual char const	*what(void) const throw();
		};
};
		std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
