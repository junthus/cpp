#include <iostream>
#include <fstream>

using namespace std;

// struct WORD
// {
//     char* str;
//     int count;
// };

// int max_of_words = 10;
// int num_of_words = 0;
// WORD *word = NULL;

//파일 읽기
//빈도 맵 만들기 std::map 타입 찾아보기
//가장 큰 count 찾기

char inputString[10];

int main()
{
    // words = new WORD[max_of_words];
    // memset(words, 0, sizeof(WORD) * max_of_words);

    // char buffer[128];

	ifstream inFile("./vote_testcase/1.inp");

	while (!inFile.eof()) {
		inFile.getline(inputString, 100);
		cout << inputString << endl;
	}

	inFile.close();

	return 0;
}

// int find(const char *s)
// {
//     for (int i = 0; i < num_of_words)
// }
