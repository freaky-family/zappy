#include "entities/Materials.hpp"
#include "IEntity.hpp"
#include "entities/AEntity.hpp"

zappy::Material::Material(raylib::Model &model): zappy::AEntity(model)
{}

zappy::Material::Material(zappy::tileCoordinates coords, raylib::Model &model): zappy::AEntity(coords, model)
{}

zappy::Material::~Material()
{}

void zappy::Material::draw()
{
    _model.Draw(Vector3(_coords.first - 5, 1, _coords.second - 5), 1.0f, raylib::Color::Blue());
}
