#ifndef RESOURCEHOLDER_H_INCLUDED
#define RESOURCEHOLDER_H_INCLUDED

#include "Game.h"


template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
    ResourceHolder(Game* game);
    void load(Identifier id, const std::string& filename);
    const Resource& get(Identifier id) const;
    
private:
    Game* mGame;
    std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};

#endif // RESOURCEHOLDER_H_INCLUDED
