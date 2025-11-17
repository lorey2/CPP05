/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:39:58 by lorey             #+#    #+#             */
/*   Updated: 2025/11/17 11:40:02 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void testInternMakeForm(Intern& intern, Bureaucrat& boss, 
						const std::string& formName, const std::string& target) 
{
	AForm* newForm = NULL; 

	std::cout << "\n--- Intern trying to create '" << formName << "' ---" << std::endl;
	try
	{
		newForm = intern.makeForm(formName, target);
		if (newForm)
		{
			std::cout << *newForm << std::endl;
			boss.signForm(*newForm);
			boss.executeForm(*newForm);
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Intern failed to make form: " << e.what() << std::endl;
	}
	if (newForm)
	{
		delete newForm;
		newForm = NULL;
	}
}
int main() {
	srand(time(NULL));

	Intern  someRandomIntern;
	Bureaucrat boss("The Boss", 1);
	std::cout << boss << std::endl;
	testInternMakeForm(someRandomIntern, boss, "robotomy request", "Bender");
	testInternMakeForm(someRandomIntern, boss, "PresidentialPardonForm", "Marvin");
	testInternMakeForm(someRandomIntern, boss, "ShrubberyCreationForm", "garden");
	testInternMakeForm(someRandomIntern, boss, "invalid form name", "nobody");
	std::cout << "\n--- All tests completed ---" << std::endl;
	return 0;
}
