#include <iostream>

using namespace std;

int& RefRetFuncOne(int &ref) // 반환형이 참조자
{
	ref++;
	return ref;
}

int RefRetFuncTwo(int &ref) // 반환형이 int
{
    ref++;
    return ref; // 참조자를 반환하지만 반환형이 int 라서 값이 반환된다.
}

int CallByReferenceWithConst(const int &ref) {
    // 함수 내에서 참조자를 통한 값 변경을 진행하지 않을 경우 참조자를 const로 선언해서
    // 함수의 원형만 봐도 값의 변경이 이뤄지지 않음을 알 수 있도록.
}

int Adder(const int &num1, const int &num2)
{
    // const 참조자의 상수참조 (임시변수 공간을 만든다.)
    // Adder(4, 5) <- 형태로 호출이 가능하다.
    return num1 + num2;
}

int main()
{
    //RefRetFuncOne - 참조 체인
    //&ref = num1;
    //&num2 = ref;
    int num1 = 1;
    int &num2 = RefRetFuncOne(num1);

	num1++;
	num2++;

	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;

    //RefRetFuncOne - 동일한 구조에서 참조 체인을 끊을 수 있다.
    // 참조형으로 반환이 되지만 일반변수로 반환값을 지정할 수 있다.
    // 이 때, num4 는 num3 과 다른 메모리 공간을 사용한다.
    int num3 = 1;
    int num4 = RefRetFuncOne(num3);

    num3 += 1;
    num4 += 100;

    cout << "num3: " << num3 << endl;
	cout << "num4: " << num4 << endl;

    //RefRetFuncTwo - int 값이 반환된다.
    int num5 = 1;
    int num6 = RefRetFuncTwo(num5);

    num5 += 1;
    num6 += 100;

    cout << "num5: " << num5 << endl;
    cout << "num6: " << num6 << endl;

    return 0;
}
