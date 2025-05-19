/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 22:19:45 by lorey             #+#    #+#             */
/*   Updated: 2025/05/19 22:36:31 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradToSign;
		const int			_gradToExec;
	public:
		Form();
		Form(std::string name, bool isSigned, int gradToSign, int gradToExec);
		Form(const Form &form);
		~Form();
		Form& operator=(const Form &form);
		std::string		getName() const;
		bool			getIsSigned() const;
		int				getGradToSign() const;
		int				getGradToExec() const;
		void			beSigned() const;
		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
};
		std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
