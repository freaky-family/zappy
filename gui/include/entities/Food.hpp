#pragma once

#include "IEntity.hpp"
#include "entities/AEntity.hpp"

namespace zappy {
    class Food : public AEntity {
        public:
            Food(raylib::Model &model);
            Food(tileCoordinates, raylib::Model &model);
            ~Food();

            void draw() override;
    };
}
