#include "entities/AEntity.hpp"
#include "IEntity.hpp"

zappy::AEntity::AEntity(): _coords(tileCoordinates(0, 0))
{}

zappy::AEntity::AEntity(zappy::tileCoordinates coords)
{
    _coords = coords;
}

zappy::AEntity::~AEntity()
{}

zappy::tileCoordinates zappy::AEntity::getCoords() const
{
    return _coords;
}
