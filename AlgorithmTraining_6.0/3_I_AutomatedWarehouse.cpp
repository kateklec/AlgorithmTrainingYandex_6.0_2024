#include <iostream>
#include <vector>
#include <algorithm>

struct Rover {
    int direction, arrival_time, index;
    Rover(int dir, int time, int idx) : direction(dir), arrival_time(time), index(idx) {}

    // перегружаем оператор < для сортировки роверов по возрастанию времени прибытия
    bool operator<(const Rover& other) const {
        return arrival_time < other.arrival_time;
    }
};

int constrain(int value, int min_val, int max_val) {
    return std::max(min_val, std::min(value, max_val));
}

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;

    // ограничиваем значения переменных в диапазоне от 0 до 3
    a = constrain(a, 1, 4) - 1;
    b = constrain(b, 1, 4) - 1;

    std::vector<Rover> crossroads[4];
    for (int i = 0; i < n; ++i) {
        int d, t;
        std::cin >> d >> t;
        // ограничиваем значение d диапазоном от 0 до 3, который соответствует четырем сторонам перекрестка в массиве crossroads
        d = constrain(d, 1, 4) - 1;
        t = constrain(t, 1, 100);
        crossroads[d].emplace_back(d, t, i);
    }

    for (int i = 0; i < 4; ++i) {
        std::sort(crossroads[i].begin(), crossroads[i].end());
    }

    std::vector<int> result_time(n, 0); //  вектор для хранения времени пересечения для каждого ровера
    std::vector<int> priority(4, 0); // приоритеты для четырех направлений перекрестка
    // устанавливаем повышенный приоритет для a и b
    priority[a] = 2;
    priority[b] = 2;

    for (int i = 0; i < 4; ++i) {
        // увеличиваем значение на 1, если выявлено совпадение с приоритетом соседнего направления
        if (priority[i] == priority[(i + 1) % 4]) {
            priority[i]++;
        }
    }

    std::vector<int> next_rover(4, 0); // индексы для отслеживания следующего ровера в каждом направлении
    for (int time = 1; time <= 1000; ++time) {
        bool moved = false;
        // обход приоритетов от 3 до 0
        for (int prio = 3; prio >= 0 && !moved; --prio) {
            // обход направлений перекрестка
            for (int i = 0; i < 4; ++i) {
                if (priority[i] == prio && next_rover[i] < crossroads[i].size() && crossroads[i][next_rover[i]].arrival_time <= time) {
                    result_time[crossroads[i][next_rover[i]++].index] = time;
                    moved = true; // останавливаем проверку других приоритетов в этом времени
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << result_time[i] << std::endl;
    }
    return 0;
}