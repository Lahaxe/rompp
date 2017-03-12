#ifndef _e1f6db1f_914c_4bda_bd2c_5493495cc431
#define _e1f6db1f_914c_4bda_bd2c_5493495cc431

// Include Standard library
#include <memory>
#include <string>

class ConfigurationBase
{
public:
    /// @brief Smart pointer for an instance of ConfigurationBase
    typedef std::shared_ptr<ConfigurationBase> Pointer;
    /// @brief Smart pointer for an instance of ConfigurationBase
    typedef std::shared_ptr<ConfigurationBase const> ConstPointer;

    virtual ~ConfigurationBase();

    virtual void read() = 0;

    virtual void write() = 0;

    virtual bool remove() = 0;

    virtual bool contains_key(std::string const & key) = 0;

    virtual std::string get_value(std::string const & key) const = 0;

    virtual void set_value(std::string const & key,
                           std::string const & value) = 0;

protected:
    ConfigurationBase();

private:

};

#endif // _e1f6db1f_914c_4bda_bd2c_5493495cc431
