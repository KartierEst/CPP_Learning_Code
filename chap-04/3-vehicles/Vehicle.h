#pragma once

#include <iostream>

class Driver
{
public :
    void pass_car_licence_exam() { _has_car_licence = true; }
    bool has_car_licence() const { return _has_car_licence; }
    void pass_car_vol_licence_exam() { _has_car_vol_licence = true; }
    bool has_car_vol_licence() const { return _has_car_vol_licence; }
private :
    bool _has_car_licence = false;
    bool _has_car_vol_licence = false;
};

class Vehicle
{
protected:
    const Driver& _driver;
    Vehicle(const Driver& driver)
        : _driver { driver }
    {}
public:
    /*Vehicle(const Driver& driver)
        : _driver { driver }
    {}*/

    virtual ~Vehicle() {}

    virtual unsigned int drive() const = 0;
    /*{
        std::cerr << "Not implemented" << std::endl;
        return 0u;
    }*/
};
