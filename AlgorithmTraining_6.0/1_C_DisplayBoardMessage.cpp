#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

void removeDuplicateRows(std::vector<std::string>& s);
void removeDuplicateColumns(std::vector<std::string>& s);
void trimEmptyRows(std::vector<std::string>& s);
void trimEmptyColumns(std::vector<std::string>& s);
void detectCharacter(const std::vector<std::string>& s);

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> s(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
    }

    removeDuplicateRows(s);
    removeDuplicateColumns(s);
    trimEmptyRows(s);
    trimEmptyColumns(s);
    detectCharacter(s);

    return 0;
}

void removeDuplicateRows(std::vector<std::string>& s) {
    s.erase(std::unique(s.begin(), s.end()), s.end());
}

void removeDuplicateColumns(std::vector<std::string>& s) {
    int i = 0;
    while (i + 1 < s[0].size()) {
        // Проверяем, все ли элементы в столбце i равны элементам в столбце i + 1
        bool duplicate = std::all_of(s.begin(), s.end(), [&](const std::string& row) {
            return row[i] == row[i + 1];
            });

        if (duplicate) {
            // Если дубликаты, удаляем столбец i
            for (auto& row : s) {
                row.erase(row.begin() + i);
            }
        }
        else {
            ++i;
        }
    }
}

void trimEmptyRows(std::vector<std::string>& s) {
    // Убираем строки сверху, заполненные точками
    while (!s.empty() && std::set<char>(s[0].begin(), s[0].end()) == std::set<char>{'.'}) {
        s.erase(s.begin());
    }

    // Убираем строки снизу, заполненные точками
    while (!s.empty() && std::set<char>(s.back().begin(), s.back().end()) == std::set<char>{'.'}) {
        s.pop_back();
    }
}

void trimEmptyColumns(std::vector<std::string>& s) {
    // Убираем столбцы слева, заполненные точками
    while (!s.empty() && !s[0].empty() && std::all_of(s.begin(), s.end(), [](const std::string& row) {
        return row[0] == '.';
        })) {
        for (auto& row : s) {
            row.erase(row.begin());
        }
    }

    // Убираем столбцы справа, заполненные точками
    while (!s.empty() && !s[0].empty() && std::all_of(s.begin(), s.end(), [](const std::string& row) {
        return row.back() == '.';
        })) {
        for (auto& row : s) {
            row.pop_back();
        }
    }
}

void detectCharacter(const std::vector<std::string>& s) {
    if (s == std::vector<std::string>{"#"}) {
        std::cout << "I" << std::endl;
    }
    else if (s == std::vector<std::string>{"###", "#.#", "###"}) {
        std::cout << "O" << std::endl;
    }
    else if (s == std::vector<std::string>{"##", "#.", "##"}) {
        std::cout << "C" << std::endl;
    }
    else if (s == std::vector<std::string>{"#.", "##"}) {
        std::cout << "L" << std::endl;
    }
    else if (s == std::vector<std::string>{"#.#", "###", "#.#"}) {
        std::cout << "H" << std::endl;
    }
    else if (s == std::vector<std::string>{"###", "#.#", "###", "#.."}) {
        std::cout << "P" << std::endl;
    }
    else {
        std::cout << "X" << std::endl;
    }
}