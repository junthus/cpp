#include <iostream>
//inputs, outputs, cint/out(console in/outputs)
//collection of tools that are found at the library called iostream

using namespace std; //std::cout << "Hello, World!\n";

int main()
{

    int val1;

    cout << "Hello you sexy world,"
            "I just wrote \nmy first cpp program using xcode!!!!";
    cout << endl; //compiler: add a return line right here

    cout << "Enter a number: " ;
    cin >> val1;

    cout << "The number is " << val1 << endl;

    return 0;
}

//int main(int argc, const char * argv[]) {
//
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}
