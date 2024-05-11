#ifndef AlphaLevelFuzzyH
#define AlphaLevelFuzzyH

#define LN 11 //Default number of levels

struct datum {
    double mf; //Level of Memebership Function
    double lv; //Left alpha level Value
    double rv; //right alpha level Value
};

class AlphaLevelFuzzy {
public:
    datum level[LN];

    AlphaLevelFuzzy();

    void Parabola2AlphaLevel(double a, double b, double c);
    void Parabola2AlphaLevel2(double q, double w, double e);
    void Trap2AlphaLevel(double lmin, double lmax, double rmax, double rmin);
    void print();
    double defuzzify();

    AlphaLevelFuzzy operator+(const AlphaLevelFuzzy& other) const;
    void Stretch(double factor);
    void Concentration();

    ~AlphaLevelFuzzy() {}
};

#endif
