#include <iostream>
// using std::cin;
// using std::cout;
// using std::endl;

using namespace std;


namespace Test
{
    void testFunc()
    {
        //using namespace std;
        cout << "test" << endl;
    }
}

int main()
{
    using Test::testFunc;
    testFunc();
    return 0;
}
