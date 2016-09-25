#ifndef _956566d2_6ef8_4b99_9b65_52ee2ddf5ac6
#define _956566d2_6ef8_4b99_9b65_52ee2ddf5ac6

#include <memory>
#include <string>
#include <vector>

namespace rompp
{

namespace files
{

class CSVFile
{
public:
    /// @brief Smart pointer for an instance of
    typedef std::shared_ptr<CSVFile> Pointer;
    /// @brief Smart pointer for an instance of
    typedef std::shared_ptr<CSVFile const> ConstPointer;

    static Pointer New();

    virtual ~CSVFile();

    std::string get_line_separator() const;

    void set_line_separator(std::string const & separator);

    std::string get_column_separator() const;

    void set_column_separator(std::string const & separator);
    
    std::vector<std::vector<std::string>> const & get_cells() const;
    
    std::string get_cell(unsigned int line, unsigned int column) const;
    
    std::vector<std::string> get_line(unsigned int line) const;
    
    std::vector<std::string> get_column(unsigned int column) const;

    void load_buffer(std::string const & buffer);

    void load_file(std::string const & filename);

    void save(std::string const & filename);

protected:

private:
    CSVFile();

    std::string _line_separator;

    std::string _column_separator;

    /// @brief Cells ordered by lines and columns
    std::vector<std::vector<std::string>> _cells;

};

} // namespace files

} // namespace rompp

#endif // _956566d2_6ef8_4b99_9b65_52ee2ddf5ac6
