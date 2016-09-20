// Include Project files
#include "rompp/tools/environment.h"

#ifndef WIN32
#include <cstdlib>
#include <sstream>
#endif

namespace rompp
{

namespace tools
{

std::string getEnvironmentVariable(const std::string & variable)
{
	char* value = getenv(variable.c_str());
	if(value == nullptr)
	{
		return "";
	}
	return value;
}

void setEnvironmentVariable(std::string const & key, std::string const & value)
{
	if (key.empty())
	{
		return;
	}

#ifdef WIN32
	_putenv_s(key.c_str(), value.c_str());
#else
	std::stringstream env_var;
	env_var << key << "=" << "value";
	char* var = (char*)env_var.str().c_str();
	putenv(var);
#endif
}

} // namespace tools

} // namespace rompp
