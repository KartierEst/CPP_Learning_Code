#pragma once

#include "PC.h"

// A person that capture Pokemons and make them fight.
class Trainer
{
public:
    Trainer(const std::string& name, PC& pc)
    : _name { name }
    , _pc { pc }
    {}
    std::string name(){
        return _name;
    }
    std::vector<std::unique_ptr<Pokemon>> pokeballs()
    {
        return _pc.pokemons();
    }
private:
    std::string _name;
    PC& _pc;
};
