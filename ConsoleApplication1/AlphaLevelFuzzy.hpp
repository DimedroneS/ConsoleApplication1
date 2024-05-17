#ifndef AlphaLevelFuzzyH
#define AlphaLevelFuzzyH

#define LN 11 // ���������� ������� �����

struct datum {
    double mf; // ������� �������������� �������
    double lv; // ����� �������� ������ �����
    double rv; // ������ �������� ������ �����
};

class AlphaLevelFuzzy {
public:
    datum level[LN];

    AlphaLevelFuzzy();

    double computeParabolaHeight(double x, double centerX, double spread);

    void printParabolaPoints(double centerX, double spread);

    void printParabolaPlus(double centerX, double spread, double centerX2, double spread2);

    void stretchParabolaPoints(double centerX, double spread, double stretchFactor);
    void stretchParabolaPoints2(double centerX, double spread, double stretchFactor);

    ~AlphaLevelFuzzy() {}
};

#endif
