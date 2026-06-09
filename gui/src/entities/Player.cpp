#include "entities/Player.hpp"
#include "IEntity.hpp"
#include "entities/AEntity.hpp"
zappy::Player::Player(): zappy::AEntity()
{}

zappy::Player::Player(zappy::tileCoordinates coords): zappy::AEntity(coords)
{}

zappy::Player::~Player()
{}

void zappy::Player::draw(zappy::ModelHolder& modelHolder)
{
    static_cast<void>(modelHolder);
    return;
}
