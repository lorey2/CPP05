/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:59:45 by lorey             #+#    #+#             */
/*   Updated: 2025/05/20 13:47:23 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void    testBureaucratConstruction() {
    std::cout << "\n--- Testing Bureaucrat Construction ---" << std::endl;
    // Valid construction
    try {
        Bureaucrat b1("Alice", 1);
        std::cout << b1 << std::endl;
        Bureaucrat b2("Bob", 150);
        std::cout << b2 << std::endl;
        Bureaucrat b3("Charlie", 75);
        std::cout << b3 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    // Invalid construction (grade too high)
    try {
        Bureaucrat b_high("HighGradeHarry", 0);
        std::cout << b_high << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }

    // Invalid construction (grade too low)
    try {
        Bureaucrat b_low("LowGradeLarry", 151);
        std::cout << b_low << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Caught expected exception: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Caught unexpected exception: " << e.what() << std::endl;
    }
}

void    testBureaucratGradeChanges() {
    std::cout << "\n--- Testing Bureaucrat Grade Changes ---" << std::endl;
    Bureaucrat b("David", 75);
    std::cout << "Initial: " << b << std::endl;

    // Increment grade
    try {
        b.incrementGrade();
        std::cout << "After increment: " << b << std::endl; // Should be 74
    } catch (const std::exception& e) {
        std::cerr << "Error incrementing grade: " << e.what() << std::endl;
    }

    // Decrement grade
    try {
        b.decrementGrade();
        std::cout << "After decrement: " << b << std::endl; // Should be 75
        b.decrementGrade();
        std::cout << "After decrement: " << b << std::endl; // Should be 76
    } catch (const std::exception& e) {
        std::cerr << "Error decrementing grade: " << e.what() << std::endl;
    }

    // Increment to highest
    Bureaucrat b_high("Eve", 2);
    std::cout << "Initial Eve: " << b_high << std::endl;
    try {
        b_high.incrementGrade(); // To 1
        std::cout << "Eve after increment: " << b_high << std::endl;
        b_high.incrementGrade(); // Should throw
        std::cout << "Eve after 2nd increment (should not reach): " << b_high << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Eve: Caught expected GradeTooHighException: " << e.what() << std::endl;
        std::cout << "Eve final state: " << b_high << std::endl; // Should be 1
    }

    // Decrement to lowest
    Bureaucrat b_low("Frank", 149);
    std::cout << "Initial Frank: " << b_low << std::endl;
    try {
        b_low.decrementGrade(); // To 150
        std::cout << "Frank after decrement: " << b_low << std::endl;
        b_low.decrementGrade(); // Should throw
        std::cout << "Frank after 2nd decrement (should not reach): " << b_low << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Frank: Caught expected GradeTooLowException: " << e.what() << std::endl;
         std::cout << "Frank final state: " << b_low << std::endl; // Should be 150
    }
}

void    testFormConstruction() {
    std::cout << "\n--- Testing Form Construction ---" << std::endl;
    // Valid construction
    try {
        Form f1("Tax Form A", false, 50, 25);
        std::cout << f1 << std::endl;
        Form f2("Secret Document X", false, 1, 1);
        std::cout << f2 << std::endl;
        Form f3("Leave Request", false, 150, 100);
        std::cout << f3 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }

    // Invalid construction (grade to sign too high)
    try {
        Form f_invalid("Invalid Form Sign High", false, 0, 50);
        std::cout << f_invalid << std::endl;
    } catch (const Form::GradeTooHighException& e) {
        std::cerr << "Caught expected exception for sign grade too high: " << e.what() << std::endl;
    }
    // Invalid construction (grade to exec too high)
    try {
        Form f_invalid("Invalid Form Exec High", false, 50, 0);
        std::cout << f_invalid << std::endl;
    } catch (const Form::GradeTooHighException& e) {
        std::cerr << "Caught expected exception for exec grade too high: " << e.what() << std::endl;
    }

    // Invalid construction (grade to sign too low)
    try {
        Form f_invalid("Invalid Form Sign Low", false, 151, 50);
        std::cout << f_invalid << std::endl;
    } catch (const Form::GradeTooLowException& e) {
        std::cerr << "Caught expected exception for sign grade too low: " << e.what() << std::endl;
    }
    // Invalid construction (grade to exec too low)
    try {
        Form f_invalid("Invalid Form Exec Low", false, 50, 151);
        std::cout << f_invalid << std::endl;
    } catch (const Form::GradeTooLowException& e) {
        std::cerr << "Caught expected exception for exec grade too low: " << e.what() << std::endl;
    }
}

void	myTestOk()
{
    std::cout << "\n\n\n------------------------------------" << std::endl;
    std::cout << "--- Testing Form Signing Process ---" << std::endl;
    std::cout << "------------------------------------" << std::endl;
	std::cout << "~-~- TEST1 (everything's ok :) ) -~-~" << std::endl;
    Bureaucrat a_capable("Paul", 40);
	std::cout << a_capable << std::endl;
    Form form_b("Project Beta", false, 50, 20);
	std::cout << form_b << std::endl;

	try
	{
    	a_capable.signForm(form_b);
	}
	catch (const std::exception& e) {
        std::cerr << "Error during Henry's direct sign: " << e.what() << std::endl;
    }
	std::cout << form_b << std::endl;
}

void	myTestTooLow()
{
    std::cout << "\n\n\n------------------------------------" << std::endl;
    std::cout << "--- Testing Form Signing Process ---" << std::endl;
    std::cout << "------------------------------------" << std::endl;
	std::cout << "~-~- TEST1 2 (grade too low) -~-~" << std::endl;
    Bureaucrat b_incapable("Henry", 60);
	std::cout << b_incapable << std::endl;
	Form form_b("Project Beta", false, 50, 20);
	std::cout << form_b << std::endl;
	try
	{
    	b_incapable.signForm(form_b);
	}
	catch (const std::exception& e) {
        std::cerr	<< b_incapable.getName()
					<< " couldn't sign " << form_b.getName()
					<< " because of " << e.what() << std::endl;
    }
	std::cout << form_b << std::endl;
}

void	myTestSignAgain()
{
    std::cout << "\n\n\n------------------------------------" << std::endl;
    std::cout << "--- Testing Form Signing Process ---" << std::endl;
    std::cout << "------------------------------------" << std::endl;
	std::cout << "~-~- TEST3 (sign two time the same form) ) -~-~" << std::endl;
    Bureaucrat a_capable("Paul", 40);
	std::cout << a_capable << std::endl;
    Form form_b("Project Beta", false, 50, 20);
	std::cout << form_b << std::endl;
	try
	{
    	a_capable.signForm(form_b);
    	a_capable.signForm(form_b);
	}

	catch (const std::exception& e) {
        std::cerr	<< a_capable.getName()
					<< " couldn't sign " << form_b.getName()
					<< " because of " << e.what() << std::endl;
    }

	std::cout << form_b << std::endl;
}

void	myTestNotOkThenOk()
{
    std::cout << "\n\n\n------------------------------------" << std::endl;
    std::cout << "--- Testing Form Signing Process ---" << std::endl;
    std::cout << "------------------------------------" << std::endl;
	std::cout << "~-~- TEST4 (not ok then ok) -~-~" << std::endl;
    Bureaucrat b_incapable("Henry", 62);
	std::cout << b_incapable << std::endl;
	Form form_b("Project Beta", false, 61, 20);
	std::cout << form_b << std::endl;
	try
	{
    	b_incapable.signForm(form_b);
	}
	catch (const std::exception& e) {
        std::cerr	<< b_incapable.getName()
					<< " couldn't sign " << form_b.getName()
					<< " because of " << e.what() << std::endl;
    }
	b_incapable.incrementGrade();
	std::cout << form_b << std::endl;
	std::cout << b_incapable << std::endl;
	try
	{
    	b_incapable.signForm(form_b);
	}
	catch (const std::exception& e) {
        std::cerr	<< b_incapable.getName()
					<< " couldn't sign " << form_b.getName()
					<< " because of " << e.what() << std::endl;
    }
	std::cout << form_b << std::endl;
}

int main() {
    //testBureaucratConstruction();
    //testBureaucratGradeChanges();
    //testFormConstruction();
	myTestOk();
	myTestTooLow();
	myTestSignAgain();
	myTestNotOkThenOk();

    std::cout << "\n--- All tests completed ---" << std::endl;
    return 0;
}
