#ifndef LOADINGTASK_H_INCLUDED
#define LOADINGTASK_H_INCLUDED

#include "Task.h"


template<typename Identifier>
class LoadingTask : public Task
{
public:
    LoadingTask(Identifier id,const std::string& filename);
    Identifier getId(); // returns Id
    std::string& getFileName(); // returns file name

private:
    Identifier mId;
    std::string& mFileName;
};

#include "LoadingTask.inl"

namespace loading
{
    // function to create a task easily without having to determine typenames
    template<typename Identifier>
    LoadingTask<Identifier> make_task(Identifier id,const std::string& filename)
    {
        return LoadingTask<Identifier>(id, fiename);
    }
}

#endif // LOADINGTASK_H_INCLUDED
