#pragma once
#include <vector>
#include <mutex>
#include <iostream>

#include "parking_spot.h"

namespace ParkingLot
{
    class Level
    {
    public:
        Level(int floor, int numSpots);
        ~Level();
        bool ParkVehicle(Vehicle *vehicle);
        bool UnparkVehicle(Vehicle *vehicle);
        void DisplayAvailability() const;

    private:
        int floor;
        std::vector<ParkingSpot *> parkingSpots;
        mutable std::mutex mtx; // mutex to protect parkingSpots
    };
}