#include "FuzzyOp.hpp"
#include <utility>

void FuzzyOp::setOp1(AlphaLevelFuzzy op) {
    op1 = op;
};

void FuzzyOp::setOp2(AlphaLevelFuzzy op) {
    op2 = op;
};

void FuzzyOp::run() {
    subtract();
};

AlphaLevelFuzzy FuzzyOp::getResult() {
    FuzzyOp::run();
    return res;
};

AlphaLevelFuzzy FuzzyOp::getOp1() {
    return op1;
};

AlphaLevelFuzzy FuzzyOp::getOp2() {
    return op2;
};

void FuzzyOp::subtract() {

}