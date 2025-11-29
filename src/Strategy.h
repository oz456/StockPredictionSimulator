#ifndef STRATEGY_H
#define STRATEGY_H

#include <vector>
#include "MarketData.h"
#include "Trade.h"

class Strategy {
public:
    virtual ~Strategy() = default;
    // Process next data point and optionally return a Trade (empty.type=="" means no trade)
    virtual Trade onTick(const std::vector<MarketData>& history, int index) = 0;
};

#endif // STRATEGY_H
