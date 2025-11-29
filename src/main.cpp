#include <iostream>
#include "CSVReader.h"
#include "EMAStrategy.h"
#include "Simulator.h"

int main() {
    std::string csvPath = "data/market.csv";
    auto data = CSVReader::readCSV(csvPath);
    if (data.empty()) {
        std::cerr << "[main] No data loaded. Ensure data/market.csv exists." << std::endl;
        return 1;
    }

    int shortPeriod = 3;
    int longPeriod = 5;
    EMAStrategy strategy(shortPeriod, longPeriod);
    Simulator sim(data, &strategy);

    std::cout << "StockPredictor - OOP EMA Crossover Simulation\n" << std::endl;
    sim.run();

    return 0;
}
