#pragma once

#include <Model.hpp>
#include <Texture.hpp>
#include <map>

namespace zappy {
    class ModelHolder {
        private:
            raylib::Model _materialModel;
            std::map<int, raylib::Texture2D> _materialTextureMap;
        public:
            ModelHolder();
            ~ModelHolder();

            void initModels();
            void unloadModels();
            raylib::Model& getMaterialModel();
    };
}