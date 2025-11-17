/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:59:45 by lorey             #+#    #+#             */
/*   Updated: 2025/11/17 11:10:16 by lorey            ###   LAUSANNE.ch       */
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

// --- Helper function to test form creation ---
void testInternMakeForm(Intern& intern, Bureaucrat& boss, 
                        const std::string& formName, const std::string& target) 
{
    AForm* newForm = NULL; // Must initialize to NULL

    std::cout << "\n--- Intern trying to create '" << formName << "' ---" << std::endl;
    try
    {
        // 1. Intern creates the form
        newForm = intern.makeForm(formName, target);

        // 2. We test the form (if creation succeeded)
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

    // 3. CRITICAL: Clean up the memory to prevent leaks
    if (newForm)
    {
        delete newForm;
        newForm = NULL;
    }
}

int main() {
    // Seed random only once
    srand(time(NULL));

    Intern  someRandomIntern;
    Bureaucrat boss("The Boss", 1);
    std::cout << boss << std::endl;

    // --- Test 1: Robotomy Request ---
    testInternMakeForm(someRandomIntern, boss, "robotomy request", "Bender");

    // --- Test 2: Presidential Pardon ---
    // Note: Your intern is looking for "PresidentialPardonForm"
    testInternMakeForm(someRandomIntern, boss, "PresidentialPardonForm", "Marvin");
    
    // --- Test 3: Shrubbery Creation ---
    // Note: Your intern is looking for "ShrubberyCreationForm"
    testInternMakeForm(someRandomIntern, boss, "ShrubberyCreationForm", "garden");

    // --- Test 4: A form that does not exist ---
    testInternMakeForm(someRandomIntern, boss, "invalid form name", "nobody");

    std::cout << "\n--- All tests completed ---" << std::endl;
    return 0;
}
