#include <string>

#include "vehicle.h"

namespace ParkingLot
{
    class Motorcycle : public Vehicle
    {
    public:
        Motorcycle(const std::string &licensePlate)
            : Vehicle(licensePlate, VehicleType::MOTORCYCLE)
    }
}
