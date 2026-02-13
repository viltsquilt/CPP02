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
		~Fixed();
		Fixed(const int num);
		Fixed(const float num);

		//copy constructor
		Fixed(const Fixed& copy);

		//copy assignment operator overload
		Fixed& operator=(const Fixed& copy);

		float	toFloat(void) const;
		int	toInt(void) const;
		int	getRawBits(void) const;
		void	setRawBits(int const raw);

		//comparison operators >,<,>=,<=,==,!=
		bool operator>(const Fixed& num) const;
		bool operator<(const Fixed& num) const;
		bool operator>=(const Fixed& num) const;
		bool operator<=(const Fixed& num) const;
		bool operator==(const Fixed& num) const;
		bool operator!=(const Fixed& num) const;

		//arithmetic operators +,-,*,/
		Fixed operator+(const Fixed& num);
		Fixed operator-(const Fixed& num);
		Fixed operator*(const Fixed& num);
		Fixed operator/(const Fixed& num);

		//increment and decrement operators
		
		//post a++, a--
		Fixed& operator++();
		Fixed& operator--();

		//pre ++a, --a
		Fixed operator++(int);
		Fixed operator--(int);

		//min and max functions
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
};

std::ostream&	 operator<<(std::ostream& os, const Fixed& copy);
