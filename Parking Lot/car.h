#include <string>
#include "vehicle.h"

namespace ParkingLot
{

    class Car : public Vehicle
    {
    public:
        Car(const std::string &licensePlate)
            : Vehicle(licensePlate, VehicleType::CAR) {}
    };

} // namespace ParkingLot