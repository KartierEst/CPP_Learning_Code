#pragma once

#include "Car.h"
class FlyingCar : public Car
{
public:
    FlyingCar(const Driver& driver, unsigned int speed)
        : Car { driver, speed }
        , _flying_speed { 10u * speed }
    {}

    unsigned int drive() const override
    {
        if(_driver.has_car_vol_licence())
        {
            std::cout << "Sweeesh!" << std::endl;
            return _flying_speed;
        }
        return Car::drive();
    }

private:
    unsigned int _flying_speed = 0;
};

