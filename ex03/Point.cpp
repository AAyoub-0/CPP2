/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:20:17 by aboumall          #+#    #+#             */
/*   Updated: 2025/07/09 18:55:24 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) { }
Point::Point(const float x, const float y) : _x(x), _y(y) { }
Point::Point(const Point &other) : _x(other._x), _y(other._y) { }
Point::~Point() { }

Point &Point::operator=(const Point &other) {
	if (this != &other) {
		// _x and _y are const, so we cannot assign them
		// This is intentional to prevent modification of Point coordinates
	}
	return *this;
}
bool Point::operator==(const Point &other) const {
	return (_x == other._x && _y == other._y);
}
std::ostream &operator<<(std::ostream &out, const Point &point) {
	out << "(" << point.getX() << ", " << point.getY() << ")";
	return out;
}

const Fixed &Point::getX() const {
	return _x;
}
const Fixed &Point::getY() const {
	return _y;
}
