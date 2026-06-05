#pragma once

#include "IEntity.hpp"
#include "Tiles.hpp"
#include <unordered_map>
namespace zappy {
    class Map {
        private:
            std::unordered_map<tileCoordinates, Tile> _tiles;
        public:
            Map();
            ~Map();

            Tile getTile(tileCoordinates) const;
    };
}