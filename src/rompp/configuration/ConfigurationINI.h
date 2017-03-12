#ifndef _67970433_1f07_4399_b8bf_b3682d8954a3
#define _67970433_1f07_4399_b8bf_b3682d8954a3

// Include Boost files
#include <boost/property_tree/ptree.hpp>

// Include Project files
#include "rompp/configuration/ConfigurationFile.h"

class ConfigurationINI : public ConfigurationFile
{
public:
    /// @brief Smart pointer for an instance of
    typedef std::shared_ptr<ConfigurationINI> Pointer;
    /// @brief Smart pointer for an instance of
    typedef std::shared_ptr<ConfigurationINI const> ConstPointer;

    static Pointer New();

    static Pointer New(std::string const & filename);

    virtual ~ConfigurationINI();

    virtual void read();

    virtual void write();

    virtual bool remove();

    virtual bool contains_key(std::string const & key);

    virtual std::string get_value(std::string const & key) const;

    virtual void set_value(std::string const & key,
                           std::string const & value);

protected:

private:
    ConfigurationINI();

    ConfigurationINI(std::string const & filename);

    boost::property_tree::ptree* _tree;

};

#endif // _67970433_1f07_4399_b8bf_b3682d8954a3
