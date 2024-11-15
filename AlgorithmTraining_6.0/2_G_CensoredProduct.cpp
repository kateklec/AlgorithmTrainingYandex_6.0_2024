#include <iostream>
#include <string>
#include <algorithm>

int main() {

    long long n, c;
    std::cin >> n >> c;
    std::string s;
    std::cin >> s;

    long long max_length = 0, left = 0, pair_ab = 0, count_a = 0, count_b = 0;

    for (long long right = 0; right < n; ++right) {

        if (s[right] == 'a') {
            count_a++;
        }
        else if (s[right] == 'b') {
            pair_ab += count_a;
            count_b++;
        }

        while (pair_ab > c) {
            if (s[left] == 'a') {
                pair_ab -= count_b;
                count_a--;
            }
            else if (s[left] == 'b') {
                count_b--;
            }
            left++;
        }

        max_length = std::max(max_length, right - left + 1);
    }

    std::cout << max_length;
    return 0;
}