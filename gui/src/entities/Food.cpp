#include "entities/Food.hpp"
#include "IEntity.hpp"
#include "ModelHolder.hpp"
#include "entities/AEntity.hpp"
zappy::Food::Food(): zappy::AEntity()
{}

zappy::Food::Food(zappy::tileCoordinates coords): zappy::AEntity(coords)
{}

zappy::Food::~Food()
{}

void zappy::Food::draw(zappy::ModelHolder& modelHolder)
{
    modelHolder.getFoodModel().Draw(Vector3(_coords.first - 5, 0.1, _coords.second - 5), 1.0f);
}
