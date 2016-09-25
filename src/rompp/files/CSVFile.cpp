
#include <sstream>

#include <boost/algorithm/string.hpp>

#include "rompp/exception/Exception.h"
#include "rompp/files/CSVFile.h"
#include "rompp/tools/file.h"

namespace rompp
{

namespace files
{

CSVFile::Pointer
CSVFile
::New()
{
    return Pointer(new CSVFile());
}

CSVFile
::CSVFile() :
    _line_separator("\n"), _column_separator("\t"), _cells({})
{
    // Nothing else.
}

CSVFile
::~CSVFile()
{
    // Nothing to do.
}

std::string
CSVFile
::get_line_separator() const
{
    return this->_line_separator;
}

void
CSVFile
::set_line_separator(std::string const & separator)
{
    this->_line_separator = separator;
}

std::string
CSVFile
::get_column_separator() const
{
    return this->_column_separator;
}

void
CSVFile
::set_column_separator(std::string const & separator)
{
    this->_column_separator = separator;
}

std::vector<std::vector<std::string> > const &
CSVFile
::get_cells() const
{
    return this->_cells;
}

std::string
CSVFile
::get_cell(unsigned int line, unsigned int column) const
{
    if (line < this->_cells.size() && column < this->_cells[line].size())
    {
        return this->_cells[line][column];
    }

    std::stringstream error;
    error << "Unknown cell [" << line << "," << column << "].";
    throw Exception(error.str());
}

std::vector<std::string>
CSVFile
::get_line(unsigned int line) const
{
    if (line >= this->_cells.size())
    {
        std::stringstream error;
        error << "Unknown line '" << line << "'.";
        throw Exception(error.str());
    }

    return this->_cells[line];
}

std::vector<std::string>
CSVFile
::get_column(unsigned int column) const
{
    std::vector<std::string> cols;
    bool sizeok = false;
    for (auto line : this->_cells)
    {
        if (column < line.size())
        {
            sizeok = true;
            cols.push_back(line[column]);
        }
        else
        {
            cols.push_back("");
        }
    }

    if (!sizeok)
    {
        std::stringstream error;
        error << "Unknown column '" << column << "'.";
        throw Exception(error.str());
    }

    return cols;
}

void CSVFile::load_buffer(std::string const & buffer)
{
    this->_cells.clear();

    std::vector<std::string> lines;
    boost::split(lines, buffer, boost::is_any_of(this->get_line_separator()));

    for (auto line : lines)
    {
        this->_cells.push_back({});

        std::vector<std::string> columns;
        boost::split(columns, line,
                     boost::is_any_of(this->get_column_separator()));

        for (auto column : columns)
        {
            this->_cells[this->_cells.size()-1].push_back(column);
        }
    }
}

void CSVFile::load_file(std::string const & filename)
{
    this->_cells.clear();

    this->load_buffer(tools::read(filename));
}

void CSVFile::save(std::string const & filename)
{
    std::stringstream file;

    bool first_line = true;
    for (auto line : this->_cells)
    {
        if (!first_line)
        {
            file << this->get_line_separator();
        }

        bool first_column = true;
        for (auto column : line)
        {
            if (!first_column)
            {
                file << this->get_column_separator();
            }

            file << column;

            first_column = false;
        }

        first_line = false;
    }

    tools::write(filename, file.str());
}

} // namespace files

} // namespace rompp
