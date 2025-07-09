/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:19:01 by aboumall          #+#    #+#             */
/*   Updated: 2025/07/09 18:55:57 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main() {
	Point a(0, 0);
	Point b(5, 0);
	Point c(0, 5);
	Point inside(1, 1);
	Point outside(6, 6);

	if (bsp(a, b, c, inside)) {
		std::cout << "Point " << inside << " is inside the triangle formed by points " 
		          << a << ", " << b << ", and " << c << "." << std::endl;
	} else {
		std::cout << "Point " << inside << " is outside the triangle formed by points "
		          << a << ", " << b << ", and " << c << "." << std::endl;
	}

	if (bsp(a, b, c, outside)) {
		std::cout << "Point " << outside << " is inside the triangle formed by points "
		          << a << ", " << b << ", and " << c << "." << std::endl;
	} else {
		std::cout << "Point " << outside << " is outside the triangle formed by points "
		          << a << ", " << b << ", and " << c << "." << std::endl;
	}
	return 0;
}
