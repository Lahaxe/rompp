// Include Standard Library
#include <map>

// Include Boost files
#include <boost/date_time/posix_time/posix_time.hpp>

// Include Log4Cpp files
#include <log4cpp/Category.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>

// Include Project files
#include "rompp/logger/Logger.h"

std::map<std::string, log4cpp::Priority::PriorityLevel> level_dictionary =
{
    { "", log4cpp::Priority::NOTSET }, // Default
    { "EMERGENCY", log4cpp::Priority::EMERG },
    { "FATAL", log4cpp::Priority::FATAL },
    { "CRITICAL", log4cpp::Priority::CRIT },
    { "ERROR", log4cpp::Priority::ERROR },
    { "WARNING", log4cpp::Priority::WARN },
    { "NOTICE", log4cpp::Priority::NOTICE },
    { "INFO", log4cpp::Priority::INFO },
    { "DEBUG", log4cpp::Priority::DEBUG }
};

Logger* Logger::_instance = nullptr;

Logger&
Logger
::instance()
{
    if (Logger::_instance == nullptr)
    {
        Logger::_instance = new Logger();
    }

    return *Logger::_instance;
}

void
Logger
::delete_instance()
{
    if (Logger::_instance != nullptr)
    {
        delete Logger::_instance;
        Logger::_instance = nullptr;
    }
}

Logger
::Logger(): _default_name("")
{
    // Nothing to do.
}

Logger
::~Logger()
{
    log4cpp::Category::shutdown();
}

std::string
Logger
::initialize_default(std::string const & priority, std::string const & pattern)
{
    return create_stream_appender(std::cout, priority, pattern, true);
}

std::string
Logger
::create_stream_appender(std::ostream & stream, std::string const & priority,
                       std::string const & pattern,
                       bool is_default)
{
    auto datetime = boost::posix_time::to_iso_string(
                boost::posix_time::second_clock::local_time());

    std::string name = "stream_" + datetime;
    log4cpp::Appender * appender = new log4cpp::OstreamAppender(name, &stream);

    auto layout = new log4cpp::PatternLayout();
    layout->setConversionPattern(pattern);
    appender->setLayout(layout);

    log4cpp::Category& category = is_default ? log4cpp::Category::getRoot() :
                                               log4cpp::Category::getInstance(name);

    category.setPriority(level_dictionary[priority]);

    category.addAppender(appender);

    if (is_default)
    {
        this->_default_name = name;
    }

    return name;
}

std::string
Logger
::create_file_appender(std::string const & filename, std::string const & priority,
                       std::string const & pattern,
                       bool is_default)
{
    auto datetime = boost::posix_time::to_iso_string(
                boost::posix_time::second_clock::local_time());

    std::string name = "file_" + datetime;
    log4cpp::Appender * appender = new log4cpp::FileAppender(name, filename);

    auto layout = new log4cpp::PatternLayout();
    layout->setConversionPattern(pattern);
    appender->setLayout(layout);

    log4cpp::Category& category = is_default ? log4cpp::Category::getRoot() :
                                               log4cpp::Category::getInstance(name);

    category.setPriority(level_dictionary[priority]);

    category.addAppender(appender);

    if (is_default)
    {
        this->_default_name = name;
    }

    return name;
}

void
Logger
::debug(std::string const & text, std::string const & name)
{
    this->_log_data(text, name, "DEBUG");
}

void
Logger
::info(std::string const & text, std::string const & name)
{
    this->_log_data(text, name, "INFO");
}

void
Logger
::warning(std::string const & text, std::string const & name)
{
    this->_log_data(text, name, "WARNING");
}

void
Logger
::error(std::string const & text, std::string const & name)
{
    this->_log_data(text, name, "ERROR");
}

void
Logger
::fatal(std::string const & text, std::string const & name)
{
    this->_log_data(text, name, "FATAL");
}

void
Logger
::_log_data(std::string const & text, std::string const & name,
            std::string const & level)
{
    bool is_default = (name.empty() || name == this->_default_name);

    log4cpp::Category& category = is_default ? log4cpp::Category::getRoot() :
                                               log4cpp::Category::getInstance(name);

    category << level_dictionary[level] << text;
}
