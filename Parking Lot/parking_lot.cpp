#include "parking_lot.h"

namespace ParkingLot
{
    // Define the static member
    std::unique_ptr<ParkingLot> ParkingLot::instance;

    ParkingLot *ParkingLot::GetInstance()
    {
        if (!instance)
        {
            instance = std::make_unique<ParkingLot>();
        }
        return instance.get();
    }

    void ParkingLot::AddLevel(Level *level)
    {
        levels.push_back(level);
    }

    bool ParkingLot::ParkVehicle(Vehicle *vehicle)
    {
        for (Level *level : levels)
        {
            if (level->ParkVehicle(vehicle))
            {
                std::cout << "Vehicle parked successfully." << std::endl;
                return true;
            }
        }
        std::cout << "Could not park vehicle" << std::endl;
        return false;
    }

    bool ParkingLot::UnParkVehicle(Vehicle *vehicle)
    {
        for (Level *level : levels)
        {
            if (level->UnparkVehicle(vehicle))
            {
                return true;
            }
        }
        return false;
    }

    void ParkingLot::DisplayAvailability()
    {
        for (Level *level : levels)
        {
            level->DisplayAvailability();
        }
    }

}