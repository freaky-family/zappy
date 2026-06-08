#include "TextureUtilityFinderFiller3000.hpp"
#include <filesystem>
#include <string>

zappy::TUFF::TUFF()
{}

zappy::TUFF::~TUFF()
{}

void zappy::TUFF::getMaterialsTextures(std::map<int, raylib::Texture2D>& textureMap)
{
    std::string file = "assets/Textures/PNG";
    if (!std::filesystem::exists(file)) {
        file = "gui/assets/Textures/PNG";
    } else {}
    for (auto file: std::filesystem::directory_iterator(file)) {
        raylib::Texture2D texture(file.path());
        if (static_cast<std::string>(file.path()).find("Base_color") != std::string::npos) {
            textureMap.insert({0, raylib::Texture2D (file.path())});
        }
        if (static_cast<std::string>(file.path()).find("Height") != std::string::npos) {
            textureMap.insert({6, raylib::Texture2D (file.path())});
        }
        if (static_cast<std::string>(file.path()).find("Roughness") != std::string::npos) {
            textureMap.insert({3, raylib::Texture2D (file.path())});
        }
        if (static_cast<std::string>(file.path()).find("Normal") != std::string::npos) {
            textureMap.insert({2, raylib::Texture2D (file.path())});
        }
        if (static_cast<std::string>(file.path()).find("Mixed_AO") != std::string::npos) {
            textureMap.insert({4, raylib::Texture2D (file.path())});
        }
        if (static_cast<std::string>(file.path()).find("Metallic") != std::string::npos) {
            textureMap.insert({1, raylib::Texture2D (file.path())});
        }
    }
}
