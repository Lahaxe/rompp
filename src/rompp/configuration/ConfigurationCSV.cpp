#include <fstream>

#include "rompp/configuration/ConfigurationCSV.h"
#include "rompp/files/CSVFile.h"
/*
ConfigurationCSV::Pointer
ConfigurationCSV
::New()
{
    return Pointer(new ConfigurationCSV());
}

ConfigurationCSV
::ConfigurationCSV() :
    ConfigurationBase(), _line_separator("\n"), _data_separator("\t")
{
    // Nothing else.
}

ConfigurationCSV
::~ConfigurationCSV()
{
    // Nothing to do.
}

std::string
ConfigurationCSV
::get_line_separator() const
{
    return this->_line_separator;
}

void
ConfigurationCSV
::set_line_separator(std::string const & separator)
{
    this->_line_separator = separator;
}

std::string
ConfigurationCSV
::get_data_separator() const
{
    return this->_data_separator;
}

void
ConfigurationCSV
::set_data_separator(std::string const & separator)
{
    this->_data_separator = separator;
}

void
ConfigurationCSV
::load(std::string const & config)
{

}

void
ConfigurationCSV
::load_file(std::string const & filename)
{
    auto used_file = filename.empty() ? this->get_filename() : filename;
    std::ifstream stream(used_file.c_str(), std::ifstream::in);

    stream.close();
}

void
ConfigurationCSV
::save()
{

}

void
ConfigurationCSV
::save(std::string const & filename)
{

}

bool
ConfigurationCSV
::contains_key(std::string const & key)
{
    return false;
}

std::string
ConfigurationCSV
::get_value(std::string const & key) const
{
    return "";
}

void
ConfigurationCSV
::set_value(std::string const & key, std::string const & value)
{

}
*/
