#include "BigReal.cpp"
using namespace std;

int main()
{
    BigReal num1,num2;
    num1.setNum("-0000012.345680913");
    num2.setNum("+1.11");
    cout<<num1 + num2;
    return 0;
}