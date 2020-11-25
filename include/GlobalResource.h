#ifndef GLOBALRESOURCE_H_INCLUDED
#define GLOBALRESOURCE_H_INCLUDED

#include <string>


class GlobalResource final
{
private:
    GlobalResource();

public:
    // window setup
    static const std::string WINDOW_TITLE;

    // stats
    static const std::string STAT_VERSION;
    static const std::string STAT_FPS;

    // utility files
    static const std::string FILE_LOG;
    static const std::string FILE_CONFIG;

    // log messages
    static const std::string LOG_INIT;
    static const std::string LOG_STOP;
    static const std::string LOG_SPLASH;
    static const std::string LOG_RUN;
    static const std::string LOG_VERSION;
    static const std::string LOG_MISSING;
    static const std::string LOG_LOADED;
    static const std::string LOG_UNLOADED;
    static const std::string LOG_OPTIONS_LOADED;
    static const std::string LOG_OPTIONS_SAVED;

    // texts
    static const std::string TEXT_TITLE;
    static const std::string TEXT_CONTINUE;

    // fonts
    static const std::string FONT_MAIN;

    // textures
    static const std::string TEX_SPLASH;
};

#endif // GLOBALRESOURCE_H_INCLUDED