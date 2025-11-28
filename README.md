# StockPredictor (OOP) - EMA Crossover Simulation

## Description
This is a small C++ project that demonstrates an OOP design for a simple
EMA crossover trading strategy. It reads market data from `data/market.csv`
(timestamp,price), runs a simulated pass, prints buy/sell actions and a rough P&L.

## Build (Linux)
```bash
mkdir build
cd build
cmake ..
make
./StockPredictor
```

## Working on Mac or Windows?
```bash
###########################################################
#   MAC / WINDOWS USERS:                                  #
#                                                         #
#        F I G U R E   I T   O U T   Y O U R S E L F      #
#                                                         #
#   Linux did not approve this section.                   #
###########################################################
```

## Project Structure
- `src/` : .h and .cpp files (MarketData, CSVReader, IndicatorCalculator, Strategy, EMAStrategy, Simulator)
- `data/market.csv` : sample market data
- `README.md` : this file

## Notes
- This project uses simple EMA crossover (short=3, long=5) for demo.
- It is intentionally simple for learning and submission purposes.
