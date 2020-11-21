#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED


class Task
{
    virtual auto getId();
    virtual std::string& getFileName();
}

#endif // TASK_H_INCLUDED
