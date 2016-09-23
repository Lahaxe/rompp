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

void initialize_log();

log4cpp::CategoryStream get_logger(log4cpp::Priority::PriorityLevel const & level);

log4cpp::CategoryStream log_debug();

log4cpp::CategoryStream log_info();

log4cpp::CategoryStream log_warning();

log4cpp::CategoryStream log_error();

log4cpp::CategoryStream log_fatal();

#define LOGGER_DEBUG log_debug()
#define LOGGER_INFO log_info()
#define LOGGER_WARNING log_warning()
#define LOGGER_ERROR log_error()
#define LOGGER_FATAL log_fatal()

#endif // _b6a1a59c_f8d3_41de_80ee_467059a1570f
