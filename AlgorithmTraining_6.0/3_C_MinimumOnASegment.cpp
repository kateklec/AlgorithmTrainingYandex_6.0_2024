#include <iostream>
#include <vector>
#include <deque>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::deque<int> dq;
    for (int i = 0; i < k; i++) {
        dq.push_back(arr[i]);
        while (dq.size() > 1 && dq.back() < dq[dq.size() - 2]) {
            dq.erase(dq.end() - 2);
        }
    }

    std::cout << dq.front() << std::endl;

    for (int i = k; i < n; i++) {
        // если есть элемент, который выходит из окна, удаляем его
        if (dq.front() == arr[i - k] || dq.size() > k) {
            dq.pop_front();
        }
        dq.push_back(arr[i]);
        while (dq.size() > 1 && dq.back() < dq[dq.size() - 2]) {
            dq.erase(dq.end() - 2);
        }
        std::cout << dq.front() << std::endl;
    }

    return 0;
}