#pragma once

// A creature that is cute and can fight other ones.
class Pokemon
{
public:
    Pokemon(std::string name)
    : _name { name }
    {}

    const std::string name()
    {
        return _name;
    }
private:
    std::string _name;
};
