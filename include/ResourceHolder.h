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
    void load(Identifier id, const std::string& filename);
    template <typename Parameter>
    void load(Identifier id, const std::string& filename, const Parameter& secondParam);
    const Resource& get(Identifier id) const;
    
private:
    Logger* mLogger;
    std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};

#include "ResourceHolder.inl"

#endif // RESOURCEHOLDER_H_INCLUDED
