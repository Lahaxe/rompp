#ifndef _3084b0f6_5ec8_4604_9261_9dcb25fcf73b
#define _3084b0f6_5ec8_4604_9261_9dcb25fcf73b

// Include Standard library
#include <string>

namespace rompp
{

namespace tools
{

std::string get_env_variable(std::string const & variable);

void set_env_variable(std::string const & key,
                      std::string const & value = "");

} // namespace tools

} // namespace rompp

#endif // _3084b0f6_5ec8_4604_9261_9dcb25fcf73b
