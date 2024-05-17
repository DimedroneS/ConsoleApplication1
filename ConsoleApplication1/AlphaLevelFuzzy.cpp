#include "AlphaLevelFuzzy.hpp"
#include <iostream>
#include <cmath>

AlphaLevelFuzzy::AlphaLevelFuzzy() {
}

double AlphaLevelFuzzy::computeParabolaHeight(double x, double centerX, double spread) {
    return 1.0 - pow((x - centerX) / spread, 2);
}

void AlphaLevelFuzzy::printParabolaPoints(double centerX, double spread) {

    for (int alphaIndex = 0; alphaIndex < LN; ++alphaIndex) {
        double alpha = static_cast<double>(alphaIndex) / (LN - 1); //диапазон 0-1
        // Левая ветвь параболы
        double leftX = centerX - spread * sqrt(1.0 - alpha);
        double leftY = computeParabolaHeight(leftX, centerX, spread);

        // Правая ветвь параболы
        double rightX = centerX + spread * sqrt(1.0 - alpha);
        double rightY = computeParabolaHeight(rightX, centerX, spread);

        // Выводим результат
        std::cout << "Alpha Level " << alpha << ": ";
        std::cout << "Left Branch (" << leftX << "); ";
        std::cout << "Right Branch (" << rightX << ")" << std::endl;
    }
}

void AlphaLevelFuzzy::printParabolaPlus(double centerX, double spread, double centerX2, double spread2) {

    for (int alphaIndex = 0; alphaIndex < LN; ++alphaIndex) {
        double alpha = static_cast<double>(alphaIndex) / (LN - 1); //диапазон 0-1
        // Левая ветвь параболы
        double leftX = centerX - spread * sqrt(1.0 - alpha) + centerX2 - spread2 * sqrt(1.0 - alpha);
        double leftY = computeParabolaHeight(leftX, centerX, spread);

        // Правая ветвь параболы
        double rightX = centerX + spread * sqrt(1.0 - alpha) + centerX2 + spread2 * sqrt(1.0 - alpha);
        double rightY = computeParabolaHeight(rightX, centerX, spread); 

        // Выводим результат
        std::cout << "Alpha Level " << alpha << ": ";
        std::cout << "Left Branch (" << leftX << "); ";
        std::cout << "Right Branch (" << rightX << ")" << std::endl;
    }
}

void AlphaLevelFuzzy::stretchParabolaPoints(double centerX, double spread, double stretchFactor) {

    for (int alphaIndex = 0; alphaIndex < LN; ++alphaIndex) {
        double alpha = static_cast<double>(alphaIndex) / (LN - 1);
        // Левая ветвь параболы
        double leftX = centerX - spread * sqrt(1.0 - alpha) * stretchFactor;
        double leftY = computeParabolaHeight(leftX, centerX, spread);

        // Правая ветвь параболы
        double rightX = centerX + spread * sqrt(1.0 - alpha) * stretchFactor;
        double rightY = computeParabolaHeight(rightX, centerX, spread);

        // Выводим результат
        std::cout << "Alpha Level " << alpha << ": ";
        std::cout << "Left Branch (" << leftX << "); ";
        std::cout << "Right Branch (" << rightX << ")" << std::endl;
    }
}

void AlphaLevelFuzzy::stretchParabolaPoints2(double centerX, double spread, double stretchFactor) {

    for (int alphaIndex = 0; alphaIndex < LN; ++alphaIndex) {
        double alpha = static_cast<double>(alphaIndex) / (LN - 1);
        // Левая ветвь параболы
        double leftX = (centerX - spread * sqrt(1.0 - alpha)) * stretchFactor;
        double leftY = computeParabolaHeight(leftX, centerX, spread);

        // Правая ветвь параболы
        double rightX = (centerX + spread * sqrt(1.0 - alpha)) * stretchFactor;
        double rightY = computeParabolaHeight(rightX, centerX, spread);

        // Выводим результат
        std::cout << "Alpha Level " << alpha << ": ";
        std::cout << "Left Branch (" << leftX << "); ";
        std::cout << "Right Branch (" << rightX << ")" << std::endl;
    }
}










