#include <iostream>

using namespace std;

int main()
{
    int num1 = 5;

    int *ptr = &num1;
    int &num2 = num1;

    cout << "*ptr = &num1 : " << ptr << endl;
    cout << "&num2 = num1 : " << num2 << endl;

    cout << "-------------------------" << endl;

    int num = 12;
    int *p = &num;
    int **dp = &p;

    int &ref = num;
    int *(&pref) = p;
    int **(&dpref) = dp;

    cout << ref << endl;
    cout << *pref << endl;
    cout << **dpref << endl;

    return 0;
}
