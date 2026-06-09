#include "entities/Food.hpp"
#include "IEntity.hpp"
#include "entities/AEntity.hpp"
zappy::Food::Food(raylib::Model &model): zappy::AEntity(model)
{}

zappy::Food::Food(zappy::tileCoordinates coords, raylib::Model &model): zappy::AEntity(coords, model)
{}

zappy::Food::~Food()
{}

void zappy::Food::draw()
{
    return;
}
