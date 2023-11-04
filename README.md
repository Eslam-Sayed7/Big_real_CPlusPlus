# Big_real_CPlusPlus
##  Breakdown algorithms of +, -, <, > and isValidReal
### isValidReal
`bool BigReal::isValidReal(string realNumber)
{
    bool one_decimal_dot{false}; // COMMENT(1) flag to catch if more than one dot
        
    // COMMENT(2) handling 1st digit to equal (number or dot or a sign(+ or -))
    if (realNumber[0] == '+' || realNumber[0] == '-' || realNumber[0] == '.' || (realNumber[0] >= '0' && realNumber[0] <= '9')  ) { 
        
	// COMMENT(3) checking number digits after sign bit (if exist)
        for (int i = 1; i < realNumber.size(); i++) { 
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
`
-	COMMENT(1) One decimal dot  is a flag to make sure the no more than one dot in the number.

-	COMMENT(2) handling first digit to equal a sign character (+ or -) or (.) or (a number).

-	COMMENT(3) loop from second character index  1 in the number to check if the rest of the BigReal contains an ordinary number (0 - 9) or if it is a dot is it only one or more , therefore inValidReal.



### < Operator

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

-	COMMENT(1) if two sign is different, than return true if the first number has the sign(-) .

-	COMMENT(2) i made a utility function(compare two values) to return a Bigreal that has a smallest value(not care about a sign).

-	COMMENT(3) if two sign is (+,+), then return true if the first num has a smallest value compared with the second num.

-	COMMENT(5) if two sign is (-,-), then return true if the first num has a Highest value compared with the second num.

### > Operator

bool BigReal::operator>(BigReal anotherReal)
{
    if (*this < anotherReal || *this == anotherReal)
        return false;
    return true;
}

-	COMMENT(1) if !(num1 < num2 || num1 == num2), then num1 > num2.
