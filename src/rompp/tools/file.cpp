
#include <fstream>
#include <sstream>

#include <boost/filesystem.hpp>

#include "rompp/exception/Exception.h"
#include "rompp/tools/file.h"

namespace rompp
{

namespace tools
{

std::string read(std::string const & filename)
{
    if (filename.empty())
    {
        throw Exception("Cannot read file without name.");
    }

    if (!boost::filesystem::exists(filename))
    {
        std::stringstream error;
        error << "Cannot read non-existent file '" << filename << "'.";
        throw Exception(error.str());
    }

    std::ifstream data(filename, std::ios_base::in);

    std::string line;
    std::stringstream result;
    bool first = true;
    while(std::getline(data,line))
    {
        if (!first)
        {
            result << "\n";
        }
        result << line;

        first = false;
    }

    return result.str();
}

void write(std::string const & filename, std::string const & content)
{
    std::ofstream outfile(filename, std::ios_base::out);
    outfile.write(content.c_str(), content.size());
    outfile.close();
}

} // namespace tools

} // namespace rompp
