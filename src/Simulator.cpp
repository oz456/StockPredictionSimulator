#include "Simulator.h"
#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <vector>

Simulator::Simulator(const std::vector<MarketData>& data, Strategy* strat)
  : market(data), strategy(strat) {}

void Simulator::run() {
    std::cout << std::left << std::setw(8) << "TIME" 
              << std::setw(10) << "PRICE" 
              << std::setw(10) << "ACTION" << std::endl;
    std::cout << "--------------------------------" << std::endl;

    std::vector<Trade> history;
    double cash = 0.0;
    double entryPrice = 0.0;

    for (size_t i = 0; i < market.size(); ++i) {
        const auto &md = market[i];
        Trade t = strategy->onTick(market, (int)i);

        std::cout << std::left << std::setw(8) << md.timestamp
                  << std::setw(10) << md.price;

        if (!t.type.empty()) {
            std::cout << std::setw(10) << t.type;
            history.push_back(t);
            if (t.type == "BUY") {
                entryPrice = t.price;
            } else if (t.type == "SELL") {
                // simple P&L: cash increases by sell - entry
                cash += (t.price - entryPrice);
                entryPrice = 0.0;
            }
        } else {
            std::cout << std::setw(10) << "...";
        }

        std::cout << std::endl;
        // small delay to simulate time (kept small)
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }

    std::cout << "--------------------------------" << std::endl;
    std::cout << "[SIM] Trades executed: " << history.size() << std::endl;
    std::cout << "[SIM] Unrealized/Realized P&L (approx): " << cash << std::endl;
}
