/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:17:54 by aboumall          #+#    #+#             */
/*   Updated: 2025/10/16 14:09:33 by aboumall         ###   ########.fr       */
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
bool Fixed::operator>(const Fixed &fixed) const {
	return this->toFloat() > fixed.toFloat();
}
bool Fixed::operator<(const Fixed &fixed) const {
	return this->toFloat() < fixed.toFloat();
}
bool Fixed::operator>=(const Fixed &fixed) const {
	return this->toFloat() >= fixed.toFloat();
}
bool Fixed::operator<=(const Fixed &fixed) const {
	return this->toFloat() <= fixed.toFloat();
}
bool Fixed::operator==(const Fixed &fixed) const {
	return this->toFloat() == fixed.toFloat();
}
bool Fixed::operator!=(const Fixed &fixed) const {
	return this->toFloat() != fixed.toFloat();
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &fixed) const {
	return Fixed(fixed.toFloat() + this->toFloat());
}
Fixed Fixed::operator-(const Fixed &fixed) const {
	return Fixed(this->toFloat() - fixed.toFloat());
}
Fixed Fixed::operator*(const Fixed &fixed) const {
	return Fixed(fixed.toFloat() * this->toFloat());
}
Fixed Fixed::operator/(const Fixed &fixed) const {
	if (fixed.toFloat() == 0) {
		throw std::runtime_error("Division by zero");
	}
	return Fixed(this->toFloat() / fixed.toFloat());
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
	return (a.toFloat() < b.toFloat()) ? a : b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a.toFloat() > b.toFloat()) ? a : b;
}
