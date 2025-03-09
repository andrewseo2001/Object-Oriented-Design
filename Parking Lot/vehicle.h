#pragma once
#include <string>

namespace ParkingLot
{

    enum class VehicleType
    {
        CAR,
        MOTORCYCLE,
        TRUCK
    };

    class Vehicle
    {
    protected:
        std::string licensePlate;
        VehicleType type;

    public:
        Vehicle(const std::string &licensePlate, VehicleType type)
            : licensePlate(licensePlate), type(type) {}

        virtual ~Vehicle() = default;

        VehicleType GetVehicleType() const
        {
            return type;
        }
    };

} // namespace ParkingLot
