#include "ModelHolder.hpp"
#include <filesystem>
#include "TextureUtilityFinderFiller3000.hpp"

zappy::ModelHolder::ModelHolder(): _materialModel(), _materialTextureMap()
{}

zappy::ModelHolder::~ModelHolder()
{}

void zappy::ModelHolder::initModels()
{
    std::string file = "assets/OBJ/stylized_crystal_SM.obj";
    if (!std::filesystem::exists(file)) {
        file = "gui/assets/OBJ/stylized_crystal_SM.obj";
    } else {}
    _materialModel.Load(file);
    zappy::TUFF::getMaterialsTextures(_materialTextureMap);
    for (auto &materialTexture: _materialTextureMap) {
        _materialModel.materials[0].maps[materialTexture.first].texture = materialTexture.second;
    }
}

void zappy::ModelHolder::unloadModels()
{
    for (auto &materialTexture: _materialTextureMap) {
        materialTexture.second.Unload();
    }
    _materialModel.Unload();
}

raylib::Model& zappy::ModelHolder::getMaterialModel()
{
    return _materialModel;
}
