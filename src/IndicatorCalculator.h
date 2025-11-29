#ifndef INDICATORCALCULATOR_H
#define INDICATORCALCULATOR_H

#include <vector>
#include "MarketData.h"

class IndicatorCalculator {
public:
    static double calculateSMA(const std::vector<MarketData>& data, int period, int currentIndex);
    static double calculateEMA(double currentPrice, double previousEMA, int period);
};

#endif // INDICATORCALCULATOR_H
