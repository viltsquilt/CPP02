#include "Fixed.hpp"

Fixed::Fixed() {

	std::cout << "Default constructor called" << std::endl;
	_num = 0;
};

Fixed::Fixed(const Fixed& orig) {

	std::cout << "Copy constructor called" << std::endl;
	_num = orig._num;
};

Fixed&	Fixed::operator=(const Fixed& orig) {

	std::cout << "Copy assignment operator called" << std::endl;
	_num = orig._num;
	return (*this);
};

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
