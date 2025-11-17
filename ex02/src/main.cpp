/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:40:35 by lorey             #+#    #+#             */
/*   Updated: 2025/11/17 11:41:29 by lorey            ###   LAUSANNE.ch       */
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

void	testSuccessfulExecution()
{
	std::cout << "\n--- Testing Successful Execution ---" << std::endl;
	try
	{
		Bureaucrat boss("The Boss", 1);
		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Ford Prefect");

		std::cout << "\n" << boss << std::endl;
		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << pardon << std::endl;

		std::cout << "\n--- Boss signing forms ---" << std::endl;
		boss.signForm(shrub);
		boss.signForm(robot);
		boss.signForm(pardon);

		std::cout << "\n--- Boss executing forms ---" << std::endl;
		// The bureaucrat must execute the form, not the form itself
		boss.executeForm(shrub);
		boss.executeForm(robot);
		boss.executeForm(pardon);

		// Test Robotomy a few more times to see the 50/50 chance
		std::cout << "\n--- Testing Robotomy 50/50 chance (loop x4) ---" << std::endl;
		boss.executeForm(robot);
		boss.executeForm(robot);
		boss.executeForm(robot);
		boss.executeForm(robot);
	}
	catch (const std::exception& e)
	{
		std::cerr << "An unexpected exception was caught: " << e.what() << std::endl;
	}
}

void	testFailureCases()
{
	std::cout << "\n\n--- Testing Failure Cases ---" << std::endl;

	Bureaucrat boss("Big Boss", 1);
	Bureaucrat manager("Mid Manager", 50);
	Bureaucrat intern("Poor Intern", 150);

	PresidentialPardonForm highLevelForm("High-Level Pardon"); // Sign 25, Exec 5
	ShrubberyCreationForm  lowLevelForm("Low-Level Tree");	 // Sign 145, Exec 137

	std::cout << "\n" << boss << std::endl;
	std::cout << manager << std::endl;
	std::cout << intern << std::endl;
	std::cout << highLevelForm << std::endl;
	std::cout << lowLevelForm << std::endl;


	// --- Test 1: Grade too low to sign ---
	std::cout << "\n--- Test 1: Grade too low to sign ---" << std::endl;
	std::cout << "Intern (150) trying to sign Presidential (25)..." << std::endl;
	intern.signForm(highLevelForm); // Fails, caught by signForm
	std::cout << "Manager (50) trying to sign Presidential (25)..." << std::endl;
	manager.signForm(highLevelForm); // Fails, caught by signForm

	// --- Test 2: Grade too low to execute ---
	std::cout << "\n--- Test 2: Grade too low to execute ---" << std::endl;
	std::cout << "Manager (50) trying to execute Presidential (5)..." << std::endl;
	boss.signForm(highLevelForm); // Boss signs it
	manager.executeForm(highLevelForm); // Manager (50) tries to exec (req 5), fails

	// --- Test 3: Executing an unsigned form ---
	std::cout << "\n--- Test 3: Executing an unsigned form ---" << std::endl;
	std::cout << "Intern (150) trying to execute unsigned Low-Level Tree (137)..." << std::endl;
	intern.executeForm(lowLevelForm); // Fails, caught by executeForm

	// --- Test 4: Success mixed with failure ---
	std::cout << "\n--- Test 4: Success mixed with failure ---" << std::endl;
	std::cout << "Intern (150) signing Low-Level Tree (145)..." << std::endl;
	intern.signForm(lowLevelForm); // Success
	std::cout << "Intern (150) executing Low-Level Tree (137)..." << std::endl;
	intern.executeForm(lowLevelForm); // Success
}

void	testExceptions()
{
	std::cout << "\n\n--- Testing Constructor Exceptions ---" << std::endl;

	// --- Test 1: Bureaucrat grade too high ---
	try
	{
		std::cout << "Trying to create Bureaucrat with grade 0..." << std::endl;
		Bureaucrat b("Too Good", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << '\n';
	}

	// --- Test 2: Bureaucrat grade too low ---
	try
	{
		std::cout << "Trying to create Bureaucrat with grade 151..." << std::endl;
		Bureaucrat b("Too Bad", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Caught exception: " << e.what() << '\n';
	}
}

int main() {
	srand(time(NULL));

	testSuccessfulExecution();
	testFailureCases();
	testExceptions();

	std::cout << "\n--- All tests completed ---" << std::endl;
	return 0;
}
