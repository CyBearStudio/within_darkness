#include "ResourceHolder.h"


template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename)
{
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filename))
    {
        mLogger->log("Missing file " + filename, LOG::ERROR);
        
        mLogger->log("Stoping!", LOG::ERROR);
        exit(EXIT_FAILURE);
    }
    
    if (!mResourceMap.insert(std::make_pair(id, std::move(resource))))
    {
        mResourceMap[id].reset(resource.release());
    }
    
    mLogger->log("Loaded file " + filename, LOG::INFO);
}

template <typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
    return mResourceMap[id];
}
