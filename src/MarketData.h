#ifndef MARKETDATA_H
#define MARKETDATA_H
#include <string>

class MarketData {
public:
    MarketData() = default;
    MarketData(const std::string &ts, double p) : timestamp(ts), price(p) {}
    std::string timestamp;
    double price = 0.0;
};

#endif // MARKETDATA_H
