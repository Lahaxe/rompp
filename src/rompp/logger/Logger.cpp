// Include Project files
#include "rompp/logger/Logger.h"

void initialize_log()
{
    log4cpp::Appender *appender1 = new log4cpp::OstreamAppender("console",
                                                                &std::cout);
    appender1->setLayout(new log4cpp::BasicLayout());

    log4cpp::Category& root = log4cpp::Category::getRoot();

    root.setPriority(level_dictionary["DEBUG"]);

    root.addAppender(appender1);
}

log4cpp::CategoryStream get_logger(const log4cpp::Priority::PriorityLevel &level)
{
    log4cpp::Category& root = log4cpp::Category::getRoot();

    return root << level;
}

log4cpp::CategoryStream log_debug()
{
    return get_logger(log4cpp::Priority::DEBUG);
}

log4cpp::CategoryStream log_info()
{
    return get_logger(log4cpp::Priority::INFO);
}

log4cpp::CategoryStream log_warning()
{
    return get_logger(log4cpp::Priority::WARN);
}

log4cpp::CategoryStream log_error()
{
    return get_logger(log4cpp::Priority::ERROR);
}

log4cpp::CategoryStream log_fatal()
{
    return get_logger(log4cpp::Priority::FATAL);
}
