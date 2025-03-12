#include <iostream>

struct Rational
{
    int64_t numerator;
    int64_t denominator;
};

int64_t getAbsoluteNumber(int64_t num)
{
    if (num < 0)
        return -num;
    else
        return num;
}

int64_t gcd(int64_t a, int64_t b)
{
    a = getAbsoluteNumber(a);
    b = getAbsoluteNumber(b);

    if (b == 0)
        return a;

    return gcd(b, a % b);
}

void canonicalizeNumber(Rational& r)
{
    int64_t greatestCommonDivisor = gcd(r.numerator, r.denominator);
    r.numerator /= greatestCommonDivisor;
    r.denominator /= greatestCommonDivisor;

    if (r.numerator < 0 && r.denominator < 0)
    {
        r.numerator *= -1;
        r.denominator *= -1;
    }
}

Rational createRational(int64_t a, int64_t b)
{
    if (!b)
        b = 1;

    Rational rational = { a, b };
    canonicalizeNumber(rational);

    return rational;
}

Rational sumRational(const Rational& lhs, const Rational& rhs)
{
    return createRational(lhs.numerator * rhs.denominator + lhs.denominator * rhs.numerator, lhs.denominator * rhs.denominator);
}

Rational multiplyRational(const Rational& lhs, const Rational& rhs)
{
    return createRational(lhs.numerator * rhs.numerator, lhs.denominator * rhs.denominator);
}

Rational substractRational(const Rational& lhs, const Rational& rhs)
{
    return createRational(lhs.numerator * rhs.denominator - lhs.denominator * rhs.numerator, lhs.denominator * rhs.denominator);
}

Rational divideRational(const Rational& lhs, const Rational& rhs)
{
    return createRational(lhs.numerator * rhs.denominator, lhs.denominator * rhs.numerator);
}

void printRational(const Rational& rational)
{
    std::cout << rational.numerator << "/" << rational.denominator << std::endl;
}

int main()
{
    Rational rational1 = createRational(2, 9);
    Rational rational2 = createRational(1, 3);

    std::cout << "Sum: ";
    printRational(sumRational(rational1, rational2));
    std::cout << "Subtraction: ";
    printRational(substractRational(rational1, rational2));
    std::cout << "Division: ";
    printRational(divideRational(rational1, rational2));
    std::cout << "Product: ";
    printRational(multiplyRational(rational1, rational2));
}
