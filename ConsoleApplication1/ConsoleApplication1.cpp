#include "AlphaLevelFuzzy.hpp"
#include <iostream>

int main() {
    double centerX = 2; // Средняя точка первой параболы
    double spread = 1;  // Разброс первой параболы

    AlphaLevelFuzzy fuzzy;
    std::cout << "1 parabola" << std::endl;
    fuzzy.printParabolaPoints(centerX, spread);

    double centerX2 = 3; // Средняя точка второй параболы
    double spread2 = 1;  // Разброс второй параболы

    std::cout << "2 parabola" << std::endl;
    fuzzy.printParabolaPoints(centerX2, spread2);

    std::cout << "SUM parabola" << std::endl;
    fuzzy.printParabolaPlus(centerX, spread, centerX2, spread2);

    double stretchFactor = 2; // Коэффициент растяжения
    std::cout << "1 Rastyazh 1 parabola" << std::endl;
    fuzzy.stretchParabolaPoints(centerX, spread, stretchFactor);

    std::cin.get();
    return 0;
}
