/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:19:01 by aboumall          #+#    #+#             */
/*   Updated: 2025/07/09 18:15:26 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main() {
	{
		// Subject test
		std::cout << "Subject test:" << std::endl;
		Fixed a;
		Fixed const b(Fixed(5.05f) * Fixed(2));

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;

		std::cout << Fixed::max(a, b) << std::endl;
	}
	{
		// Additional tests
		std::cout << "\nAdditional tests:" << std::endl;
		Fixed a(5);
		Fixed const b(2.5f);
		Fixed c;
		
		// testing operators
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "a + b: " << a + b << std::endl;
		std::cout << "a - b: " << a - b << std::endl;
		std::cout << "a / b: " << a / b << std::endl;
		std::cout << "a * b: " << a * b << std::endl;
		
		c = a * b;
		// testing comparison operators
		std::cout << "c: " << c << std::endl;
		std::cout << "a > b: " << (a > b) << std::endl;
		std::cout << "a < b: " << (a < b) << std::endl;
		std::cout << "a >= b: " << (a >= b) << std::endl;
		std::cout << "a <= b: " << (a <= b) << std::endl;
		std::cout << "c == (b * a): " << (c == b * a) << std::endl;
		std::cout << "c != (b * a): " << (c != b * a) << std::endl;

		// testing increment and decrement operators
		c = c.toInt(); // Reset c to an integer value for clarity
		std::cout << "c before increment: " << c << std::endl;
		std::cout << "++c: " << ++c << std::endl;
		std::cout << "c after increment: " << c << std::endl;
		std::cout << "c after post-increment: " << c++ << std::endl;
		std::cout << "c after post-increment: " << c << std::endl;
		std::cout << "--c: " << --c << std::endl;
		std::cout << "c after decrement: " << c << std::endl;
		std::cout << "c after post-decrement: " << c-- << std::endl;
		std::cout << "c after post-decrement: " << c << std::endl;
	}
	{
		// try division by zero
		std::cout << "\nTesting division by zero:" << std::endl;

		Fixed a(5);
		Fixed b(0);
		
		try {
			std::cout << "a / b: " << a / b << std::endl;
		} catch (const std::runtime_error &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	return 0;
}
