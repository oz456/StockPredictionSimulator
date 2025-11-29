#ifndef EMASTRATEGY_H
#define EMASTRATEGY_H

#include "Strategy.h"
#include <string>

class EMAStrategy : public Strategy {
public:
    EMAStrategy(int shortP, int longP);
    Trade onTick(const std::vector<MarketData>& history, int index) override;

private:
    int shortPeriod;
    int longPeriod;
    double prevShortEMA = 0.0;
    double prevLongEMA = 0.0;
    bool firstRun = true;
    bool holding = false;
};

#endif // EMASTRATEGY_H
