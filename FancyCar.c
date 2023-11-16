#include <stdio.h>
#include <string.h>
#include "FancyCar.h"

// Complete the body of the functions

// Car initialization                                       (3 marks)
// Complete the function body
FancyCar InitializeFancyCar(FancyCar car, char* model, double kpl, double fuelCapacity,
                              double fuel, int odometer) {
    strcpy(car.model,model);
    car.kpl = kpl;
    car.fuel = fuel;
    car.fuelCapacity = fuelCapacity;
    car.odometer = odometer;
    car.engineStatus = 0;
    
    return car;
}

// Drive car requested kilometers.                           (7 marks)
// It must check for engine status, enough fuel and check for positive value
FancyCar Drive(FancyCar car, int kilometersToDrive) {
    if(car.engineStatus && kilometersToDrive >=0){
        if(car.fuel < (kilometersToDrive / car.kpl)){
            kilometersToDrive = car.fuel * car.kpl;
            car.fuel = 0.0;
            car.odometer += kilometersToDrive;
        }else{
            car.odometer += kilometersToDrive;
            car.fuel -= kilometersToDrive / car.kpl;
        }
    }
    return car;
}

// Add fuel to tank.                                         (4 marks)
// It must Check for engine status, fuel capacity and positive value.
FancyCar AddFuel(FancyCar car, int amtToAdd) {
    if(car.engineStatus){
        car.fuel += amtToAdd;
        if(car.fuel > car.fuelCapacity){
            car.fuel = car.fuelCapacity;
        }
    }

    return car;
}

// Turn on the car engine.                                  (1 mark)
FancyCar StartEngine(FancyCar car) {
    car.engineStatus = 1;
    return car;    
}

// Turn off the car engine.                                 (1 mark)
FancyCar StopEngine(FancyCar car) {
    car.engineStatus = 0;
    return car;
}
