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

void BigReal::print_num()
{
    reverse(digits_d.begin(), digits_d.end());
    reverse(digits_r.begin(), digits_r.end());

    cout << sign;
    for (int num: digits_r)
        cout << num;
    
    cout << '.';

    for (int num: digits_d)
        cout << num;
    
}
