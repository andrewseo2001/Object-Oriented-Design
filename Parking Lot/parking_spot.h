#pragma once
#include "vehicle.h"
#include <stdexcept>

namespace ParkingLot
{
    class ParkingSpot
    {
    public:
        ParkingSpot(int spotNumber, VehicleType vehicleType)
            : spotNumber(spotNumber), vehicleType(vehicleType), parkedVehicle(nullptr)
        {
        }

        bool IsAvailable()
        {
            return parkedVehicle == nullptr;
        }

        void ParkVehicle(Vehicle *vehicle)
        {
            if (IsAvailable() && vehicle->GetVehicleType() == vehicleType)
            {
                parkedVehicle = vehicle;
            }
            else
            {
                throw std::invalid_argument("Invalid vehicle type or spot already occupied");
            }
        }

        void UnparkVehicle()
        {
            parkedVehicle = nullptr;
        }

        VehicleType GetVehicleType()
        {
            return vehicleType;
        }

        Vehicle *GetParkedVehicle()
        {
            return parkedVehicle;
        }

        int GetSpotNumber()
        {
            return spotNumber;
        }

    private:
        int spotNumber;
        VehicleType vehicleType;
        Vehicle *parkedVehicle; // Pointer can be nullptr when spot is empty
    };
}