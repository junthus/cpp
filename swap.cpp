#include <iostream>

void swap (int* a, int* b)
{
	 int tmp = *a;
	 *a = *b;
	 *b = tmp;
}


int main ()
{
		int A = 1;
		int B = 2;

		swap(&A, &B);
		
		std::cout << A << " , " << B << std::endl;
		return 0;
}

