#include <iostream>

using namespace std;

/*
    reference : 참조자
    할당된 하나의 메모리 공간에 둘 이상의 이름을 부여 -> 참조자는 자신이 참조하는 변수를 대신할 수 있는 또 하나의 이름
    참조자의 수에는 제한이 없으며, 참조자를 대상으로도 참조자를 선언할 수 있다.
 */

/*
    다음 선언은 유효하지 않다.

    int &ref;
    int &ref = NULL;
    int &ref = 20; -> 상수를 대상으로 참조자를 선언하는 것은 의미가 없다 (const int &ref = 20; 으로 임시변수로 만드는 것은 가능)

 */

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
