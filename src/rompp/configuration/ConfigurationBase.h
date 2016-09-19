#ifndef _e1f6db1f_914c_4bda_bd2c_5493495cc431
#define _e1f6db1f_914c_4bda_bd2c_5493495cc431

// Include Standard library
#include <memory>
#include <string>

class ConfigurationBase
{
public:
    ConfigurationBase();

    virtual ~ConfigurationBase();

    std::string get_filename() const;

    void set_filename(std::string const & new_name);

    virtual void load(std::string const & config) = 0;

    virtual void load_file(std::string const & filename) = 0;

    virtual void save() = 0;

    virtual void save(std::string const & filename) = 0;

    virtual bool contains_key(std::string const & key) = 0;

    virtual std::string get_value(std::string const & key) const = 0;

    virtual void set_value(std::string const & key,
                           std::string const & value) = 0;

protected:

private:
    std::string _filename;

};

#endif // _e1f6db1f_914c_4bda_bd2c_5493495cc431
