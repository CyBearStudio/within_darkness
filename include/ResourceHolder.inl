#include "GlobalResource.h"


template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename)
{
    // initializing new resource and attempting loading it
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filename))
    {
        mLogger->log(GlobalResource::LOG_MISSING + filename, LOG::ERROR);
        
        mLogger->log(GlobalResource::LOG_STOP, LOG::ERROR);
        exit(EXIT_FAILURE);
    }
    
    // adding resource to container or updating it
    if (!mResourceMap.insert(std::make_pair(id, std::move(resource))).second)
    {
        mResourceMap[id].reset(resource.release());
    }
    
    mLogger->log(GlobalResource::LOG_LOADED + filename, LOG::INFO);
}

template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename, const Parameter& secondParam)
{
    // initializing new resource and attempting loading it
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filename, secondParam))
    {
        mLogger->log(GlobalResource::LOG_MISSING + filename, LOG::ERROR);
        
        mLogger->log(GlobalResource::LOG_STOP, LOG::ERROR);
        exit(EXIT_FAILURE);
    }
    
    // adding resource to container or updating it
    if (!mResourceMap.insert(std::make_pair(id, std::move(resource))).second)
    {
        mResourceMap[id].reset(resource.release());
    }
    
    mLogger->log(GlobalResource::LOG_LOADED + filename, LOG::INFO);
}

template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id)
{
    // attempting to find resource
    auto found = mResourceMap.find(id);

    // throwing error if not found
    if(found == mResourceMap.end())
    {
        mLogger->log(GlobalResource::LOG_UNLOADED, LOG::ERROR);

        mLogger->log(GlobalResource::LOG_STOP, LOG::ERROR);
        exit(EXIT_FAILURE);
    }

    return *found->second;
}

template <typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
    // attempting to find resource
    auto found = mResourceMap.find(id);

    // trowing error if not found
    if(found == mResourceMap.end())
    {
        mLogger->log(GlobalResource::LOG_UNLOADED, LOG::ERROR);

        mLogger->log(GlobalResource::LOG_STOP, LOG::ERROR);
        exit(EXIT_FAILURE);
    }

    return *found->second;
}
