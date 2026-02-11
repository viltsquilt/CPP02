#pragma once

#include <iostream>

class Fixed {

	private:
		int			_num;
		static const int	_bits = 8;
	public:
		Fixed();
		//copy constructor
		Fixed(const Fixed& copy);
		//copy assignment operator overload
		Fixed& operator=(const Fixed& copy);
		~Fixed();
		int	getRawBits(void) const;
		void	setRawBits(int const raw);
};
