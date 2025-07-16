#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

class RationalNumber
{
public:
    RationalNumber();   // Comment 1: Create a default constructor for x.
    RationalNumber(int, int);
    void printRational() const;

    // Comment 2: In the overloading operators (+, -, *, /), we should not modify
    //            the values from both the current and another RationalNumber object.
    RationalNumber operator+(const RationalNumber&) const;
    RationalNumber operator-(const RationalNumber&) const;
    RationalNumber operator*(const RationalNumber&) const;
    RationalNumber operator/(const RationalNumber&) const;

    // Comment 3: For the assignment operator (=), the current RationalNumber object
    //            will be updated while another object should stay the same.
    RationalNumber &operator=(const RationalNumber&);

    // Comment 4: In the relational and equality operators (>, <, >=, <=, ==, !=),
    //            we should not modifyany values from both objects, instead, we
    //            compare and return if values match the corresponding requirements.
    bool operator>(const RationalNumber&) const;
    bool operator<(const RationalNumber&) const;
    bool operator>=(const RationalNumber&) const;
    bool operator<=(const RationalNumber&) const;
    bool operator==(const RationalNumber&) const;
    bool operator!=(const RationalNumber&) const;
private:
    int numerator;
    int denominator;
    int gcd(int, int);  // Comment 5: Create a helper function for the constructor.
};

#endif