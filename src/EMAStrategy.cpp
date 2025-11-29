#include "EMAStrategy.h"
#include "IndicatorCalculator.h"

EMAStrategy::EMAStrategy(int shortP, int longP)
  : shortPeriod(shortP), longPeriod(longP) {}

Trade EMAStrategy::onTick(const std::vector<MarketData>& history, int index) {
    Trade t;
    const auto &md = history[index];
    double price = md.price;

    double shortEMA, longEMA;
    if (firstRun) {
        shortEMA = price;
        longEMA = price;
        firstRun = false;
    } else {
        shortEMA = IndicatorCalculator::calculateEMA(price, prevShortEMA, shortPeriod);
        longEMA = IndicatorCalculator::calculateEMA(price, prevLongEMA, longPeriod);
    }

    bool goldenCross = (prevShortEMA < prevLongEMA) && (shortEMA > longEMA) && (index > longPeriod);
    bool deathCross  = (prevShortEMA > prevLongEMA) && (shortEMA < longEMA) && (index > longPeriod);

    if (goldenCross && !holding) {
        t.time = md.timestamp;
        t.price = price;
        t.type = "BUY";
        holding = true;
    } else if (deathCross && holding) {
        t.time = md.timestamp;
        t.price = price;
        t.type = "SELL";
        holding = false;
    } else {
        // no trade
    }

    prevShortEMA = shortEMA;
    prevLongEMA = longEMA;
    return t;
}
