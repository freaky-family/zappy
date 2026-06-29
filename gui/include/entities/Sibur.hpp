#pragma once

#include "IEntity.hpp"
#include "entities/Materials.hpp"
#include <Color.hpp>

namespace zappy {
    class Sibur : public Material {
        public:
            Sibur() = delete;
            Sibur(tileCoordinates, int);
            ~Sibur();

            raylib::Color getMaterialColor() override;
            std::pair<float, float> getMaterialPosition(std::pair<int, int>) override;
    };
}
