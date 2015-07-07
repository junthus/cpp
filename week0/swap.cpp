#include <iostream>

using namespace std;

void SwapByRef(int * p1, int * p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void SwapByRef2(int &ref1, int &ref2)
{
    int tmp = ref1;
    ref1 = ref2;
    ref2 = tmp;
}

void FailSwap(int num1, int num2)
{
    int tmp = num1;
    num1 = num2;
    num2 = tmp;
}

int main()
{
    int val1 = 10;
    int val2 = 20;

    cout << "val1 : " << val1 << ", val2 : " << val2 << endl;

    SwapByRef(&val1, &val2);
    cout << "Swap with pointer" << endl;

    cout << "val1 : " << val1 << ", val2 : " << val2 << endl;
    
    SwapByRef2(val1, val2);
    cout << "Swap with reference" << endl;

    cout << "val1 : " << val1 << ", val2 : " << val2 << endl;

    FailSwap(val1, val2);
    cout << "Swap Fail(value)" << endl;

    cout << "val1 : " << val1 << ", val2 : " << val2 << endl;
    
    return 0;
    
}
