#include <iostream>
#include <algorithm>
#include <vector>
#include "BigReal.h"

bool BigReal::isValidReal(string realNumber)
{
    bool one_decimal_dot{false}; // flag to catch if more than one dot
        
        // handling 1st digit to equal (number or dot or a sign(+ or -))
    if (realNumber[0] == '+' || realNumber[0] == '-' || realNumber[0] == '.' || (realNumber[0] >= '0' && realNumber[0] <= '9')  ) { 
        
        for (int i = 1; i < realNumber.size(); i++) { // checking number digits after sign bit (if exist)
            if ((realNumber[i] <='9' && realNumber[i] >= '0')) {
                continue;
            } else if (realNumber[i] == '.' && !one_decimal_dot) {
                one_decimal_dot = true;
            } else {
                return false;
            }   
        }
        return true;
    }
    return false;
}

BigReal::BigReal(double realNumber)
{
    string real_number_str = to_string(realNumber);
    setNum(real_number_str);
}

BigReal::BigReal(string realNumber)
{
    setNum(realNumber);
}

BigReal::BigReal(const BigReal &other)
{
    this->digits_d = other.digits_d;
    this->digits_r = other.digits_r;
    this->sign = other.sign;
}

BigReal BigReal::compare_two_values(BigReal num1, BigReal num2)
{
    if (num1.digits_r.size() < num2.digits_r.size())
        return num1;
    else if (num1.digits_r.size() > num2.digits_r.size())
        return num2;
    
    if (num1.digits_d.size() < num2.digits_d.size())
        return num1;
    else if (num1.digits_d.size() > num2.digits_d.size())
        return num2;
    
    for (int i = num1.digits_r.size()-1 ; i >= 0 ;--i)
        if (num1.digits_r[i] > num2.digits_r[i])
            return num2;
    
    for (int i = num1.digits_d.size()-1 ; i >= 0 ;--i)
        if (num1.digits_d[i] > num2.digits_d[i])
            return num2;
    
    return num1;
}

void BigReal::setNum(string realNumber)
{
    if(!isValidReal(realNumber))
    {
        cout << "this number is not valid. Try again!!\n";
        return;
    }

    // make sure that it is clear before filling digits
    digits_d.clear(); 
    digits_r.clear();
    sign = realNumber[0];
    bool flag = false;
    
    for (int idx = realNumber.size()-1; idx >= 1  ; --idx)
    {
        if (realNumber[idx] == '.')
        {
            flag = true;
            continue;
        }

        int digit = realNumber[idx] - '0';

        if (!flag)
            digits_d.push_back(digit);
        else
            digits_r.push_back(digit);
    }
    
    while(!digits_r.empty() && digits_r.back() == 0)
        digits_r.pop_back();
}

int BigReal::SIZE()
{
    return (digits_d.size() + digits_r.size());
}

BigReal &BigReal::operator=(BigReal &other)
{
    if (this == &other)
        return *this;
    this->digits_r.clear();    
    this->digits_d.clear();
    
    this->sign = other.sign;

    for (int i = 0; i < other.digits_r.size(); ++i)
        digits_r.push_back(other.digits_r[i]);

    for (int i = 0; i < other.digits_d.size(); ++i)
        digits_d.push_back(other.digits_d[i]);

    return *this;
}

bool BigReal::operator<(BigReal anotherReal)
{
    if (sign == '+' && anotherReal.sign == '-')
        return false;
    else if (sign == '-' && anotherReal.sign == '+')
        return true;

    if (*this == anotherReal)
        return false;
    
    if (compare_two_values(*this, anotherReal) == *this)   // the value of *this is smallest
    {
        if (sign == '+')
            return true;
        else
            return false;
    }
    else   // the value of anotherReal is smallest
    {
        if (sign == '+')
            return false;
        else
            return true;
    } 

    return true;
}

bool BigReal::operator>(BigReal anotherReal)
{
    if (*this < anotherReal || *this == anotherReal)
        return false;
    return true;
}

bool BigReal::operator==(BigReal anotherReal)
{
    if (sign != anotherReal.sign)
        return false;
    if (digits_r.size() != anotherReal.digits_r.size())
        return false;
    if (digits_d.size() != anotherReal.digits_d.size())
        return false;

    for (int i = 0 ; i < digits_r.size() ; ++i)
        if (digits_r[i] != anotherReal.digits_r[i])
            return false;
    
    for (int i = 0 ; i < digits_d.size() ; ++i)
        if (digits_d[i] != anotherReal.digits_d[i])
            return false;
    
    return true;
}

ostream &operator<<(ostream &out, BigReal num)
{
    if (num.sign == '-')
        out << '-';
    
    for (int i = num.digits_r.size()-1 ; i >= 0; --i)
        out << num.digits_r[i];
    for (int i = num.digits_d.size()-1 ; i >= 0; --i)
    {
        if (i == num.digits_d.size()-1)
            out << '.';
        out << num.digits_d[i];
    }
    return out;
}
