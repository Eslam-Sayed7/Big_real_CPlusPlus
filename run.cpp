#include "BigReal.cpp"
using namespace std;

int main()
{
    BigReal num1, num2,res;
    num1.setNum("11");
    num2.setNum("11");

    res = num1 + num2;
    cout<<res;
    return 0;
}