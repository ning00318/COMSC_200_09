#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

class RationalNumber
{
public:
    RationalNumber();   // Default constructor
    RationalNumber(int, int);
    void printRational() const;
    RationalNumber operator+(const RationalNumber&) const;
    RationalNumber operator-(const RationalNumber&) const;
    RationalNumber operator*(const RationalNumber&) const;
/*    RationalNumber operator/(const RationalNumber&) const;
    RationalNumber &operator=(const RationalNumber&);

    bool operator<(const RationalNumber&) const;
    bool operator>(const RationalNumber&) const;
    bool operator<=(const RationalNumber&) const;
    bool operator>=(const RationalNumber&) const;
    bool operator==(const RationalNumber&) const;
    bool operator!=(const RationalNumber&) const;*/
private:
    int numerator;
    int denominator;
    int gcd(int, int);
};

#endif