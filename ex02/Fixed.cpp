#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _rawBits(value << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
    : _rawBits(static_cast<int>(roundf(value * (1 << _fractionalBits)))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        _rawBits = other._rawBits;
    return *this;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return _rawBits;
}

void Fixed::setRawBits(int const raw) {
    _rawBits = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(_rawBits) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _rawBits >> _fractionalBits;
}

bool Fixed::operator>(const Fixed &other) const { return _rawBits > other._rawBits; }
bool Fixed::operator<(const Fixed &other) const { return _rawBits < other._rawBits; }
bool Fixed::operator>=(const Fixed &other) const { return _rawBits >= other._rawBits; }
bool Fixed::operator<=(const Fixed &other) const { return _rawBits <= other._rawBits; }
bool Fixed::operator==(const Fixed &other) const { return _rawBits == other._rawBits; }
bool Fixed::operator!=(const Fixed &other) const { return _rawBits != other._rawBits; }

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result._rawBits = _rawBits + other._rawBits;
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result._rawBits = _rawBits - other._rawBits;
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    result._rawBits = static_cast<int>((static_cast<long>(_rawBits) * other._rawBits) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;
    result._rawBits = static_cast<int>((static_cast<long>(_rawBits) << _fractionalBits) / other._rawBits);
    return result;
}

Fixed &Fixed::operator++(void) {
    ++_rawBits;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    ++_rawBits;
    return tmp;
}

Fixed &Fixed::operator--(void) {
    --_rawBits;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    --_rawBits;
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &o, const Fixed &fixed) {
    o << fixed.toFloat();
    return o;
}
