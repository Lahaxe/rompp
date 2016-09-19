#ifndef _043baecf_4391_475c_b2b0_43612fcc6060
#define _043baecf_4391_475c_b2b0_43612fcc6060

// Include boost files
#include <boost/filesystem.hpp>
#include <boost/test/unit_test.hpp>

// Include Project files
#include <EvoCommon/environment.h>

class FixtureBase
{
public:
    FixtureBase() : _temporary_dir("")
    {
        // Nothing to do.
    }

    virtual ~FixtureBase()
    {
        // Suppression du dossier temporaire
        if (!this->_temporary_dir.empty())
        {
            boost::filesystem::remove_all(
                        boost::filesystem::path(_temporary_dir.c_str()));
        }
    }

protected:
    static std::string _getEnvVariable(std::string const & name)
    {
        auto value = rompp::getEnvironmentVariable(name);
        if(value == "")
        {
            BOOST_FAIL(name + " is not defined");
        }
        return value;
    }

    void _createTempDirectory()
    {
        // Creation d'un dossier temporaire
        boost::filesystem::path uniquepath = boost::filesystem::unique_path();
        boost::filesystem::path temp = boost::filesystem::temp_directory_path();
        this->_temporary_dir = boost::filesystem::absolute(temp).string() +
                               uniquepath.filename().string();
        boost::filesystem::create_directory(this->_temporary_dir.c_str());
    }

    std::string _createFile(std::string const & filename,
                            std::string const & content)
    {
        this->_createTempDirectory();

        boost::filesystem::path filepath(this->_temporary_dir.c_str());
        filepath /= filename;
        std::string const filepathstr = filepath.string();
        std::ofstream outfile(filepathstr.c_str());
        outfile.write(content.c_str(), content.size());
        outfile.close();

        return filepathstr;
    }

private:
    std::string _temporary_dir;

};

#endif // _043baecf_4391_475c_b2b0_43612fcc6060
