//---------------------------------------------------------------------------
#ifndef YourOpH
#define YourOpH
//---------------------------------------------------------------------------
#include "AlphaLevelFuzzy.hpp"
#include "FuzzyOp.hpp"

class YourOp : public FuzzyOp {
public:
	AlphaLevelFuzzy run();
};

#endif