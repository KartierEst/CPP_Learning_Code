#pragma once

#include <memory>
#include "Pokemon.h"
// A ball where Pokemon sleep.
class Pokeball
{
public:
    bool empty()
    {
        return _pokemon == nullptr;
    }
    void store(std::unique_ptr<Pokemon> pokemon)
    {
        _pokemon = std::move(pokemon);
    }
    Pokemon& pokemon()
    {
        return *_pokemon;
    }
private:
    std::unique_ptr<Pokemon> _pokemon = nullptr;
};