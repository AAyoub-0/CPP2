/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:13:57 by aboumall          #+#    #+#             */
/*   Updated: 2025/07/09 17:52:24 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int integer);
		Fixed(const float floatingPoint);
		~Fixed();

		Fixed &operator=(const Fixed &other);
		friend std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
		// operand for >, <, >=, <=, ==, !=
		friend bool operator>(const Fixed &lhs, const Fixed &rhs);
		friend bool operator<(const Fixed &lhs, const Fixed &rhs);
		friend bool operator>=(const Fixed &lhs, const Fixed &rhs);
		friend bool operator<=(const Fixed &lhs, const Fixed &rhs);
		friend bool operator==(const Fixed &lhs, const Fixed &rhs);
		friend bool operator!=(const Fixed &lhs, const Fixed &rhs);
		// operand for +, -, *, /
		friend Fixed operator+(const Fixed &lhs, const Fixed &rhs);
		friend Fixed operator-(const Fixed &lhs, const Fixed &rhs);
		friend Fixed operator*(const Fixed &lhs, const Fixed &rhs);
		friend Fixed operator/(const Fixed &lhs, const Fixed &rhs);
		// increment and decrement operators
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		int getRawBits() const;
		void setRawBits(int const raw);

		float toFloat() const;
		int toInt() const;

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
};

#endif