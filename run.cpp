#include <iostream>
#include "BigReal.cpp"
using namespace std;

int main()
{
    BigReal num;
    num.setNum("-0000012.345680913");
    num.print_num();
    return 0;
}