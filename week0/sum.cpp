#include <iostream>

using namespace std;

int main()
{
    
    int num = 0;

    for (int i = 0; i < 5; ++i) {
        int tmp = 0;
        cout << "Enter number(" << i+1 <<") : ";
        cin>>tmp;

        num += tmp;
    }

    cout <<"Sum: " << num << endl;
    
    return 0;
}
