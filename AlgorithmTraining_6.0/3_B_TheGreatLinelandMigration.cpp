#include <iostream>
#include <vector>
#include <string>

int main() {
    int countOfCities;
    std::cin >> countOfCities;

    // средняя цена проживания в каждом городе
    std::vector<int> averagePrices(countOfCities);
    for (int i = 0; i < countOfCities; ++i) {
        std::cin >> averagePrices[i];
    }

    // индексы городов, которые могут быть перемещены
    std::vector<int> relocationList;
    // по умолчанию заполнение "-1" для всех городов
    std::vector<std::string> result(countOfCities, "-1");

    for (int i = 0; i < countOfCities; ++i) {
        while (!relocationList.empty() && averagePrices[relocationList.back()] > averagePrices[i]) {
            int index = relocationList.back();
            relocationList.pop_back();
            result[index] = std::to_string(i);
        }
        relocationList.push_back(i);
    }

    for (const auto& el : result) {
        std::cout << el << ' ';
    }

    return 0;
}