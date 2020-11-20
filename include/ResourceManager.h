#ifndef RESOURCEMANAGER_H_INCLUDED
#define RESOURCEMANAGER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Logger.h"
#include "ResourceHolder.h"


namespace Textures
{
    enum ID {};
}

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

class ResourceManager
{
public:
    ResourceManager(Logger* logger);
    void load(Textures::ID id, const std::string& filename);
    const sf::Texture& get(Textures::ID id) const;
    
private:
    TextureHolder mTextureHolder;
};

#endif // RESOURCEMANAGER_H_INCLUDED
