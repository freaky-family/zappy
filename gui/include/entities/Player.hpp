#pragma once

#include "IEntity.hpp"
#include "ModelHolder.hpp"
#include "entities/AEntity.hpp"

namespace zappy {
    class Player : public AEntity {
        public:
            Player();
            Player(tileCoordinates);
            ~Player();

            void draw(ModelHolder&) override;
    };
}
