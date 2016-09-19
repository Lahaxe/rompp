#include "rompp/configuration/ConfigurationBase.h"

ConfigurationBase
::ConfigurationBase() :
    _filename("")
{
    // Nothing else.
}

ConfigurationBase
::~ConfigurationBase()
{
    // Nothing to do.
}

std::string
ConfigurationBase
::get_filename() const
{
    return this->_filename;
}

void
ConfigurationBase
::set_filename(std::string const & new_name)
{
    this->_filename = new_name;
}
