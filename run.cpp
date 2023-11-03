#include "BigReal.cpp"
using namespace std;

int main()
{
    BigReal num1, num2;
    num1.setNum("2");
    num2.setNum("3");
    cout << num1;
    cout << num2;
    cout << num1 + num2 ;
    return 0;
}