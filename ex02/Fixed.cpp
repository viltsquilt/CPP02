#include "Fixed.hpp"

Fixed::Fixed() {

	std::cout << "Default constructor called" << std::endl;
	_num = 0;
};

Fixed::~Fixed() {

	std::cout << "Destructor called" << std::endl;
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

int	Fixed::getRawBits(void) const {

	std::cout << "getRawBits member function called" << std::endl;
	return (_num);
};

void	Fixed::setRawBits(int const raw) {

	_num = raw;
};

bool	Fixed::operator>(const Fixed& num) const {

	return (this->_num > num._num);
};

bool	Fixed::operator<(const Fixed& num) const {

	return (this->_num < num._num);
};

bool	Fixed::operator>=(const Fixed& num) const {

	return (this->_num >= num._num);
};

bool	Fixed::operator<=(const Fixed& num) const {

	return (this->_num <= num._num);
};

bool	Fixed::operator==(const Fixed& num) const {

	return (this->_num == num._num);
};

bool	Fixed::operator!=(const Fixed& num) const {

	return (this->_num != num._num);
};

Fixed	Fixed::operator+(const Fixed& num) {

	Fixed	res;
	res.setRawBits(this->_num + num._num);
	return (res);
};

Fixed	Fixed::operator-(const Fixed& num) {

	Fixed	res;
	res.setRawBits(this->_num - num._num);
	return (res);
};

Fixed	Fixed::operator*(const Fixed& num) {

	Fixed	res;
	res.setRawBits(this->_num * num._num >> _bits);
	return (res);
};

Fixed	Fixed::operator/(const Fixed& num) {

	Fixed	res;
	res.setRawBits(this->_num / num._num << _bits);
	return (res);
};

//post-increment operator a++
//returns copy, increments actual value
Fixed	Fixed::operator++(int) {

	Fixed	temp = (*this);
	++this->_num;
	return (temp);
};

//pre-increment operator ++a
//returns reference to incremented value
Fixed&	Fixed::operator++() {

	++this->_num;
	return(*this);
};

//post-decrement operator a--
//returns copy, decrements actual value
Fixed	Fixed::operator--(int) {

	Fixed	temp = *this;
	--this->_num;
	return (temp);
};

//pre-decrement operator --a
//returns reference to decremented value
Fixed&	Fixed::operator--() {

	--this->_num;
	return (*this);
};

//min and max functions
Fixed&	Fixed::max(Fixed& a, Fixed& b) {

	return ((a > b) ? a : b);
};

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b){

	return ((a > b) ? a : b);
};

Fixed&	Fixed::min(Fixed& a, Fixed& b) {

	return ((a < b) ? a : b);
};

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {

	return ((a < b) ? a : b);
};
