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
        bool nIsNegative = false;
        if (d < 0)  // Moves the negative sign to the numerator when the denominator is less than 0.
        {
            n = -n;
            d = abs(d);
        }
        if (n < 0)
        {
            nIsNegative = true;
            n = -n;
        }
        // Find out the greatest common divisor of both values and simplifies them if needed.
        int gcdValue = gcd(n, d);
        n /= gcdValue;
        d /= gcdValue;
        if (nIsNegative)
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

void RationalNumber::printRational() const
{
    if (denominator != 1)
        cout << numerator << "/" << denominator;
    else
        cout << numerator;
}

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

bool RationalNumber::operator>(const RationalNumber& another) const
{
    if (denominator == another.denominator)
        return numerator > another.numerator;
    else
    {
        int currentNume = numerator * another.denominator;
        int anotherNume = denominator * another.numerator;
        int Deno = denominator * another.denominator;
        if (currentNume > Deno)
            return currentNume > anotherNume;
        else
            return currentNume < anotherNume;
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
        int Deno = denominator * another.denominator;
        if (currentNume > Deno)
            return currentNume < anotherNume;
        else
            return currentNume > anotherNume;
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
        int Deno = denominator * another.denominator;
        if (currentNume > Deno)
            return currentNume >= anotherNume;
        else
            return currentNume <= anotherNume;
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
        int Deno = denominator * another.denominator;
        if (currentNume > Deno)
            return currentNume <= anotherNume;
        else
            return currentNume >= anotherNume;
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
        int Deno = denominator * another.denominator;
        if (currentNume > Deno)
            return currentNume == anotherNume;
        else
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
        int Deno = denominator * another.denominator;
        if (currentNume > Deno)
            return currentNume != anotherNume;
        else
            return currentNume != anotherNume;
    }
}