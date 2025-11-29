#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include <vector>
#include "MarketData.h"

class CSVReader {
public:
    // Read simple CSV with two columns: timestamp,price
    static std::vector<MarketData> readCSV(const std::string &path);
};

#endif // CSVREADER_H
