#ifndef BIGREAL_H
#define BIGREAL_H

#pragma once

#include <iostream>
#include <vector>
using namespace std;

class BigReal
{
private:
    bool isValidReal(string realNumber); // True if correct real

    vector<int> digits_d;
    vector<int> digits_r;
    char sign;
    
    BigReal compare_two_values(BigReal num1, BigReal num2);  // return Bigreal that has a smallest value (independent sign)
    bool isValidReal(string realNumber); // True if correct real
public:
    BigReal(double realNumber = 0.0); // Default constructor
    BigReal(string realNumber);       // Initialize from string
    BigReal(const BigReal &other);    // Copy constructor

    void setNum(string realNumber);
    int SIZE();
    

    BigReal &operator=(BigReal &other); // Assignment operator
    BigReal operator+(BigReal &other);
    BigReal operator-(BigReal &other);

    bool operator<(BigReal anotherReal);
    bool operator>(BigReal anotherReal);
    bool operator==(BigReal anotherReal);
    friend ostream &operator<<(ostream &out, BigReal num);
};

#endif