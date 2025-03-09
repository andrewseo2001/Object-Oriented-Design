#include "parking_lot.h"
#include "car.h"
#include "truck.h"

namespace ParkingLot
{
    static void Run()
    {
        ParkingLot *parkingLot = ParkingLot::GetInstance();
        parkingLot->AddLevel(new Level(1, 100));
        parkingLot->AddLevel(new Level(2, 100));

        Vehicle *car = new Car("ABC123");
        Vehicle *truck = new Truck("XYZ789");
        Vehicle *motorcycle = new Motorcycle("M1234");

        parkingLot->ParkVehicle(car);
        parkingLot->ParkVehicle(truck);
        parkingLot->ParkVehicle(motorcycle);

        parkingLot->DisplayAvailability();

        parkingLot->UnParkVehicle(motorcycle);

        parkingLot->DisplayAvailability();
    }

}

int main()
{
    ParkingLot::Run();
}