#include "entities/Player.hpp"
#include "IEntity.hpp"
#include "entities/AEntity.hpp"
zappy::Player::Player(raylib::Model &model): zappy::AEntity(model)
{}

zappy::Player::Player(zappy::tileCoordinates coords, raylib::Model &model): zappy::AEntity(coords, model)
{}

zappy::Player::~Player()
{}

void zappy::Player::draw()
{
    return;
}
