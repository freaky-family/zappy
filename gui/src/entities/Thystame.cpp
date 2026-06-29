#include "entities/Thystame.hpp"
#include "IEntity.hpp"
#include "entities/Materials.hpp"
#include <Color.hpp>
#include <raylib.h>
#include <utility>

zappy::Thystame::Thystame(zappy::tileCoordinates tile, int amount) : Material(MaterialType::Thystame, tile, amount)
{}

zappy::Thystame::~Thystame()
{}

raylib::Color zappy::Thystame::getMaterialColor()
{
    return raylib::Color::DarkBlue();
}

std::pair<float, float> zappy::Thystame::getMaterialPosition(std::pair<int, int> dimensions)
{
    float zComponent = _coords.second - (dimensions.second / 2.0f) - 0.4;
    return std::pair<float, float>(_coords.first - (dimensions.first / 2.0f) - 0.4 + 0.5f, zComponent + 0.6 + 0.5f);
}
