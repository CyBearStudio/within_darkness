

template<typename Identifier>
LoadingTask<Identifier>::LoadingTask(Identifier id, const std::string& filename) : mId(id), mFileName(filename)
{
}

template<typename Identifier>
Identifier LoadingTask<Identifier>::getId() 
{
    return mId;
}

template<typename Identifier>
std::string& LoadingTask<Identifier>::getFileName() 
{
    return mFileName;
}
