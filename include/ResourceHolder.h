#ifndef RESOURCEHOLDER_H_
#define RESOURCEHOLDER_H_

#include "Identifier.h"

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

#include <map>
#include <memory>
#include <string>

template <typename Resource, typename Identifier>
class ResourceHolder{
    public:
        void load(Identifier id, const std::string& filename);
        Resource& get(Identifier id);
        const Resource& get(Identifier id) const;
    private:
        std::map<Identifier, std::unique_ptr<Resource>> resource_map_;
};

#include "ResourceHolder.inl"

typedef ResourceHolder<sf::Texture, Textures::Identifier> TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::Identifier> FontHolder;

#endif /* RESOURCEHOLDER_H_ */
