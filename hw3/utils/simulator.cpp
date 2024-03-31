//
// Created by Jingfeng Sun on 2024/3/29.
//

#include "simulator.h"

using std::rand;
simulator:: simulator(double brate, double trate) {
    busArrivalRate = brate;
    truckArrivalRate = trate;
    currentTime = 0;
    totalBuses = totalTrucks = 0;
    busWaitTime = truckWaitTime = 0;
    std::srand(time(nullptr));
}

void simulator::makeASimulate(int simulateTime) {
    while (currentTime < simulateTime) { // The main simulation loop
        if ((rand() % 100) < (100 * busArrivalRate)) { // Buses are coming!
            busQueue.addLast(currentTime);
        }
        if ((rand() % 100) < (100 * truckArrivalRate)) { // Trucks are coming!
            truckQueue.addLast(currentTime);
        }
        if (currentTime % 10 == 0) { // Every 10 mimutes, a ship will arrive
            int vehiclesLoaded = 0;
            while (vehiclesLoaded < 10 && (!busQueue.isEmpty() || !truckQueue.isEmpty())) {
                int busesLoaded = 0;
                while (!busQueue.isEmpty() && busesLoaded < 4 && vehiclesLoaded < 10) { // Load buses by rule
                    busWaitTime += currentTime - busQueue.getFirst();
                    busQueue.removeFirst();
                    busesLoaded++;
                    vehiclesLoaded++;
                    totalBuses++;
                }
                if ((busesLoaded % 4 == 0 || busQueue.isEmpty()) && !truckQueue.isEmpty() &&
                    vehiclesLoaded < 10) { // Load trucks by rule
                    truckWaitTime += currentTime - truckQueue.getFirst();
                    truckQueue.removeFirst();
                    vehiclesLoaded++;
                    totalTrucks++;
                }
                while (!truckQueue.isEmpty() && vehiclesLoaded < 10 && busesLoaded < 4) {
                    truckWaitTime += currentTime - truckQueue.getFirst();
                    truckQueue.removeFirst();
                    vehiclesLoaded++;
                    totalTrucks++;
                }
            }
        }
        currentTime++;
    }
}

double simulator::getAverageBusWaitTime() {
    double averageBusWaitTime = totalBuses > 0 ? static_cast<double>(busWaitTime) / totalBuses : 0.0;
    std::cout << "Average bus wait time: " << averageBusWaitTime << std::endl;
    return averageBusWaitTime;
}

double simulator::getAvetageTruckWaitTime() {
    double averageTruckWaitTime = totalTrucks > 0 ? static_cast<double>(truckWaitTime) / totalTrucks : 0.0;
    std::cout << "Average truck wait time: " << averageTruckWaitTime << std::endl;
    return averageTruckWaitTime;
}

void simulator::clear() {
    deque<int> newQueue;
    busQueue = newQueue;
    truckQueue = newQueue;
    currentTime = 0;
    totalBuses = totalTrucks = 0;
    busWaitTime = truckWaitTime = 0;
    std::srand(time(nullptr));
}