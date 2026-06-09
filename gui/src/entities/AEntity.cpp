#include "entities/AEntity.hpp"
#include "IEntity.hpp"

zappy::AEntity::AEntity(raylib::Model &model): _coords(tileCoordinates(0, 0)), _model(model)
{}

zappy::AEntity::AEntity(zappy::tileCoordinates coords, raylib::Model &model): _model(model)
{
    _coords = coords;
}

zappy::AEntity::~AEntity()
{}

zappy::tileCoordinates zappy::AEntity::getCoords() const
{
    return _coords;
}
