#include <iostream>
#include <string>
#include <vector>

char pairBracket(char el);
std::string minPSP(int n, const std::string& w, const std::string& s);

int main() {
    int n;
    std::string w, s;

    std::cin >> n >> w >> s;

    std::string result = minPSP(n, w, s);

    if (!result.empty()) {
        std::cout << result;
    }

    return 0;
}

char pairBracket(char el) {
    if (el == '(') {
        return ')';
    }
    else if (el == '[') {
        return ']';
    }
    else {
        return '?';
    }
}

std::string minPSP(int n, const std::string& w, const std::string& s) {
    std::vector<char> stack(n);
    int stackIndex = 0;

    for (char ch : s) {
        // если ch открывающая скобка, добавляем в stack
        if (pairBracket(ch) != '?') {
            stack[stackIndex] = ch;
            ++stackIndex;
        }
        // если ch закрывающая скобка, проверяем, соответствует ли она верхней открывающей скобке из стека
        else {
            if (stackIndex > 0 && pairBracket(stack[stackIndex - 1]) == ch) {
                --stackIndex;
            }
            else {
                return "";
            }
        }
    }

    std::string result = s;
    while (result.length() < n) {
        bool done = false;
        for (int i = 0; i < 4; ++i) {
            if (stackIndex > 0 && pairBracket(stack[stackIndex - 1]) == w[i]) {
                result += w[i];
                --stackIndex;
                done = true;
                break;
            }
            if (n - result.length() - 1 >= stackIndex + 1 && pairBracket(w[i]) != '?') {
                result += w[i];
                stack[stackIndex++] = w[i];
                done = true;
                break;
            }
        }
        if (!done) {
            return "";
        }
    }

    return result;
}