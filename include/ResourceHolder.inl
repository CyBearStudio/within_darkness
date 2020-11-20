

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
    
    if (!mResourceMap.insert(std::make_pair(id, std::move(resource))).second)
    {
        mResourceMap[id].reset(resource.release());
    }
    
    mLogger->log("Loaded file " + filename, LOG::INFO);
}

template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename, const Parameter& secondParam)
{
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filename, secondParam))
    {
        mLogger->log("Missing file " + filename, LOG::ERROR);
        
        mLogger->log("Stoping!", LOG::ERROR);
        exit(EXIT_FAILURE);
    }
    
    if (!mResourceMap.insert(std::make_pair(id, std::move(resource))).second)
    {
        mResourceMap[id].reset(resource.release());
    }
    
    mLogger->log("Loaded file " + filename, LOG::INFO);
}

template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id)
{
    auto found = mResourceMap.find(id);

    if(found == mResourceMap.end())
    {
        mLogger->log("Attempting to access a resource that wasn't loaded before", LOG::ERROR);

        mLogger->log("Stoping!", LOG::ERROR);
        exit(EXIT_FAILURE);
    }

    return *found->second;
}

template <typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
    auto found = mResourceMap.find(id);

    if(found == mResourceMap.end())
    {
        mLogger->log("Attempting to access a resource that wasn't loaded before", LOG::ERROR);

        mLogger->log("Stoping!", LOG::ERROR);
        exit(EXIT_FAILURE);
    }

    return *found->second;
}
