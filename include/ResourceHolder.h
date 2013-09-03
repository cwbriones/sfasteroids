#ifndef RESOURCEHOLDER_H_
#define RESOURCEHOLDER_H_

#include <map>
#include <memory>
#include <string>

template <typename Resource, typename Identifier>
class ResourceHolder{
    public:
        void load(Identifier id, const std::string& filename);
        Resource& get(Identifier id);
        const Resource& get(Identifier id) const;
    private:
        std::map<Identifier, std::unique_ptr<Resource>> resource_map_;
};

#include "ResourceHolder.inl"

#endif /* RESOURCEHOLDER_H_ */
