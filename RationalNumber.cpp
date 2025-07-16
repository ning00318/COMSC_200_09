#include <iostream>
#include <cmath>
#include <stdexcept>
#include "RationalNumber.h"
using namespace std;
RationalNumber::RationalNumber() {}
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

int RationalNumber::gcd(int n, int d)
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
    if (denominator != 1)
        cout << numerator << "/" << denominator;
    else
        cout << numerator;
}

RationalNumber RationalNumber::operator+(const RationalNumber& another) const
{
    RationalNumber result;  // Create a new RationalNumber object
    result.numerator = numerator;
    result.denominator = denominator;

    if (result.denominator == another.denominator)
        result.numerator += another.numerator;
    else
    {
        result.numerator = result.numerator * another.denominator + result.denominator * another.numerator;
        result.denominator *= another.denominator;
    }
    
    return result;
}
/*
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
*/