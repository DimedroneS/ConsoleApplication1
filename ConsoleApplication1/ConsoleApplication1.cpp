#include "YourOp.hpp"
#include "AlphaLevelFuzzy.hpp"
#include <iostream>

int main(int argc, char* argv[]) {

    AlphaLevelFuzzy a, b, c;
    AlphaLevelFuzzy q, w, e;
    YourOp testOp;

    // Adjust the parameters for the parabolic membership function
    a.Parabola2AlphaLevel(1, 0, -2);
    b.Parabola2AlphaLevel(1, 0, 2);

    testOp.setOp1(a);
    testOp.setOp2(b);
    testOp.run();
    c = testOp.getResult();
    std::cout << "parabola 1:" << std::endl;
    c.print();

    q.Parabola2AlphaLevel2(-1, 0, 1);
    w.Parabola2AlphaLevel2(-1, 0, -1);

    testOp.setOp1(q);
    testOp.setOp2(w);
    testOp.run();
    e = testOp.getResult();
    std::cout << "parabola 2:" << std::endl;
    e.print();

    AlphaLevelFuzzy sum = c + e;
    std::cout << "Sum parabols" << std::endl;
    sum.print();

    double stretchFactor = 2.0; // Example stretch factor
    c.Stretch(stretchFactor);
    std::cout << "Stretched parabola c:" << std::endl;
    c.print();


    return 0;
}
