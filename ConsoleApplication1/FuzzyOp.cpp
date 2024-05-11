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
    for (int i = 0; i < LN; ++i) {
        res.level[i].mf = std::min(op1.level[i].mf, op2.level[i].mf);
        res.level[i].lv = op1.level[i].lv - op2.level[i].lv;
        res.level[i].rv = op1.level[i].rv - op2.level[i].rv;
    }
}