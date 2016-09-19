#ifndef _b6a1a59c_f8d3_41de_80ee_467059a1570f
#define _b6a1a59c_f8d3_41de_80ee_467059a1570f

// Include Standard library
#include <map>
#include <string>

#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>

static std::map<std::string, log4cpp::Priority::PriorityLevel> level_dictionary =
{
    { "", log4cpp::Priority::DEBUG },       // Default
    { "FATAL", log4cpp::Priority::FATAL },
    { "ERROR", log4cpp::Priority::ERROR },
    { "WARNING", log4cpp::Priority::WARN },
    { "INFO", log4cpp::Priority::INFO },
    { "DEBUG", log4cpp::Priority::DEBUG }
};

void initialize();

log4cpp::CategoryStream getLogger(log4cpp::Priority::PriorityLevel const & level);

log4cpp::CategoryStream loggerDebug();

log4cpp::CategoryStream loggerInfo();

log4cpp::CategoryStream loggerWarning();

log4cpp::CategoryStream loggerError();

log4cpp::CategoryStream loggerFatal();

#define LOGGER_DEBUG loggerDebug()
#define LOGGER_INFO loggerInfo()
#define LOGGER_WARNING loggerWarning()
#define LOGGER_ERROR loggerError()
#define LOGGER_FATAL loggerFatal()

#endif // _b6a1a59c_f8d3_41de_80ee_467059a1570f
