

template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename)
{
    // initializing new resource and attempting loading it
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filename))
    {
        mLogger->log("Missing file " + filename, LOG::ERROR);
        
        mLogger->log("Stoping!", LOG::ERROR);
        exit(EXIT_FAILURE);
    }
    
    // adding resource to container or updating it
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
    // initializing new resource and attempting loading it
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filename, secondParam))
    {
        mLogger->log("Missing file " + filename, LOG::ERROR);
        
        mLogger->log("Stoping!", LOG::ERROR);
        exit(EXIT_FAILURE);
    }
    
    // adding resource to container or updating it
    if (!mResourceMap.insert(std::make_pair(id, std::move(resource))).second)
    {
        mResourceMap[id].reset(resource.release());
    }
    
    mLogger->log("Loaded file " + filename, LOG::INFO);
}

template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id)
{
    // attempting to find resource
    auto found = mResourceMap.find(id);

    // throwing error if not found
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
    // attempting to find resource
    auto found = mResourceMap.find(id);

    // trowing error if not found
    if(found == mResourceMap.end())
    {
        mLogger->log("Attempting to access a resource that wasn't loaded before", LOG::ERROR);

        mLogger->log("Stoping!", LOG::ERROR);
        exit(EXIT_FAILURE);
    }

    return *found->second;
}
