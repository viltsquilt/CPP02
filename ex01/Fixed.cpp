#include "Fixed.hpp"

Fixed::Fixed() {

	std::cout << "Default constructor called" << std::endl;
	_num = 0;
};

Fixed::Fixed(const Fixed& orig) {

	std::cout << "Copy constructor called" << std::endl;
	setRawBits(orig._num);
};

Fixed&	Fixed::operator=(const Fixed& orig) {

	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(orig._num);
	return (*this);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& copy) {

	os << copy.toFloat();
	return (os);
};

Fixed::Fixed(const int num) {

	std::cout << "Int constructor called" << std::endl;
	_num = num << _bits;
};

Fixed::Fixed(const float num) {

	std::cout << "Float constructor called" << std::endl;
	_num = roundf(num *(1 << _bits));
};

float	Fixed::toFloat(void) const {

	return (float(_num) / (1 << _bits));
};

int	Fixed::toInt(void) const {

	return (_num >> _bits);
}

Fixed::~Fixed() {

	std::cout << "Destructor called" << std::endl;
};

int	Fixed::getRawBits(void) const {

	std::cout << "getRawBits member function called" << std::endl;
	return (_num);
};

void	Fixed::setRawBits(int const raw) {

	_num = raw;
};
