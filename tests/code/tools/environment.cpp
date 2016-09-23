#define BOOST_TEST_MODULE ModuleEnvironment
// Include boost files
#include <boost/test/unit_test.hpp>

// Include Project files
#include "rompp/tools/environment.h"

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Check the functions getenv and setenv
 */
BOOST_AUTO_TEST_CASE(GetenvSetenv)
{
    std::string const varname = "MY_VARIABLE";
    BOOST_CHECK_EQUAL(rompp::tools::get_env_variable(varname), "");
    rompp::tools::set_env_variable(varname, "my_value");
    BOOST_CHECK_EQUAL(rompp::tools::get_env_variable(varname), "my_value");
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Check the functions setenv with empty key
 */
BOOST_AUTO_TEST_CASE(SetenvWithEmptyKey)
{
    // No error
    rompp::tools::set_env_variable("", "my_value");
}
