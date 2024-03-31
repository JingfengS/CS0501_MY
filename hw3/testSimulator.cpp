//
// Created by Jingfeng Sun on 2024/3/29.
//
#include <iostream>
#include "gtest/gtest.h"
#include "simulator.h"

TEST(simulator, constructor) {
    simulator s(0.5, 0.5);
}

TEST(simulator, makeASimulation) {
    simulator s(0.6, 0.3);
    s.makeASimulate(1000);
    s.getAvetageTruckWaitTime();
    s.getAverageBusWaitTime();
    s.clear();
}

TEST(simulator, make2Simulation) {
    simulator s(0.6, 0.3);
    s.makeASimulate(1000);
    s.getAvetageTruckWaitTime();
    s.getAverageBusWaitTime();
    s.clear();
    s.makeASimulate(10000);
    s.getAvetageTruckWaitTime();
    s.getAverageBusWaitTime();
    s.clear();
}

/**
 * When simulation time gets very large, the average time of both
 * buses and trucks begins to converge, which follows intuition.
 */
TEST(simulator, makeManySimulation) {
    simulator s(0.6, 0.3);
    for (int i = 10; i < 10000000; i *= 2) {
        std::cout << "Simulation Time: " << i << std::endl;
        s.makeASimulate(i);
        s.getAverageBusWaitTime();
        s.getAvetageTruckWaitTime();
        s.clear();
        std::cout << std::endl;
    }
}

