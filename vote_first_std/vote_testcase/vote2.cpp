#include <iostream>
#include <fstream>
// #include <chrono>
// #include "StopWatch.H"

using namespace std;
// using namespace std::chrono;

struct WORD
{
    char* str;
    int count;
};

int max_of_words = 10;
int num_of_words = 0;
int max_freq = 0;
WORD *words = NULL;

void CountWord(char *s);
int FindWord(const char *s);
void Realloc();
void DeleteAll();
void ShowMaxFreqItem();

int main(int argc, char* argv[])
{
    // StopWatch::start();

    words = new WORD[max_of_words];
    memset(words, 0, sizeof(WORD) * max_of_words);

    ifstream infile(argv[1]);
    char buffer[128];

    if (!infile.is_open()) {
        cerr << "INVALID_FILE";
    }

    while(!infile.eof() && infile >> buffer) {
        CountWord(buffer);
    }

    ShowMaxFreqItem();

    DeleteAll();

    // StopWatch::stop();
    // cout << StopWatch::getMilliSeconds();

    return 0;
}

void ShowMaxFreqItem() {
    for (int i = 0; i < num_of_words; ++i) {
        if (words[i].count == max_freq) {
            cout << words[i].str << " (" << max_freq << ")" << endl;
        }
    }
}

void CountWord(char *s)
{
    int idx = FindWord(s);
    int currFreq = 1;

    if (idx == -1) {
        words[num_of_words].str = new char[strlen(s) + 1];
        // words[num_of_words].str = s;
        strcpy(words[num_of_words].str, s);
        words[num_of_words].count = 1;
        num_of_words++;

        if (num_of_words == max_of_words) {
            Realloc();
        }
    } else {
        currFreq = ++words[idx].count;
    }

    if (currFreq > max_freq) {
        max_freq = currFreq;
    }
}

int FindWord(const char *s)
{
    for (int i = 0; i < num_of_words; ++i) {
        if (strcmp(words[i].str, s) == 0) {
            return i;
        }
    }

    return -1;
}

void Realloc()
{
    max_of_words += 10;
    WORD *tmp = words;

    words = new WORD[max_of_words];
    memcpy(words, tmp, sizeof(WORD) * num_of_words);

    delete []tmp;
}

void DeleteAll()
{
    for (int i = 0; i < num_of_words; ++i) {
        delete []words[i].str;
    }

    delete []words;
}