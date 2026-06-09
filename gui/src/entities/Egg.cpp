#include "entities/Egg.hpp"
#include "IEntity.hpp"
#include "ModelHolder.hpp"
#include "entities/AEntity.hpp"
zappy::Egg::Egg(): zappy::AEntity()
{}

zappy::Egg::Egg(zappy::tileCoordinates coords): zappy::AEntity(coords)
{}

zappy::Egg::~Egg()
{}

void zappy::Egg::draw(zappy::ModelHolder& modelHolder)
{
    static_cast<void>(modelHolder);
    return;
}
