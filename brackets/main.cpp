#include <iostream>
#include <string>
#include <cstdlib>
#include <stack>
#include <utility>

static int MUL = '*';
static int ADD = '+';

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

bool isOpenBracket(int which) {
    return which > 0;
}

bool isPair(int a, int b) {
    return a == b;
}

int main() {
    std::string line;

    std::getline(std::cin, line);
    int numOfTest = std::atoi(line.c_str());
    // int numOfTest = 2;

    while(numOfTest-- > 0) {
        std::stack<std::pair<int,int> > addStack;
        std::stack<std::pair<int,int> > multiplyStack;

        int ret = 0;
        int tmp = 0;
        int count = 0;
        int before = 0;

        std::getline(std::cin, line);

        for (int i = 0; i < line.size(); ++i) {
            int which = convert(line[i]);

            std::pair <int,int> itm;

            if (isOpenBracket(which)) {
                itm.first = which;
                itm.second = i;

                if (isOpenBracket(before)) {
                    multiplyStack.push(itm);
                    count++;
                } else if (!isOpenBracket(before)) {
                    addStack.push(itm);
                }

            } else {
                if (count == 0) {
                    if (isPair(before, -which)) {
                        itm = addStack.top();
                        ret += itm.first;
                        addStack.pop();
                    } else {
                        ret = -1;
                        break;
                    }
                } else {
                    if (isPair(before, -which)) {
                        itm = addStack.top();
                        tmp += itm.first;
                        addStack.pop();
                    } else {
                        itm = multiplyStack.top();
                        tmp *= itm.first;
                        multiplyStack.pop();
                        count--;

                        if (count == 0) {
                            ret += tmp;
                        }
                    }

                    if (itm.first !=  -which) {
            std::cout << "MUL " << itm.first << " , " << -which << " at: " << i << std::endl;
                        ret = -1;
                        break;
                    }
                }
            }
            std::cout << "    RET " << ret << std::endl;

            before = which;
        }


        if (ret < 0) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << ret % 100000000 << std::endl;
        }

    }

	return 0;
}
