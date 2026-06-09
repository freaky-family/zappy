#include "entities/Egg.hpp"
#include "IEntity.hpp"
#include "entities/AEntity.hpp"
zappy::Egg::Egg(raylib::Model &model): zappy::AEntity(model)
{}

zappy::Egg::Egg(zappy::tileCoordinates coords, raylib::Model &model): zappy::AEntity(coords, model)
{}

zappy::Egg::~Egg()
{}

void zappy::Egg::draw()
{
    return;
}
