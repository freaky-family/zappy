#pragma once

#include "IEntity.hpp"
#include "ModelHolder.hpp"
#include "entities/AEntity.hpp"

namespace zappy {
    class Food : public AEntity {
        public:
            Food();
            Food(tileCoordinates);
            ~Food();

            void draw(ModelHolder&) override;
    };
}
