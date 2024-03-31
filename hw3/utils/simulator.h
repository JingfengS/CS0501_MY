//
// Created by Jingfeng Sun on 2024/3/29.
//

#ifndef HW3_SIMULATOR_H
#define HW3_SIMULATOR_H
#include <iostream>
#include "deque.h"
#include <cstdlib>
#include <ctime>


class simulator {
private:
    deque<int> busQueue, truckQueue;
    int currentTime;
    int totalBuses, totalTrucks;
    int busWaitTime, truckWaitTime;
    double busArrivalRate, truckArrivalRate;
    double averageBusWaitTime;
    double averageTruckWaitTime;
public:
    simulator(double brate, double trate);

    /**
     * Make a simulation basd on the simulate time
     * @param simulateTime the total time you want to simulate
     */
    void simulate(int simulateTime);

    /**
     * Get the average bus wait time in last simulation
     * Note: The most recent simulation will overwrite the simulations before
     * @return average bus wait time
     */
    double getAverageBusWaitTime();

    /**
     * Get the average truck wait time in last simulation
     * Node: The most recent simulation will overwrite the simulations befroe
     * @return average truck wait time
     */
    double getAvetageTruckWaitTime();
};


#endif //HW3_SIMULATOR_H
