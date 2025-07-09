/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:17:54 by aboumall          #+#    #+#             */
/*   Updated: 2025/07/09 18:57:24 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors and Destructor
Fixed::Fixed() : _value(0) { }
Fixed::Fixed(const Fixed &other) : _value(other._value) { }
Fixed::Fixed(const int integer) {
	_value = integer << _fractionalBits;
}
Fixed::Fixed(const float floatingPoint) {
	_value = static_cast<int>(roundf(floatingPoint * (1 << _fractionalBits)));
}
Fixed::~Fixed() { }

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		_value = other._value;
	}
	return *this;
}
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	return out << fixed.toFloat();
}

// Comparison operators
bool operator>(const Fixed &lhs, const Fixed &rhs) {
	return lhs._value > rhs._value;
}
bool operator<(const Fixed &lhs, const Fixed &rhs) {
	return lhs._value < rhs._value;
}
bool operator>=(const Fixed &lhs, const Fixed &rhs) {
	return lhs._value >= rhs._value;
}
bool operator<=(const Fixed &lhs, const Fixed &rhs) {
	return lhs._value <= rhs._value;
}
bool operator==(const Fixed &lhs, const Fixed &rhs) {	
	return lhs._value == rhs._value;
}
bool operator!=(const Fixed &lhs, const Fixed &rhs) {
	return lhs._value != rhs._value;
}

// Arithmetic operators
Fixed operator+(const Fixed &lhs, const Fixed &rhs) {
	return Fixed(lhs.toFloat() + rhs.toFloat());
}
Fixed operator-(const Fixed &lhs, const Fixed &rhs) {
	return Fixed(lhs.toFloat() - rhs.toFloat());
}
Fixed operator*(const Fixed &lhs, const Fixed &rhs) {
	return Fixed(lhs.toFloat() * rhs.toFloat());
}
Fixed operator/(const Fixed &lhs, const Fixed &rhs) {
	if (rhs._value == 0) {
		throw std::runtime_error("Division by zero");
	}
	return Fixed(lhs.toFloat() / rhs.toFloat());
}

// Increment and Decrement operators
Fixed &Fixed::operator++() {
	_value++;
	return *this;
}
Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	_value++;
	return temp;
}
Fixed &Fixed::operator--() {
	_value--;
	return *this;
}
Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	_value--;
	return temp;
}

// Getter and Setter
int Fixed::getRawBits() const {
	return _value;
}
void Fixed::setRawBits(int const raw) {
	_value = raw;
}

// Conversion functions
float Fixed::toFloat() const {
	return static_cast<float>(_value) / (1 << _fractionalBits);
}
int Fixed::toInt() const {
	return _value >> _fractionalBits;
}

// Min and Max functions
Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}
