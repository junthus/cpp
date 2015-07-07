#include <iostream>
#include <fstream>
#include <map>

using namespace std;


int main(int argc, char* argv[])
{
    typedef map<string, int> freq_map;

    freq_map freq;
    string word;
    int maxFreq;
    string mostFreqItem;

    ifstream infile(argv[1]);

    if (!infile.is_open()) {
        cerr << "INVALID_FILE_NAME";
    }

    while(!infile.eof() && infile >> word) {
        int f = freq[word]++;

        if (f > maxFreq) {
            maxFreq = f;
            mostFreqItem = word;
        }
    }

    cout << mostFreqItem << endl;

    return 0;
}