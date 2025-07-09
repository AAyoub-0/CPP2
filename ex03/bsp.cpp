/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:29:22 by aboumall          #+#    #+#             */
/*   Updated: 2025/07/09 18:53:18 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point) {
	float areaABC = ((a.getX() - c.getX()) * (b.getY() - a.getY()) - (a.getX() - b.getX()) * (c.getY() - a.getY())).toFloat();
	float areaPAB = ((a.getX() - point.getX()) * (b.getY() - a.getY()) - (a.getX() - b.getX()) * (point.getY() - a.getY())).toFloat();
	float areaPBC = ((b.getX() - point.getX()) * (c.getY() - b.getY()) - (b.getX() - c.getX()) * (point.getY() - b.getY())).toFloat();
	float areaPCA = ((c.getX() - point.getX()) * (a.getY() - c.getY()) - (c.getX() - a.getX()) * (point.getY() - c.getY())).toFloat();

	return ((areaABC > 0 && areaPAB > 0 && areaPBC > 0 && areaPCA > 0) ||
			(areaABC < 0 && areaPAB < 0 && areaPBC < 0 && areaPCA < 0));
}
