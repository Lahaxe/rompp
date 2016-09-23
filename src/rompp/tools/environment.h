#ifndef _d5f2840a_fc3e_4a48_97ea_f84a99a77114
#define _d5f2840a_fc3e_4a48_97ea_f84a99a77114

// Include Standard library
#include <string>

namespace rompp
{

namespace tools
{

std::string get_env_variable(const std::string & variable);

void set_env_variable(std::string const & key, 
                      std::string const & value = "");

} // namespace tools

} // namespace rompp

#endif // _d5f2840a_fc3e_4a48_97ea_f84a99a77114