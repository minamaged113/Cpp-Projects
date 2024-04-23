#if !defined(__NUMBER_H__)
#define __NUMBER_H__

#include <cstdlib>
#include <iostream>


namespace Number {
struct Number {
    int value;
    int min;
    int max;

    // ctors
    Number();
    Number(int value);
    Number(int min, int max);

    // dtors
    ~Number();

    // Overloaded operators
    bool operator==(const int other);

    bool operator==(const Number &other);

    int operator-(const Number &other) const;

    // methods
    int random();
};

float error(const Number &input, const Number &reference);

std::istream &operator>>(std::istream &in, Number &number);
} // namespace Number

#endif // __NUMBER_H__
