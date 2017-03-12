// Include boost files
#include <boost/property_tree/ini_parser.hpp>
#include <boost/filesystem.hpp>

// Include Project files
#include "rompp/configuration/ConfigurationINI.h"
#include "rompp/exception/Exception.h"

ConfigurationINI::Pointer
ConfigurationINI
::New()
{
    return Pointer(new ConfigurationINI());
}

ConfigurationINI::Pointer
ConfigurationINI
::New(std::string const & filename)
{
    return Pointer(new ConfigurationINI(filename));
}

ConfigurationINI
::ConfigurationINI() :
    ConfigurationFile(), _tree(nullptr)
{
    // Nothing else.
}

ConfigurationINI
::ConfigurationINI(std::string const & filename) :
    ConfigurationFile(filename), _tree(nullptr)
{
    // Nothing else.
}

ConfigurationINI
::~ConfigurationINI()
{
    if (this->_tree != nullptr)
    {
        delete this->_tree;
        this->_tree = nullptr;
    }
}

void
ConfigurationINI
::read()
{
    if (this->get_filename().empty())
    {
        throw rompp::Exception("Cannot read file without filename");
    }

    if (!boost::filesystem::exists(boost::filesystem::path(this->get_filename())))
    {
        throw rompp::Exception("Cannot read file");
    }

    this->_tree = new boost::property_tree::ptree();
    boost::property_tree::ini_parser::read_ini(this->get_filename(), *this->_tree);
}


void ConfigurationINI::write()
{
    if (this->get_filename().empty())
    {
        throw rompp::Exception("Cannot write file without filename");
    }

    boost::property_tree::ini_parser::write_ini(this->get_filename(), *this->_tree);
}

bool ConfigurationINI::remove()
{
    bool result = ConfigurationFile::remove();

    if (this->_tree != nullptr)
    {
        delete this->_tree;
        this->_tree = nullptr;
    }

    return result;
}

bool ConfigurationINI::contains_key(std::string const & key)
{
    return (this->_tree->find(key) != this->_tree->not_found());
}

std::string ConfigurationINI::get_value(std::string const & key) const
{
    return this->_tree->get<std::string>(key);
}

void ConfigurationINI::set_value(std::string const & key,
                                 std::string const & value)
{
    this->_tree->put(key, value);
}
