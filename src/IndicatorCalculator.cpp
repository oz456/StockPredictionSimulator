#include "IndicatorCalculator.h"

double IndicatorCalculator::calculateSMA(const std::vector<MarketData>& data, int period, int currentIndex) {
    if (currentIndex < period - 1) return 0.0;
    double sum = 0.0;
    for (int i = 0; i < period; ++i) sum += data[currentIndex - i].price;
    return sum / period;
}

double IndicatorCalculator::calculateEMA(double currentPrice, double previousEMA, int period) {
    double k = 2.0 / (period + 1);
    return (currentPrice * k) + (previousEMA * (1.0 - k));
}
