#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

int main() {
    std::string expr;
    std::getline(std::cin, expr);

    std::vector<int> stack;
    std::istringstream iss(expr);
    std::string el;

    while (iss >> el) {
        // проверка, что это число или отрицательное число
        if (isdigit(el[0]) || (el[0] == '-' && el.size() > 1 && isdigit(el[1]))) {
            // преобразование числа в строке в целое число и добавление в стэк
            stack.push_back(std::stoll(el));
        }
        else {
            int right = stack.back(); 
            stack.pop_back();
            int left = stack.back(); 
            stack.pop_back();

            if (el == "+") {
                stack.push_back(left + right);
            }
            else if (el == "-") {
                stack.push_back(left - right);
            }
            else if (el == "*") {
                stack.push_back(left * right);
            }
            else if (el == "/") {
                if (right == 0) { // проверка деления на 0
                    return 0;
                }
                stack.push_back(left / right);
            }
        }
    }

    std::cout << stack.back() << std::endl;

    return 0;
}