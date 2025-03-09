#include <iostream>
#include <vector>

#include "level.h"
#include "vehicle.h"

namespace ParkingLot
{
    class ParkingLot
    {
        friend std::unique_ptr<ParkingLot> std::make_unique<ParkingLot>();

    public:
        static ParkingLot *GetInstance();

        void AddLevel(Level *level);
        bool ParkVehicle(Vehicle *vehicle);
        bool UnParkVehicle(Vehicle *vehicle);
        void DisplayAvailability();

    private:
        static std::unique_ptr<ParkingLot> instance;
        std::vector<Level *> levels;

        ParkingLot() = default; // private constructor for singleton
    };
}