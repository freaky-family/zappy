#pragma once

#include "IEntity.hpp"
#include "entities/AEntity.hpp"

namespace zappy {
    class Player : public AEntity {
        public:
            Player(raylib::Model &model);
            Player(tileCoordinates, raylib::Model &model);
            ~Player();

            void draw() override;
    };
}
