#include "entities/Materials.hpp"
#include "IEntity.hpp"
#include "ModelHolder.hpp"
#include "entities/AEntity.hpp"

zappy::Material::Material(): zappy::AEntity()
{}

zappy::Material::Material(zappy::tileCoordinates coords): zappy::AEntity(coords)
{}

zappy::Material::~Material()
{}

void zappy::Material::draw(zappy::ModelHolder& modelHolder)
{
    modelHolder.getMaterialModel().Draw(Vector3(_coords.first - 5, 1, _coords.second - 5), 1.0f, raylib::Color::Blue());
}
