#include "CSVReader.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<MarketData> CSVReader::readCSV(const std::string &path) {
    std::vector<MarketData> out;
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "[CSVReader] Failed to open: " << path << std::endl;
        return out;
    }
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::istringstream ss(line);
        std::string ts, priceStr;
        if (!std::getline(ss, ts, ',')) continue;
        if (!std::getline(ss, priceStr)) continue;
        try {
            double price = std::stod(priceStr);
            out.emplace_back(ts, price);
        } catch (...) {
            // skip invalid line
            continue;
        }
    }
    return out;
}
