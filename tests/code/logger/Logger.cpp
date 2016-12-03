#define BOOST_TEST_MODULE ModuleLogger

#include "FixtureLogger.h"
#include "rompp/logger/Logger.h"


/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Logger not Initialize
 */
BOOST_FIXTURE_TEST_CASE(No_Initialization, FixtureLogger)
{
    // Test
    LOGGER_ERROR << " test ";
    LOGGER_WARNING << " test ";
    LOGGER_INFO << " test ";
    LOGGER_DEBUG << " test ";

    BOOST_CHECK(stream().empty());
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: InitializeLogger (ERROR)
 */
BOOST_FIXTURE_TEST_CASE(InitializeloggerError, FixtureLogger)
{
    // Initialize logger
    initialize_log();

    // Test
    LOGGER_ERROR << " test ";
    LOGGER_WARNING << " test ";
    LOGGER_INFO << " test ";
    LOGGER_DEBUG << " test ";

    BOOST_REQUIRE(!stream().empty());

    BOOST_CHECK(stream().find("ERROR") != std::string::npos);
    BOOST_CHECK(stream().find("WARN") == std::string::npos);
    BOOST_CHECK(stream().find("INFO") == std::string::npos);
    BOOST_CHECK(stream().find("DEBUG") == std::string::npos);
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: InitializeLogger (WARNING)
 */
BOOST_FIXTURE_TEST_CASE(InitializeloggerWarning, FixtureLogger)
{
    // initialize_log logger
    initialize_log();

    // Test
    LOGGER_ERROR << " test ";
    LOGGER_WARNING << " test ";
    LOGGER_INFO << " test ";
    LOGGER_DEBUG << " test ";

    BOOST_REQUIRE(!stream().empty());

    BOOST_CHECK(stream().find("ERROR") != std::string::npos);
    BOOST_CHECK(stream().find("WARN") != std::string::npos);
    BOOST_CHECK(stream().find("INFO") == std::string::npos);
    BOOST_CHECK(stream().find("DEBUG") == std::string::npos);
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: InitializeLogger (INFO)
 */
BOOST_FIXTURE_TEST_CASE(InitializeloggerInfo, FixtureLogger)
{
    // Initialize logger
    initialize_log();

    // Test
    LOGGER_ERROR << " test ";
    LOGGER_WARNING << " test ";
    LOGGER_INFO << " test ";
    LOGGER_DEBUG << " test ";

    BOOST_REQUIRE(!stream().empty());

    BOOST_CHECK(stream().find("ERROR") != std::string::npos);
    BOOST_CHECK(stream().find("WARN") != std::string::npos);
    BOOST_CHECK(stream().find("INFO") != std::string::npos);
    BOOST_CHECK(stream().find("DEBUG") == std::string::npos);
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: InitializeLogger (DEBUG)
 */
BOOST_FIXTURE_TEST_CASE(InitializeloggerDebug, FixtureLogger)
{
    // Initialize logger
    initialize_log();

    // Test
    LOGGER_ERROR << " test ";
    LOGGER_WARNING << " test ";
    LOGGER_INFO << " test ";
    LOGGER_DEBUG << " test ";

    BOOST_REQUIRE(!stream().empty());

    BOOST_CHECK(stream().find("ERROR") != std::string::npos);
    BOOST_CHECK(stream().find("WARN") != std::string::npos);
    BOOST_CHECK(stream().find("INFO") != std::string::npos);
    BOOST_CHECK(stream().find("DEBUG") != std::string::npos);
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: InitializeLogger (DEFAULT)
 */
BOOST_FIXTURE_TEST_CASE(InitializeLogger_Default, FixtureLogger)
{
    // Initialize logger
    initialize_log();

    // Test
    LOGGER_ERROR << " test ";
    LOGGER_WARNING << " test ";
    LOGGER_INFO << " test ";
    LOGGER_DEBUG << " test ";

    BOOST_REQUIRE(!stream().empty());

    BOOST_CHECK(stream().find("ERROR") != std::string::npos);
    BOOST_CHECK(stream().find("WARN") != std::string::npos);
    BOOST_CHECK(stream().find("INFO") != std::string::npos);
    BOOST_CHECK(stream().find("DEBUG") != std::string::npos);
}
