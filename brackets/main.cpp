#include <iostream>
#include <string>
#include <cstdlib>
#include <stack>
#include <utility>

int convert (int itm) {
    int ret;
    switch (itm) {
        case '(':
            ret = 1;
            break;
        case '{':
            ret = 2;
            break;
        case '[':
            ret = 3;
            break;
        case ')':
            ret = -1;
            break;
        case '}':
            ret = -2;
            break;
        case ']':
            ret = -3;
            break;
        default:
            ret = 0;
            break;
    }

    return ret;
}

void throwException () {
    std::cout << 0 << std::endl;
}

int main() {
    std::string line;

    std::getline(std::cin, line);
    int numOfTest = std::atoi(line.c_str());
    // int numOfTest = 2;

    while(numOfTest-- > 0) {
        std::stack<std::pair<int,int> > stk;
        int ret = 0;

        std::getline(std::cin, line);

        for (int i = 0; i < line.size(); ++i) {
            int which = convert(line[i]);
            std::pair <int,int> itm;

            if (which > 0) {
                itm.first = which;
                itm.second = i;
                stk.push(itm);
            } else if (which < 0) {
                itm = stk.top();

                if (itm.first == -which) {
                    if (itm.second == i-1) { //+
                        ret += itm.first;
                    } else { //*
                        ret *= itm.first;
                    }

                    stk.pop();
                } else {
                    throwException();
                    continue;
                }
            } else {
                throwException();
                continue;
            }
        }

        std::cout << ret % 100000000 << std::endl;
    }

	return 0;
}
