#include <iostream>
#include <cmath>    // abs()
#include <stdexcept>
#include "RationalNumber.h"
using namespace std;
RationalNumber::RationalNumber() {}
RationalNumber::RationalNumber(int n, int d)
{
    if (d != 0)
    {
        bool nIsNegative = false;

        // Comment 6: Moves the negative sign to the numerator when the denominator is less than 0.
        if (d < 0)
        {
            n = -n;
            d = abs(d);
        }

        // Comment 7: Makes the numerator positive if it is less than 0.
        if (n < 0)
        {
            nIsNegative = true;
            n = -n;
        }

        // Comment 8: Find out the greatest common divisor of both values and simplify them if needed.
        int gcdValue = gcd(n, d);
        n /= gcdValue;
        d /= gcdValue;
        if (nIsNegative)    // Comment 9: After finding out the gcd, put back the negative sign if needed.
            n = -n;
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

// Comment 10: There is no need to print out the denominator if its value is 1.
void RationalNumber::printRational() const
{
    if (denominator != 1)
        cout << numerator << "/" << denominator;
    else
        cout << numerator;
}

// Comment 11: When both denominators are the same, add both numerators to a new variable, and the denominator remains the
//             same. Otherwise, convert fractions to a common denominator and update their corresponding numerators.
RationalNumber RationalNumber::operator+(const RationalNumber& another) const
{
    int nume, deno;
    if (denominator == another.denominator)
    {
        nume = numerator + another.numerator;
        deno = denominator;
    }
    else
    {
        nume = numerator * another.denominator + denominator * another.numerator;
        deno = denominator * another.denominator;
    }
    
    // Comment 12: After having the updated numerator and denominator, invoke
    //             the constructor to check if the output fraction is simplified.
    return RationalNumber(nume, deno);
}

RationalNumber RationalNumber::operator-(const RationalNumber& another) const
{
    int nume, deno;
    if (denominator == another.denominator)
    {
        nume = numerator - another.numerator;
        deno = denominator;
    }
    else
    {
        nume = numerator * another.denominator - denominator * another.numerator;
        deno = denominator * another.denominator;
    }
   
    return RationalNumber(nume, deno);
}

RationalNumber RationalNumber::operator*(const RationalNumber& another) const
{
    int nume, deno;
    nume = numerator * another.numerator;
    deno = denominator * another.denominator;
    
    return RationalNumber(nume, deno);
}

RationalNumber RationalNumber::operator/(const RationalNumber& another) const
{
    int nume, deno;
    nume = numerator * another.denominator;
    deno = denominator * another.numerator;
    
    return RationalNumber(nume, deno);
}

RationalNumber &RationalNumber::operator=(const RationalNumber& another)
{
    numerator = another.numerator;
    denominator = another.denominator;
    return *this;
}

// Comment 13: When both denominators are the same, return whether the current numerator is greater than
//             another.Otherwise, convert fractions to a common denominator and compare the numerators.
bool RationalNumber::operator>(const RationalNumber& another) const
{
    if (denominator == another.denominator)
        return numerator > another.numerator;
    else
    {
        int currentNume = numerator * another.denominator;
        int anotherNume = denominator * another.numerator;
        return currentNume > anotherNume;
    }
}

bool RationalNumber::operator<(const RationalNumber& another) const
{
    if (denominator == another.denominator)
        return numerator < another.numerator;
    else
    {
        int currentNume = numerator * another.denominator;
        int anotherNume = denominator * another.numerator;
        return currentNume < anotherNume;
    }
}

bool RationalNumber::operator>=(const RationalNumber& another) const
{
    if (denominator == another.denominator)
        return numerator >= another.numerator;
    else
    {
        int currentNume = numerator * another.denominator;
        int anotherNume = denominator * another.numerator;
        return currentNume >= anotherNume;
    }
}

bool RationalNumber::operator<=(const RationalNumber& another) const
{
    if (denominator == another.denominator)
        return numerator <= another.numerator;
    else
    {
        int currentNume = numerator * another.denominator;
        int anotherNume = denominator * another.numerator;
        return currentNume <= anotherNume;
    }
}

bool RationalNumber::operator==(const RationalNumber& another) const
{
    if (denominator == another.denominator)
        return numerator == another.numerator;
    else
    {
        int currentNume = numerator * another.denominator;
        int anotherNume = denominator * another.numerator;
        return currentNume == anotherNume;
    }
}
bool RationalNumber::operator!=(const RationalNumber& another) const
{
    if (denominator == another.denominator)
        return numerator != another.numerator;
    else
    {
        int currentNume = numerator * another.denominator;
        int anotherNume = denominator * another.numerator;
        return currentNume != anotherNume;
    }
}