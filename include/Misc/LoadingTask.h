#ifndef LOADINGTASK_H_INCLUDED
#define LOADINGTASK_H_INCLUDED

#include "Task.h"


template<typename Identifier>
class LoadingTask : public Task
{
public:
    LoadingTask(Identifier id, std::string filename);
    Identifier getId();
    std::string& getFileName();

private:
    Identifier mId;
    std::string& mFileName;
};

#include "LoadingTask.inl"

namespace loading
{
    template<typename Identifier>
    LoadingTask<Identifier> make_task(Identifier id, std::string filename)
    {
        return LoadingTask<Identifier>(id, fiename);
    }
}

#endif // LOADINGTASK_H_INCLUDED
