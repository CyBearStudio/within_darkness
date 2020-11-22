#ifndef RESOURCEHOLDER_H_INCLUDED
#define RESOURCEHOLDER_H_INCLUDED

#include <map>
#include <memory>
#include "Logger.h"


template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
    ResourceHolder(Logger* logger) : mLogger(logger) {};
    void load(Identifier id, const std::string& filename); // store a new resource or update
    template <typename Parameter>
    void load(Identifier id, const std::string& filename, const Parameter& secondParam); // same for shader and more
    Resource& get(Identifier id); // access resource
    const Resource& get(Identifier id) const; // access resource without modifying it
    
private:
    Logger* mLogger;
    std::map<Identifier, std::unique_ptr<Resource>> mResourceMap; // resources container
};

#include "ResourceHolder.inl"

#endif // RESOURCEHOLDER_H_INCLUDED
