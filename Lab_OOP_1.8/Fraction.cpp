/////////////////////////////////////////////////
// Fraction.cpp
#include "Fraction.h"
#include <iostream>

using namespace std;


Fraction::Fraction() : whole(), frac() {}


void Fraction::setWhole(const DigitString& value) {
    whole = value;
}

void Fraction::setFrac(unsigned short value)
{
    frac = value;
}

Fraction Fraction:: operator+(const Fraction& other) const
{
    Fraction result;
    result.whole = this->whole + other.getWhole();
    result.frac = this->frac + other.getFrac();

    if (result.frac >= 100) {
        result.whole = result.whole + DigitString("1");
        result.frac -= 100;
    }

    return result;
}

Fraction Fraction::operator-(const Fraction& other) const
{
    Fraction result;
    result.whole = this->whole - other.getWhole();
    result.frac = this->frac - other.getFrac();

    // Змінено перевірку
    if (result.frac < 0) {
        result.whole = result.whole - DigitString("1");
        result.frac += 100;
    }

    return result;
}


Fraction Fraction:: operator*(const Fraction& other) const
{
    Fraction result;
    result.whole = this->whole * other.getWhole();
    result.frac = this->frac * other.getFrac();

    if (result.frac >= 100) {
        result.whole = result.whole + DigitString("1");
        result.frac -= 100;
    }

    return result;
}

bool Fraction::operator==(const Fraction& other) const {
    if ((whole == other.whole) && (frac == other.frac))
    {
        cout << "Gooood" << endl;
        return true;
    }
    else
    {
        cout << "NOOO" << endl;
        return false;

    }

}

bool Fraction::operator!=(const Fraction& other) const {
    if ((whole != other.whole) && (frac != other.frac))
    {
        cout << "Gooood" << endl;
        return true;
    }
    else
    {
        cout << "NOOO" << endl;
        return false;

    }

}

bool Fraction::operator<(const Fraction& other) const {
    return (whole < other.whole) || ((whole == other.whole) && (frac < other.frac));
}


bool Fraction::operator>(const Fraction& other) const {
    return !(*this < other) && (*this != other);
}

bool Fraction::operator>=(const Fraction& other) const {
    return !(*this < other) && (*this == other);
}

bool Fraction::operator<=(const Fraction& other) const {
    return !(*this > other) && (*this == other);
}


void Fraction::Init()
{
    whole.Read();
    cout << "Enter fractional part: ";
    cin >> frac;
}

void Fraction::Read()
{
    cout << "Enter whole part: ";
    whole.Read();
    cout << "Enter fractional part: ";
    cin >> frac;
}

void Fraction::Display() const
{
    whole.Display();
    cout << ".";
    if (frac < 10) {
        cout << "0";  // Додайте "0" перед однозначною дробовою частиною.
    }
    cout << frac;
    cout << endl;
}

std::string Fraction::toString() const
{
    return whole.toString() + "." + to_string(frac);
}


Fraction:: DigitString::DigitString()
{

}

Fraction::DigitString::DigitString(const string& digits) : digits(digits)
{

}

Fraction::DigitString Fraction::DigitString:: operator+(const DigitString& other) const
{
    DigitString result;

    int carry = 0;

    for (int i = this->digits.size() - 1, j = other.digits.size() - 1; i >= 0 || j >= 0 || carry > 0; i--, j--)
    {
        int digit1 = (i >= 0) ? (this->digits[i] - '0') : 0;
        int digit2 = (j >= 0) ? (other.digits[j] - '0') : 0;

        int sum = digit1 + digit2 + carry;

        carry = sum / 10;
        sum %= 10;

        result.digits = to_string(sum) + result.digits;
    }

    return result;
}

Fraction::DigitString Fraction::DigitString::operator-(const DigitString& other) const
{
    DigitString result;

    // Check if the second operand is greater than the first one
    bool swapOperands = false;

    if (other.digits.size() > this->digits.size() ||
        (other.digits.size() == this->digits.size() && other.digits > this->digits))
    {
        swapOperands = true;
    }

    // Perform subtraction with the operands swapped if needed
    const DigitString& minuend = (swapOperands) ? other : *this;
    const DigitString& subtrahend = (swapOperands) ? *this : other;

    int borrow = 0;

    for (int i = minuend.digits.size() - 1, j = subtrahend.digits.size() - 1; i >= 0; i--, j--)
    {
        int digit1 = (i >= 0) ? (minuend.digits[i] - '0') : 0;
        int digit2 = (j >= 0) ? (subtrahend.digits[j] - '0') : 0;

        int diff = digit1 - digit2 - borrow;

        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        // Add digits to the result without leading zeros
        if (!(result.digits.empty() && diff == 0))
        {
            result.digits = to_string(diff) + result.digits;
        }
    }

    // Add negative sign if operands were swapped and the result is not zero
    if (swapOperands && !result.digits.empty() && result.digits != "0")
    {
        result.digits = '-' + result.digits;
    }

    // Handle borrow if it's still present
    if (borrow > 0)
    {
        cout << "NOOO" << endl;
    }

    return result;
}

Fraction::DigitString Fraction::DigitString::operator*(const DigitString& other) const
{
    DigitString result("0");

    for (int i = this->digits.size() - 1; i >= 0; i--)
    {
        int digit1 = this->digits[i] - '0';
        int carry = 0;

        DigitString partialResult;
        partialResult.digits = string(this->digits.size() - i - 1, '0');

        for (int j = other.digits.size() - 1; j >= 0; j--)
        {
            int digit2 = other.digits[j] - '0';
            int product = (digit1 * digit2) + carry;

            carry = product / 10;
            product %= 10;

            partialResult.digits = to_string(product) + partialResult.digits;
        }

        while (carry > 0)
        {
            partialResult.digits = to_string(carry % 10) + partialResult.digits;
            carry /= 10;
        }

        // Додавання partialResult до поточного результату
        result = result + partialResult;
    }

    return result;
}

Fraction::DigitString Fraction::DigitString::operator/(const DigitString& other) const
{
    DigitString quotient;
    DigitString remainder(*this);


    if (other.digits == "0") {
        cout << "Error: Division by zero\n";
        return quotient;
    }

    if (remainder < other) {
        quotient.digits = "0";
        return quotient;
    }


    while (remainder >= other) {
        int count = 0;


        while (remainder >= other) {
            remainder = remainder - other;
            count++;
        }


        quotient.digits += to_string(count);
    }


    while (!quotient.digits.empty() && quotient.digits[0] == '0') {
        quotient.digits.erase(0, 1);
    }


    if (quotient.digits.empty()) {
        quotient.digits = "0";
    }

    return quotient;
}



bool Fraction::DigitString::operator==(const DigitString& other) const {
    if (digits == other.digits)
    {
        cout << "Gooood" << endl;
        return true;
    }
    else
    {
        cout << "NOOO" << endl;
        return false;

    }
}

bool Fraction::DigitString:: operator!=(const DigitString& other) const
{
    if (digits != other.digits)
    {
        cout << "Gooood" << endl;
        return true;
    }
    else
    {
        cout << "NOOO" << endl;
        return false;

    }
}

bool Fraction::DigitString::operator<(const DigitString& other) const
{
    return (digits < other.digits) || ((digits == other.digits) && (digits < other.digits));
}


bool Fraction::DigitString::operator>(const DigitString& other) const
{
    return !(*this < other) && (*this != other);
}

bool Fraction::DigitString::operator>=(const DigitString& other) const {
    return !(*this < other) && (*this == other);
}

bool Fraction::DigitString::operator<=(const DigitString& other) const {
    return !(*this > other) && (*this == other);
}

void Fraction::DigitString::setDigits(const string& digits)
{
    this->digits = digits;
}

void Fraction::DigitString::Init()
{
    cout << "Enter digits: ";
    cin >> digits;
}

void Fraction::DigitString::Read()
{

    cin >> digits;
}

void Fraction::DigitString::Display() const
{
    cout << digits;
}

string Fraction::DigitString::toString() const
{
    return digits;
}