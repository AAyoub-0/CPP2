/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:13:57 by aboumall          #+#    #+#             */
/*   Updated: 2025/07/09 17:36:07 by aboumall         ###   ########.fr       */
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

		int getRawBits() const;
		void setRawBits(int const raw);

		float toFloat() const;
		int toInt() const;
};

#endif