// Include Project files
#include "rompp/configuration/ConfigurationFile.h"

ConfigurationFile
::ConfigurationFile():
    ConfigurationBase(), _filename("")
{
    // Nothing else.
}

ConfigurationFile
::ConfigurationFile(std::string const & filename):
    ConfigurationBase(), _filename(filename)
{
    // Nothing else.
}

ConfigurationFile
::~ConfigurationFile()
{
    // Nothing to do.
}

std::string
ConfigurationFile
::get_filename() const
{
    return this->_filename;
}

void
ConfigurationFile
::set_filename(std::string const & filename)
{
    this->_filename = filename;
}
