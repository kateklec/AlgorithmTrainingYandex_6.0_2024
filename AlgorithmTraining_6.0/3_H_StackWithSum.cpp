#include <iostream>
#include <stack>
#include <sstream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::stack<int> stack;
    std::vector<long long> stackSUM = {0};
    std::vector<long long> res;

    for (int i = 0; i < n; ++i) {
        std::string operation;
        std::cin >> operation;

        if (operation[0] == '+') {
            int x;
            std::stringstream(operation.substr(1)) >> x;
            stack.push(x);
            stackSUM.push_back(stackSUM.back() + x);
        }
        else if (operation[0] == '-') {
            if (!stack.empty()) {
                res.push_back(stack.top());
                stack.pop();
                stackSUM.pop_back();
            }
        }
        else if (operation[0] == '?') {
            int k;
            std::stringstream(operation.substr(1)) >> k;
            long long sum = stackSUM.back() - stackSUM[stackSUM.size() - k - 1];
            res.push_back(sum);
        }
    }

    for (const long long& el : res) {
        std::cout << el << std::endl;
    }

    return 0;
}