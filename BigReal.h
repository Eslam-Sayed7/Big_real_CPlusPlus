#ifndef BIGREAL_H
#define BIGREAL_H

#pragma once

#include <iostream>
#include <vector>
using namespace std;

class BigReal
{
private:
    void fill_zeros(BigReal&other) {

        int maxSize = max(digits_d.size(), other.digits_d.size());
        int minSize = min(digits_d.size(), other.digits_d.size());

        int numZeros = maxSize - minSize;

        if (other.digits_d.size() < digits_d.size())
            other.digits_d.insert(other.digits_d.begin(), numZeros, 0);
        else if (other.digits_d.size() > digits_d.size())
            digits_d.insert(digits_d.begin(), numZeros, 0);


        maxSize = max(digits_r.size(), other.digits_r.size());
        minSize = min(digits_r.size(), other.digits_r.size());
        numZeros = maxSize - minSize;

        if (other.digits_r.size() < digits_r.size()) {
            while (numZeros--)
                other.digits_r.push_back(0);

        } else if (other.digits_r.size() > digits_r.size()) {
            while (numZeros--)
                digits_r.push_back(0);
        }

    }

    void ninesComplemet(BigReal &b) {
        for (int i = 0; i < b.digits_r.size(); ++i) {
            b.digits_r[i] = 9 - b.digits_r[i];
        }
        for (int i = 0; i < b.digits_d.size(); ++i) {
            b.digits_d[i] = 9 - b.digits_d[i];

        }


    }

    BigReal add(BigReal other) {
        int maxSize = max(digits_d.size(), other.digits_d.size());
        BigReal res;
        int carry = 0;
        for (int i = 0; i < maxSize; ++i) {
            int sum = carry;
            if (i < digits_d.size())
                sum += digits_d[i];
            if (i < other.digits_d.size())
                sum += other.digits_d[i];
            res.digits_d.push_back(sum % 10);
            carry = sum / 10;
        }
        maxSize = max(digits_r.size(), other.digits_r.size());
        for (int i = 0; i < maxSize; ++i) {
            int sum = carry;
            if (i < digits_r.size())
                sum += digits_r[i];
            if (i < other.digits_r.size())
                sum += other.digits_r[i];
            res.digits_r.push_back(sum % 10);
            carry = sum / 10;
        }
        if (carry != 0) res.digits_r.push_back(carry);
        return res;
    }
    bool isValidReal(string realNumber); // True if correct real

    vector<int> digits_d;
    vector<int> digits_r;
    char sign;
    
    BigReal compare_two_values(BigReal num1, BigReal num2);  // return Bigreal that has a smallest value (independent sign)
   // bool isValidReal(string realNumber); // True if correct real
public:
    BigReal(double realNumber = 0.0); // Default constructor
    BigReal(string realNumber);       // Initialize from string
    BigReal(const BigReal &other);    // Copy constructor

    void setNum(string realNumber);
    int SIZE();
    

    BigReal operator=(BigReal other); // Assignment operator
    BigReal operator+(BigReal &other);
    BigReal operator-(BigReal &other);

    bool operator<(BigReal anotherReal);
    bool operator>(BigReal anotherReal);
    bool operator==(BigReal anotherReal);
    friend ostream &operator<<(ostream &out, BigReal num);
};

#endif