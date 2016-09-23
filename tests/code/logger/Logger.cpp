#define BOOST_TEST_MODULE ModuleLogger
#include <boost/test/unit_test.hpp>

#include "rompp/logger/Logger.h"

struct TestDataLogger
{
    std::stringstream stream;
    std::streambuf* OldBuf;

    TestDataLogger()
    {
        // redirect standard output to stringstream
        OldBuf = std::cout.rdbuf(stream.rdbuf());
    }

    ~TestDataLogger()
    {
        // set the default output
        std::cout.rdbuf(OldBuf);
    }
};

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Logger not Initialize
 */
BOOST_FIXTURE_TEST_CASE(No_Initialization, TestDataLogger)
{
    // Test
    LOGGER_ERROR << " test ";
    LOGGER_WARNING << " test ";
    LOGGER_INFO << " test ";
    LOGGER_DEBUG << " test ";

    BOOST_CHECK_EQUAL(stream.str(), "");
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: InitializeLogger (ERROR)
 */
BOOST_FIXTURE_TEST_CASE(InitializeloggerError, TestDataLogger)
{
    // Initialize logger
    initialize_log();

    // Test
    LOGGER_ERROR << " test ";
    LOGGER_WARNING << " test ";
    LOGGER_INFO << " test ";
    LOGGER_DEBUG << " test ";

    BOOST_REQUIRE(stream.str() != "");

    BOOST_CHECK(stream.str().find("ERROR") != std::string::npos);
    BOOST_CHECK(stream.str().find("WARN") == std::string::npos);
    BOOST_CHECK(stream.str().find("INFO") == std::string::npos);
    BOOST_CHECK(stream.str().find("DEBUG") == std::string::npos);
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: InitializeLogger (WARNING)
 */
BOOST_FIXTURE_TEST_CASE(InitializeloggerWarning, TestDataLogger)
{
    // initialize_log logger
    initialize_log();

    // Test
    LOGGER_ERROR << " test ";
    LOGGER_WARNING << " test ";
    LOGGER_INFO << " test ";
    LOGGER_DEBUG << " test ";

    BOOST_REQUIRE(stream.str() != "");

    BOOST_CHECK(stream.str().find("ERROR") != std::string::npos);
    BOOST_CHECK(stream.str().find("WARN") != std::string::npos);
    BOOST_CHECK(stream.str().find("INFO") == std::string::npos);
    BOOST_CHECK(stream.str().find("DEBUG") == std::string::npos);
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: InitializeLogger (INFO)
 */
BOOST_FIXTURE_TEST_CASE(InitializeloggerInfo, TestDataLogger)
{
    // Initialize logger
    initialize_log();

    // Test
    LOGGER_ERROR << " test ";
    LOGGER_WARNING << " test ";
    LOGGER_INFO << " test ";
    LOGGER_DEBUG << " test ";

    BOOST_REQUIRE(stream.str() != "");

    BOOST_CHECK(stream.str().find("ERROR") != std::string::npos);
    BOOST_CHECK(stream.str().find("WARN") != std::string::npos);
    BOOST_CHECK(stream.str().find("INFO") != std::string::npos);
    BOOST_CHECK(stream.str().find("DEBUG") == std::string::npos);
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: InitializeLogger (DEBUG)
 */
BOOST_FIXTURE_TEST_CASE(InitializeloggerDebug, TestDataLogger)
{
    // Initialize logger
    initialize_log();

    // Test
    LOGGER_ERROR << " test ";
    LOGGER_WARNING << " test ";
    LOGGER_INFO << " test ";
    LOGGER_DEBUG << " test ";

    BOOST_REQUIRE(stream.str() != "");

    BOOST_CHECK(stream.str().find("ERROR") != std::string::npos);
    BOOST_CHECK(stream.str().find("WARN") != std::string::npos);
    BOOST_CHECK(stream.str().find("INFO") != std::string::npos);
    BOOST_CHECK(stream.str().find("DEBUG") != std::string::npos);
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: InitializeLogger (DEFAULT)
 */
BOOST_FIXTURE_TEST_CASE(InitializeLogger_Default, TestDataLogger)
{
    // Initialize logger
    initialize_log();

    // Test
    LOGGER_ERROR << " test ";
    LOGGER_WARNING << " test ";
    LOGGER_INFO << " test ";
    LOGGER_DEBUG << " test ";

    BOOST_REQUIRE(stream.str() != "");

    BOOST_CHECK(stream.str().find("ERROR") != std::string::npos);
    BOOST_CHECK(stream.str().find("WARN") != std::string::npos);
    BOOST_CHECK(stream.str().find("INFO") != std::string::npos);
    BOOST_CHECK(stream.str().find("DEBUG") != std::string::npos);
}
