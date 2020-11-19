#include "ResourceManager.h"


ResourceManager::ResourceManager(Logger* logger) : mTextureHolder(logger)
{
}

void ResourceManager::load(Textures::ID id, const std::string& filename)
{
    mTextureHolder.load(id, filename);
}

const sf::Texture& ResourceManager::get(Textures::ID id) const
{
    return mTextureHolder.get(id);
}
