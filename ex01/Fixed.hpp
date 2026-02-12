#pragma once

#include <iostream>
#include <cmath>
#include <fstream>

class Fixed {

	private:
		int			_num;
		static const int	_bits = 8;
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		//copy constructor
		Fixed(const Fixed& copy);
		//copy assignmendt operator overload
		Fixed& operator=(const Fixed& copy);
		~Fixed();
		float	toFloat(void) const;
		int	toInt(void) const;
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};

std::ostream&	 operator<<(std::ostream& os, const Fixed& copy);
