#include "number/number.h"

namespace Number {
// Number::ctors
Number::Number() {
    value = 0;
    min = 0;
    max = 100;
}
Number::Number(int value) : value(value) {
    if (value >= 0) {
        min = 0;
        max = value;
    } else if (value < 0) {
        min = value;
        max = 0;
    }
}
Number::Number(int min, int max) : min(min), max(max) { (void)this->random(); }

// Number::dtors
Number::~Number() {}

// Number::operators
bool Number::operator==(const int other) { return value == other; }

bool Number::operator==(const Number &other) { return value == other.value; }

int Number::operator-(const Number &other) const { return value - other.value; }

// Number::methods
int Number::random() {
    value = rand() % this->max;
    return this->value;
}

float error(const Number &input, const Number &reference) {
    if ((reference.max - reference.min) == 0)
    {
        return 0.;
    }
    
    return (input - reference) / (float)(reference.max - reference.min);
}

std::istream &operator>>(std::istream &in, Number &number) {
    int value;
    in >> value;
    number.value = value;
    return in;
}
} // namespace Number