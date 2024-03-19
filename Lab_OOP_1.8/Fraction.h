////////////////////////////////////////////////////////
// Fraction.h
#pragma once
#include <string>

using namespace std;

class Fraction
{
public:
    class DigitString
    {
    private:
        string digits;

    public:
        DigitString();
        DigitString(const string& digits);

        // Арифметичні операції
        DigitString operator+(const DigitString& other) const;
        DigitString operator-(const DigitString& other) const;
        DigitString operator*(const DigitString& other) const;
        DigitString operator/(const DigitString& other) const;


        // Операції порівняння
        bool operator==(const DigitString& other) const;
        bool operator!=(const DigitString& other) const;
        bool operator<(const DigitString& other) const;
        bool operator>(const DigitString& other) const;
        bool operator>=(const DigitString& other) const;
        bool operator<=(const DigitString& other) const;


        const string& getDigits() const { return digits; };
        void setDigits(const string& digits);

        void Init();
        void Read();
        void Display() const;
        string toString() const;
    };


private:
    DigitString whole;
    unsigned short frac;

public:
    Fraction();

    Fraction operator+ (const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;


    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;


    const DigitString& getWhole() const { return whole; };
    unsigned short getFrac() const { return frac; };

    void setWhole(const DigitString& value);
    void setFrac(unsigned short value);


    void Init();
    void Read();
    void Display() const;
    string toString() const;
};