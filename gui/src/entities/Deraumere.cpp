#include "entities/Deraumere.hpp"
#include "IEntity.hpp"
#include "entities/Materials.hpp"
#include <Color.hpp>
#include <raylib.h>
#include <utility>

zappy::Deraumere::Deraumere(zappy::tileCoordinates tile, int amount) : Material(MaterialType::Deraumere, tile, amount)
{}

zappy::Deraumere::~Deraumere()
{}

raylib::Color zappy::Deraumere::getMaterialColor()
{
    return raylib::Color::Green();
}

std::pair<float, float> zappy::Deraumere::getMaterialPosition(std::pair<int, int> dimensions)
{
    float zComponent = _coords.second - (dimensions.second / 2.0f) - 0.4;
    return std::pair<float, float>(_coords.first - (dimensions.first / 2.0f) - 0.4 + 0.5f, zComponent + 0.15 + 0.5f);
}
