#pragma once

#include <iostream>
#include <string>
#include <string_view>

class Person
{
public:
    Person(std::string_view name, int position)
        : _name { name }
        , _position { position }
    {}
    Person() {}

    void answer_phone() const { std::cout << "Hi! " << _name << " on the phone!" << std::endl; }

    int get_position() const { return _position; }

    void set_position(int position) { _position = position; }

    const std::string _name;

private:
    int               _position = 0;
};
