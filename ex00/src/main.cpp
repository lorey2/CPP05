/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorey <lorey@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 01:59:45 by lorey             #+#    #+#             */
/*   Updated: 2025/05/19 22:00:47 by lorey            ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

// src/main.cpp
#include "Bureaucrat.hpp" // Assuming Bureaucrat.hpp is in the 'includes' directory
#include <iostream>
#include <exception> // For std::exception

// The main function - entry point of your program
int main() {
    // Example Usage of Bureaucrat
    try {
        Bureaucrat b1("Alice", 1); // Highest grade
        std::cout << b1 << std::endl;

        b1.decrementGrade(); // Grade becomes 2
        std::cout << "After decrement: " << b1 << std::endl;

        b1.incrementGrade(); // Grade becomes 1 again
        std::cout << "After increment: " << b1 << std::endl;

        Bureaucrat b2("Bob", 150); // Lowest grade
        std::cout << b2 << std::endl;

        // b2.decrementGrade(); // This should ideally throw GradeTooLowException or print an error
                            // if you implemented the boundary checks correctly.

        // b1.incrementGrade(); // This should ideally throw GradeTooHighException or print an error.


        Bureaucrat b3("Charlie", 75);
        std::cout << b3 << std::endl;

        Bureaucrat b4 = b3; // Test copy constructor
        std::cout << "Copied b4: " << b4 << std::endl;

        Bureaucrat b5("Dave", 100);
        b5 = b1; // Test assignment operator
        std::cout << "Assigned b5 from b1: " << b5 << std::endl;
        std::cout << "Original b1 (name should be unchanged): " << b1 << std::endl;


        // Test exceptions (if you've implemented them)
        std::cout << "\n--- Testing Exceptions ---" << std::endl;
        try {
            Bureaucrat tooHigh("HighScorer", 0); // Should trigger an error or be clamped
            std::cout << tooHigh << std::endl;
        } catch (const Bureaucrat::GradeTooHighException& e) {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        } catch (const std::exception& e) { // Catch any other standard exceptions
            std::cerr << "Caught standard exception: " << e.what() << std::endl;
        }

        try {
            Bureaucrat tooLow("LowScorer", 151); // Should trigger an error or be clamped
            std::cout << tooLow << std::endl;
        } catch (const Bureaucrat::GradeTooLowException& e) {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Caught standard exception: " << e.what() << std::endl;
        }

        // Example of trying to increment beyond the highest grade
        try {
            Bureaucrat top("TopRank", 1);
            std::cout << top << std::endl;
            top.incrementGrade(); // Attempt to go higher than 1
            std::cout << "After trying to increment past highest: " << top << std::endl;
        } catch (const Bureaucrat::GradeTooHighException& e) {
            std::cerr << "Caught exception during increment: " << e.what() << std::endl;
        }


    } catch (const std::exception& e) {
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
        return 1; // Indicate an error
    }

    return 0; // Indicate successful execution
}
