// Include Project files
#include "rompp/tools/environment.h"

#ifndef WIN32
#include <cstdlib>
#endif

namespace rompp
{

namespace tools
{

std::string get_env_variable(std::string const & variable)
{
    char* value = getenv(variable.c_str());
    if(value == nullptr)
    {
        return "";
    }
    return value;
}

void set_env_variable(std::string const & key, std::string const & value)
{
    if (key.empty())
    {
        return;
    }

#ifdef WIN32
    _putenv_s(key.c_str(), value.c_str());
#else
    setenv(key.c_str(), value.c_str(), 1);
#endif
}

} // namespace tools

} // namespace rompp
