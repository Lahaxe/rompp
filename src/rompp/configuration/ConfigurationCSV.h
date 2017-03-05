#ifndef _06de3182_b2ee_462c_86ed_48a5efe17e96
#define _06de3182_b2ee_462c_86ed_48a5efe17e96

#include <unordered_map>

#include "rompp/configuration/ConfigurationBase.h"

/*class ConfigurationCSV : public ConfigurationBase
{
public:
    /// @brief Smart pointer for an instance of
    typedef std::shared_ptr<ConfigurationCSV> Pointer;
    /// @brief Smart pointer for an instance of
    typedef std::shared_ptr<ConfigurationCSV const> ConstPointer;

    static Pointer New();

    virtual ~ConfigurationCSV();

    std::string get_line_separator() const;

    void set_line_separator(std::string const & separator);

    std::string get_data_separator() const;

    void set_data_separator(std::string const & separator);

    virtual void load(std::string const & config);

    virtual void load_file(std::string const & filename);

    virtual void save();

    virtual void save(std::string const & filename);

    virtual bool contains_key(std::string const & key);

    virtual std::string get_value(std::string const & key) const;

    virtual void set_value(std::string const & key,
                           std::string const & value);

protected:

private:
    ConfigurationCSV();

    std::string _line_separator;

    std::string _data_separator;

    std::unordered_map<std::string, std::string> _values;

};*/

#endif // _06de3182_b2ee_462c_86ed_48a5efe17e96
