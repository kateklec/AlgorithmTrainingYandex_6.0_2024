#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    std::vector<std::pair<int, int>> res;

    if (a > 0 && c > 0) {
        res.push_back({ b + 1, d + 1 });
    }

    if (b > 0 && d > 0) {
        res.push_back({ a + 1, c + 1 });
    }

    if (a > 0 && b > 0) {
        res.push_back({ std::max(a, b) + 1, 1 });
    }

    if (c > 0 && d > 0) {
        res.push_back({ 1, std::max(c, d) + 1 });
    }

    auto min_element = *std::min_element(res.begin(), res.end(), [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
        return (p1.first + p1.second) < (p2.first + p2.second);
        });

    std::cout << min_element.first << " " << min_element.second << std::endl;

    return 0;
}