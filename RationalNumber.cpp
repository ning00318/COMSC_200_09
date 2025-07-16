#include <iostream>
#include <cmath>
#include <stdexcept>
#include "RationalNumber.h"
using namespace std;

RationalNumber::RationalNumber(int n, int d)
{
    if (d != 0)
    {
        if (d < 0)  // Moves the negative sign to the numerator when the denominator is less than 0.
        {
            n = -n;
            d = abs(d);
        }

        // Find out the greatest common divisor of both values and simplifies them if needed.
        int gcdValue = gcd(n, d);
        n /= gcdValue;
        d /= gcdValue;
        numerator = n;
        denominator = d;
    }
    else
        throw invalid_argument("The denominator should not be 0.");
}

int gcd(int n, int d)
{
    while (d != 0)
    {
        int temp = d;
        d = n % d;
        n = temp;
    }
    return n;
}
void RationalNumber::printRational() const
{

}
RationalNumber RationalNumber::operator+(const RationalNumber&) const
{

}
RationalNumber RationalNumber::operator-(const RationalNumber&) const
{

}
RationalNumber RationalNumber::operator*(const RationalNumber&) const
{

}
RationalNumber RationalNumber::operator/(const RationalNumber&) const
{

}
RationalNumber &RationalNumber::operator=(const RationalNumber&)
{

}

bool RationalNumber::operator<(const RationalNumber&) const
{

}
bool RationalNumber::operator>(const RationalNumber&) const
{

}
bool RationalNumber::operator<=(const RationalNumber&) const
{

}
bool RationalNumber::operator>=(const RationalNumber&) const
{

}
bool RationalNumber::operator==(const RationalNumber&) const
{

}
bool RationalNumber::operator!=(const RationalNumber&) const
{

}