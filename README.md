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
