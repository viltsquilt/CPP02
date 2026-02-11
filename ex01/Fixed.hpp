#pragma once

#include <iostream>

class Fixed {

	private:
		int			_num;
		static const int	_bits = 8;
	public:
		Fixed(const int num);
		Fixed(const float num);
		//copy constructor
		Fixed(const Fixed& copy);
		//copy assignmendt operator overload
		Fixed& operator=(const Fixed& copy);
		~Fixed();
		float	toFloat(void) const;
		int	toInt(void) const;
	Fixed& operator<<(const Fixed& copy);
};
