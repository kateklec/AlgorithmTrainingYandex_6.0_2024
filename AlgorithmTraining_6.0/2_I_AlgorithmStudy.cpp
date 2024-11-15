#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Algorithm {
    int index;
    int interest;
    int usefulness;

    template<typename T>
    static bool compare(const Algorithm& a, const Algorithm& b, T Algorithm::* primary, T Algorithm::* secondary) {
        if (a.*primary != b.*primary) return a.*primary < b.*primary;
        if (a.*secondary != b.*secondary) return a.*secondary < b.*secondary;
        return a.index > b.index;
    }

    bool operator<(const Algorithm& other) const {
        return compare(*this, other, &Algorithm::interest, &Algorithm::usefulness); // по умолчанию по интересности
    }
};

struct CompareUsefulness {
    bool operator()(const Algorithm& a, const Algorithm& b) const {
        return Algorithm::compare(a, b, &Algorithm::usefulness, &Algorithm::interest); // сравнение по полезности
    }
};

int main() {
    int n;
    std::cin >> n;

    std::vector<Algorithm> algorithms(n);
    for (int i = 0; i < n; i++) {
        std::cin >> algorithms[i].interest;
        algorithms[i].index = i + 1;
    }

    for (int i = 0; i < n; i++) {
        std::cin >> algorithms[i].usefulness;
    }

    std::vector<int> mood(n);
    for (int i = 0; i < n; i++) {
        std::cin >> mood[i];
    }

    std::priority_queue<Algorithm> interestQueue(algorithms.begin(), algorithms.end());
    std::priority_queue<Algorithm, std::vector<Algorithm>, CompareUsefulness> usefulnessQueue(algorithms.begin(), algorithms.end());

    std::vector<bool> studied(n, false); // Изучены ли алгоритмы
    std::vector<int> result;

    for (int i = 0; i < n; i++) {
        if (mood[i] == 1) {
            while (!usefulnessQueue.empty()) {
                Algorithm alg = usefulnessQueue.top();
                usefulnessQueue.pop();
                if (!studied[alg.index - 1]) {
                    result.push_back(alg.index);
                    studied[alg.index - 1] = true;
                    break;
                }
            }
        }
        else {
            while (!interestQueue.empty()) {
                Algorithm alg = interestQueue.top();
                interestQueue.pop();
                if (!studied[alg.index - 1]) {
                    result.push_back(alg.index);
                    studied[alg.index - 1] = true;
                    break;
                }
            }
        }
    }

    for (const int index : result) {
        std::cout << index << " ";
    }

    return 0;
}