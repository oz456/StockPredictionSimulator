#ifndef TRADE_H
#define TRADE_H

#include <string>

struct Trade {
    std::string time;
    double price = 0.0;
    std::string type; // "BUY" or "SELL"
};

#endif // TRADE_H
