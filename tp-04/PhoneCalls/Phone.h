#pragma once

#include "Person.h"

class Phone
{
protected:
    Phone(const Person& owner)
        : _owner { owner }
    {}
public:
    virtual void ring() const = 0;//{ _owner.answer_phone(); }

    const Person& _owner;
};
