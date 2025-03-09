#include <string>

#include "vehicle.h"

namespace ParkingLot
{
    class Truck : public Vehicle
    {
    public:
        Truck(const std::string &licensePlate)
            : Vehicle(licensePlate, VehicleType::TRUCK)
    }
}
