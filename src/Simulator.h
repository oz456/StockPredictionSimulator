#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <vector>
#include "MarketData.h"
#include "Strategy.h"
#include "Trade.h"

class Simulator {
public:
    Simulator(const std::vector<MarketData>& data, Strategy* strat);
    void run(); // runs through data and prints output
private:
    std::vector<MarketData> market;
    Strategy* strategy;
};

#endif // SIMULATOR_H
