/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:20:24 by aboumall          #+#    #+#             */
/*   Updated: 2025/10/14 12:00:53 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &other);
		~Point();

		Point &operator=(const Point &other);

		const Fixed &getX() const;
		const Fixed &getY() const;

		bool operator==(const Point &other) const;
};

std::ostream &operator<<(std::ostream &out, const Point &point);
bool bsp(const Point a, const Point b, const Point c, const Point point);

#endif