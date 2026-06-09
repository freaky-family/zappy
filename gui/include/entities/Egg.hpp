#pragma once

#include "IEntity.hpp"
#include "entities/AEntity.hpp"

namespace zappy {
    class Egg : public AEntity {
        public:
            Egg(raylib::Model &model);
            Egg(tileCoordinates, raylib::Model &model);
            ~Egg();

            void draw() override;
    };
}
