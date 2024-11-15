#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int n, H;
    std::cin >> n >> H;

    std::vector<std::pair<int, int>> chairs(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> chairs[i].first; // высота стула
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> chairs[i].second; // ширина стула
    }

    // сортируем стулья по высоте
    std::sort(chairs.begin(), chairs.end());

    int left = 0;
    int right = chairs[n - 1].first - chairs[0].first; // разница между максимальной и минимальной высотой

    while (left < right) {
        int mid = (left + right) / 2;

        int current_width = 0; // суммарная ширина выбранных стульев
        int last_height = chairs[0].first; // высота последнего стула, который добавлен в текущий набор
        bool can_lie = false; // можно ли на выбранных стульях лежать

        for (int i = 0; i < n; ++i) {
            if (std::abs(chairs[i].first - last_height) <= mid) {
                current_width += chairs[i].second;
                last_height = chairs[i].first;
                if (current_width >= H) {
                    can_lie = true;
                    break;
                }
            }
            else {
                last_height = chairs[i].first;
                current_width = chairs[i].second;
            }
        }

        if (can_lie) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    std::cout << left << std::endl;
    return 0;
}