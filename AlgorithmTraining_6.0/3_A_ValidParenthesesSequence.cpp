#include <iostream>
#include <vector>
#include <string>

int main() {
    std::string str;
    std::cin >> str;

    std::vector<char> stack;

    for (char c : str) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push_back(c);
        }
        else {
            if (stack.empty()) {
                std::cout << "no";
                return 0;
            }
            char top = stack.back();
            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                std::cout << "no";
                return 0;
            }
            stack.pop_back();
        }
    }

    if (stack.empty()) {
        std::cout << "yes";
    }
    else {
        std::cout << "no";
    }

    return 0;
}