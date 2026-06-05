#pragma once

#include "IEntity.hpp"
#include "raylib-cpp.hpp"

namespace zappy {
    class AEntity : public IEntity {
        protected:
            tileCoordinates _coords;
            raylib::Image _texture;
        public:
            AEntity();
            ~AEntity();

            tileCoordinates getCoords() const override;
    };
}
