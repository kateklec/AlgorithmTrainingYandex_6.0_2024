#include <iostream>
#include <string>

int main()
{
    int x1, y1, x2, y2, x, y;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
    std::string s = "";

    if (y > y2)
    s += "N";
    if (y < y1)
    s += "S";
    if (x < x1)
    s += "W";
    if (x > x2)
    s += "E";
    std::cout << s;

    return 0;
}