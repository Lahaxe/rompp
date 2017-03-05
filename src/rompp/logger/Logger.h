#ifndef _79859d52_adcd_41c6_8753_15d964e0ad57
#define _79859d52_adcd_41c6_8753_15d964e0ad57

// Include Standard library
#include <string>

const std::string DEFAULT_PATTERN = "%d{%Y-%m-%d %H:%M:%S.%l} - %p: %m%n";

class Logger
{
public:

    static Logger& instance();

    static void delete_instance();

    virtual ~Logger();

    std::string initialize_default(std::string const & priority,
                                   std::string const & pattern = DEFAULT_PATTERN);

    std::string create_stream_appender(std::ostream & stream,
                                     std::string const & priority = "",
                                     std::string const & pattern = DEFAULT_PATTERN,
                                     bool is_default = false);

    std::string create_file_appender(std::string const & filename,
                                   std::string const & priority = "",
                                   std::string const & pattern = DEFAULT_PATTERN,
                                   bool is_default = false);

    void debug(std::string const & text, std::string const & name = "");

    void info(std::string const & text, std::string const & name = "");

    void warning(std::string const & text, std::string const & name = "");

    void error(std::string const & text, std::string const & name = "");

    void fatal(std::string const & text, std::string const & name = "");

protected:

private:
    Logger();

    void _log_data(std::string const & text, std::string const & name = "",
                   std::string const & level = "");

    static Logger* _instance;

    std::string _default_name;

};

#endif // _79859d52_adcd_41c6_8753_15d964e0ad57
