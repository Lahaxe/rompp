// Include Project files
#include "rompp/logger/Logger.h"

void initialize()
{
    log4cpp::Appender *appender1 = new log4cpp::OstreamAppender("console",
                                                                &std::cout);
    appender1->setLayout(new log4cpp::BasicLayout());

    log4cpp::Category& root = log4cpp::Category::getRoot();

    root.setPriority(level_dictionary["DEBUG"]);

    root.addAppender(appender1);
}

log4cpp::CategoryStream getLogger(const log4cpp::Priority::PriorityLevel &level)
{
    log4cpp::Category& root = log4cpp::Category::getRoot();

    return root << level;
}

log4cpp::CategoryStream loggerDebug()
{
    return getLogger(log4cpp::Priority::DEBUG);
}

log4cpp::CategoryStream loggerInfo()
{
    return getLogger(log4cpp::Priority::INFO);
}

log4cpp::CategoryStream loggerWarning()
{
    return getLogger(log4cpp::Priority::WARN);
}

log4cpp::CategoryStream loggerError()
{
    return getLogger(log4cpp::Priority::ERROR);
}

log4cpp::CategoryStream loggerFatal()
{
    return getLogger(log4cpp::Priority::FATAL);
}
