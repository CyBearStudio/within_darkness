#include "ResourceHolder.h"


template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename)
{
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filename))
    {
        mLogger->log("ERROR: missing file " + filename);
        
        mLogger->log("Program terminated with ERROR");
        exit(EXIT_FAILURE);
    }
    
    if (!mResourceMap.insert(std::make_pair(id, std::move(resource))))
    {
        mResourceMap[id].reset(resource.release());
    }
}

template <typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
    return mResourceMap[id];
}
