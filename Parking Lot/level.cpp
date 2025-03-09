#include "level.h"
#include "parking_spot.h"

namespace ParkingLot
{

    Level::Level(int floor, int numSpots) : floor(floor)
    {
        parkingSpots.reserve(numSpots);

        double spotsForBikes = 0.50;
        double spotsForCars = 0.40;

        int numBikes = static_cast<int>(numSpots * spotsForBikes);
        int numCars = static_cast<int>(numSpots * spotsForCars);

        for (int i = 1; i <= numCars; i++)
        {
            parkingSpots.push_back(new ParkingSpot(i, VehicleType::CAR));
        }

        for (int i = numCars + 1; i <= numBikes + numCars; ++i)
        {
            parkingSpots.push_back(new ParkingSpot(i, VehicleType::MOTORCYCLE));
        }

        for (int i = numBikes + numCars + 1; i <= numSpots; ++i)
        {
            parkingSpots.push_back(new ParkingSpot(i, VehicleType::TRUCK));
        }
    }

    Level::~Level()
    {
        for (auto spot : parkingSpots)
        {
            delete spot;
        }
    }

    bool Level::ParkVehicle(Vehicle *vehicle)
    {
        std::lock_guard<std::mutex> lock(mtx);
        for (auto spot : parkingSpots)
        {
            if (spot->IsAvailable() && spot->GetVehicleType() == vehicle->GetVehicleType())
            {
                spot->ParkVehicle(vehicle);
                return true;
            }
        }
        return false;
    }

    bool Level::UnparkVehicle(Vehicle *vehicle)
    {
        std::lock_guard<std::mutex> lock(mtx);
        for (auto spot : parkingSpots)
        {
            if (!spot->IsAvailable() && spot->GetParkedVehicle() == vehicle)
            {
                spot->UnparkVehicle();
                return true;
            }
        }
        return false;
    }

    void Level::DisplayAvailability() const
    {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Level " << floor << "Availability:" << std::endl;
        for (auto spot : parkingSpots)
        {
            std::cout << "Spot " << spot->GetSpotNumber() << ": "
                      << (spot->IsAvailable() ? "Available For" : "Occupied By")
                      << " ";

            std::cout << static_cast<int>(spot->GetVehicleType()) << std::endl;
        }
    }

}
