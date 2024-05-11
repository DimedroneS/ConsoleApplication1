#include "AlphaLevelFuzzy.hpp"
#include <iostream>

AlphaLevelFuzzy::AlphaLevelFuzzy() {
}

void AlphaLevelFuzzy::Parabola2AlphaLevel(double a, double b, double c) {
    for (int i = 0; i < LN; ++i) {
        double alpha = static_cast<double>(i) / (LN - 1);
        level[i].mf = alpha;
        double discriminant = b * b - 4 * a * (c - alpha);
        if (discriminant >= 0) {
            double sqrt_discriminant = sqrt(discriminant);
            level[i].lv = (-b - sqrt_discriminant) / (2 * a);
            level[i].rv = (-b + sqrt_discriminant) / (2 * a);
        }
        else {
            level[i].lv = -sqrt(-discriminant) / (2 * a);
            level[i].rv = sqrt(-discriminant) / (2 * a);
        }
    }
}

void AlphaLevelFuzzy::Parabola2AlphaLevel2(double q, double w, double e) {
    for (int i = 0; i < LN; ++i) {
        double alpha = static_cast<double>(i) / (LN - 1);
        level[i].mf = alpha;
        double discriminant = w * w - 4 * q * (e - alpha);
        if (discriminant >= 0) {
            double sqrt_discriminant = sqrt(discriminant);
            level[i].lv = (-w - sqrt_discriminant) / (2 * q);
            level[i].rv = (-w + sqrt_discriminant) / (2 * q);
        }
        else {
            level[i].lv = -sqrt(-discriminant) / (2 * q);
            level[i].rv = sqrt(-discriminant) / (2 * q);
        }
    }
}

void AlphaLevelFuzzy::Trap2AlphaLevel(double lmin, double lmax, double rmax, double rmin) {
}

void AlphaLevelFuzzy::print() {
    for (int i = 0; i < LN; ++i) {
        std::cout << "Alpha Level " << i << ": MF = " << level[i].mf << ", LV = " << level[i].lv << ", RV = " << level[i].rv << std::endl;
    }
}

double AlphaLevelFuzzy::defuzzify() {
    double numerator = 0.0;
    double denominator = 0.0;
    for (int i = 0; i < LN; ++i) {
        double mid = (level[i].lv + level[i].rv) / 2;
        numerator += level[i].mf * mid;
        denominator += level[i].mf;
    }
    return denominator != 0 ? numerator / denominator : 0;
}

AlphaLevelFuzzy AlphaLevelFuzzy::operator+(const AlphaLevelFuzzy& other) const {
    AlphaLevelFuzzy result;
    for (int i = 0; i < LN; ++i) {
        result.level[i].mf = level[i].mf + other.level[i].mf;

        result.level[i].lv = std::min(level[i].lv, other.level[i].lv);
        result.level[i].rv = std::max(level[i].rv, other.level[i].rv);
    }
    return result;
}

void AlphaLevelFuzzy::Stretch(double factor) {
    for (int i = 0; i < LN; ++i) {
        level[i].lv *= factor;
        level[i].rv *= factor;
    }
}

void AlphaLevelFuzzy::Interpolate() {
    for (int i = 1; i < LN - 1; ++i) {
        if (level[i].mf < level[i - 1].mf && level[i].mf < level[i + 1].mf) {
            level[i].lv = (level[i - 1].lv + level[i + 1].lv) / 2;
            level[i].rv = (level[i - 1].rv + level[i + 1].rv) / 2;
        }
    }
}

