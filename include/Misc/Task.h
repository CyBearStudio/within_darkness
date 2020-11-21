#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED


class Task
{
public:
    virtual auto getId();
    virtual std::string& getFileName();
}

#endif // TASK_H_INCLUDED
