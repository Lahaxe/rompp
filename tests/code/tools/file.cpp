#define BOOST_TEST_MODULE ModuleFile
// Include boost files
#include <boost/test/unit_test.hpp>

// Include Project files
#include "rompp/exception/Exception.h"
#include "rompp/tools/file.h"

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Check the functions Read and Write file
 */
BOOST_AUTO_TEST_CASE(ReadWrite)
{
    std::string const filename = "TestFile_ReadWrite.txt";
    std::string const text = "Hello\nWorld!";
    rompp::tools::write(filename, text);

    auto read_text = rompp::tools::read(filename);
    BOOST_CHECK_EQUAL(read_text, text);

}

/******************************* TEST Error ************************************/
/**
 * Error test case: Read with empty filename
 */
BOOST_AUTO_TEST_CASE(ReadWithoutFilename)
{
    BOOST_CHECK_EXCEPTION(rompp::tools::read(""),
                          rompp::Exception,
                          [](rompp::Exception const & exc)
                              {
                                  return std::string(exc.what()) ==
                                         std::string("Cannot read file without name.");
                              });
}

/******************************* TEST Error ************************************/
/**
 * Error test case: Read missing file
 */
BOOST_AUTO_TEST_CASE(ReadFileMissing)
{
    BOOST_CHECK_EXCEPTION(rompp::tools::read("missing_file.txt"),
                          rompp::Exception,
                          [](rompp::Exception const & exc)
                              {
                                  return std::string(exc.what()) ==
                                         std::string("Cannot read non-existent file 'missing_file.txt'.");
                              });
}
