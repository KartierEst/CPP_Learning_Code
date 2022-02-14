#pragma once

#include "Animal.h"

#include <iostream>

class Cow : public Animal
{
public:
    //void sing() const override { std::cout << "Mewwwwwh" << std::endl; }
    void sing(char next_char) const override { std::cout << "Mewwwwwh" << next_char; }
};
