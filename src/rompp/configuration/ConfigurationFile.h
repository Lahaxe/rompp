#ifndef _ee424dad_014f_4ce2_b708_4cef3b23c6e6
#define _ee424dad_014f_4ce2_b708_4cef3b23c6e6

// Include Project files
#include "rompp/configuration/ConfigurationBase.h"

class ConfigurationFile : public ConfigurationBase
{
public:
    /// @brief Smart pointer for an instance of ConfigurationBase
    typedef std::shared_ptr<ConfigurationFile> Pointer;
    /// @brief Smart pointer for an instance of ConfigurationBase
    typedef std::shared_ptr<ConfigurationFile const> ConstPointer;

    virtual ~ConfigurationFile();

    std::string get_filename() const;

    void set_filename(std::string const & filename);

protected:
    ConfigurationFile();

    ConfigurationFile(std::string const & filename);

private:
    std::string _filename;

};

#endif // _ee424dad_014f_4ce2_b708_4cef3b23c6e6
