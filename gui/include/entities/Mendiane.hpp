#pragma once

#include "IEntity.hpp"
#include "entities/Materials.hpp"
#include <Color.hpp>

namespace zappy {
    class Mendiane : public Material {
        public:
            Mendiane() = delete;
            Mendiane(tileCoordinates, int);
            ~Mendiane();

            raylib::Color getMaterialColor() override;
            std::pair<float, float> getMaterialPosition(std::pair<int, int>) override;
    };
}
