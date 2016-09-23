#define BOOST_TEST_MODULE ModuleException
#include <boost/test/unit_test.hpp>

#include "rompp/exception/Exception.h"

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Constructor / Destructor
 */
BOOST_AUTO_TEST_CASE(Constructor)
{
    auto exception = new rompp::Exception("mon message");
    BOOST_REQUIRE(exception != nullptr);

    BOOST_CHECK_EQUAL(std::string(exception->what()), "mon message");

    delete exception;
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Throw and Catch Exception
 */
BOOST_AUTO_TEST_CASE(ThrowException)
{
    BOOST_CHECK_EXCEPTION(throw rompp::Exception("mon message"), 
                          rompp::Exception, 
                          [](rompp::Exception const & exc)
                              { 
                                  return std::string(exc.what()) == 
                                         std::string("mon message");
                              });
}
