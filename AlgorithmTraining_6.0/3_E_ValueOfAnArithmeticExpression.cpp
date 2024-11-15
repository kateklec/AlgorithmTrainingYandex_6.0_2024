#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>

size_t pos = 0;
std::string expr;

void skipSpace();
int64_t parseNumber(bool& valid);
int64_t parseParens(bool& valid);
int64_t parseMulDiv(bool& valid);
int64_t parseAddSub(bool& valid);

int main() {
    std::getline(std::cin, expr);
    pos = 0;
    bool valid = true;

    int64_t result = parseAddSub(valid);

    if (valid && pos == expr.size()) {
        std::cout << result << std::endl;
    }
    else {
        std::cout << "WRONG" << std::endl;
    }

    return 0;
}

void skipSpace() {
    while (pos < expr.size() && std::isspace(expr[pos])) {
        ++pos;
    }
}

int64_t parseNumber(bool& valid) {
    skipSpace();
    int64_t result = 0;
    bool negative = false;

    // определение знака числа
    if (expr[pos] == '-') {
        negative = true;
        ++pos;
    }

    // проверка, является ли текущий символ цифрой
    if (pos >= expr.size() || !std::isdigit(expr[pos])) {
        valid = false;
        return 0;
    }

    // сборка числа
    while (pos < expr.size() && std::isdigit(expr[pos])) {
        result = result * 10 + (expr[pos] - '0');
        ++pos;
    }

    return negative ? -result : result;
}

int64_t parseParens(bool& valid) {
    skipSpace();
    if (expr[pos] == '(') {
        ++pos;
        int64_t result = parseAddSub(valid);
        skipSpace();
        if (pos >= expr.size() || expr[pos] != ')') {
            valid = false;
            return 0;
        }
        ++pos;
        return result;
    }
    else {
        return parseNumber(valid);
    }
}

int64_t parseMulDiv(bool& valid) {
    int64_t result = parseParens(valid);
    if (!valid) return 0;

    while (true) {
        skipSpace();
        if (pos >= expr.size()) return result;

        char operand = expr[pos];
        if (operand != '*' && operand != '/') break;
        ++pos;

        int64_t nextElement = parseParens(valid);
        if (!valid) return 0;

        if (operand == '*') {
            result *= nextElement;
        }
        else {
            if (nextElement == 0) {
                valid = false;  // ошибка деления на 0
                return 0;
            }
            result /= nextElement;
        }
    }
    return result;
}

int64_t parseAddSub(bool& valid) {
    int64_t result = parseMulDiv(valid);
    if (!valid) return 0;

    while (true) {
        skipSpace();
        if (pos >= expr.size()) return result;

        char operand = expr[pos];
        if (operand != '+' && operand != '-') break;
        ++pos;

        int64_t nextTerm = parseMulDiv(valid);
        if (!valid) return 0;

        if (operand == '+') {
            result += nextTerm;
        }
        else {
            result -= nextTerm;
        }
    }
    return result;
}