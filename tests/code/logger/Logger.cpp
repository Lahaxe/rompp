#define BOOST_TEST_MODULE ModuleLogger

// Include standard Library
#include <sstream>

// Include Project files
#include "FixtureLogger.h"

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Constructor and Destructor
 */
BOOST_FIXTURE_TEST_CASE(Constructor, FixtureLogger)
{
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Log a message into a default stream
 */
BOOST_FIXTURE_TEST_CASE(LogDefaultStream, FixtureLogger)
{
    std::stringstream stream;
    auto logger = Logger::instance();
    logger.create_stream_appender(stream, "DEBUG", DEFAULT_PATTERN, true);

    logger.debug("My message");

    auto result = stream.str();
    BOOST_CHECK(result.find("DEBUG: My message") != std::string::npos);
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Log a Debug message into a stream
 */
BOOST_FIXTURE_TEST_CASE(LogDebugStream, FixtureLogger)
{
    std::stringstream stream;
    auto logger = Logger::instance();
    auto name = logger.create_stream_appender(stream);

    logger.debug("My message", name);

    auto result = stream.str();
    BOOST_CHECK(result.find("DEBUG: My message") != std::string::npos);
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Log an Information message into a stream
 */
BOOST_FIXTURE_TEST_CASE(LogInfoStream, FixtureLogger)
{
    std::stringstream stream;
    auto logger = Logger::instance();
    auto name = logger.create_stream_appender(stream);

    logger.info("My message", name);

    auto result = stream.str();
    BOOST_CHECK(result.find("INFO: My message") != std::string::npos);
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Log a Warning message into a stream
 */
BOOST_FIXTURE_TEST_CASE(LogWarningStream, FixtureLogger)
{
    std::stringstream stream;
    auto logger = Logger::instance();
    auto name = logger.create_stream_appender(stream);

    logger.warning("My message", name);

    auto result = stream.str();
    BOOST_CHECK(result.find("WARN: My message") != std::string::npos);
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Log an Error message into a stream
 */
BOOST_FIXTURE_TEST_CASE(LogErrorStream, FixtureLogger)
{
    std::stringstream stream;
    auto logger = Logger::instance();
    auto name = logger.create_stream_appender(stream);

    logger.error("My message", name);

    auto result = stream.str();
    BOOST_CHECK(result.find("ERROR: My message") != std::string::npos);
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Log a Fatal message into a stream
 */
BOOST_FIXTURE_TEST_CASE(LogFatalStream, FixtureLogger)
{
    std::stringstream stream;
    auto logger = Logger::instance();
    auto name = logger.create_stream_appender(stream);

    logger.fatal("My message", name);

    auto result = stream.str();
    BOOST_CHECK(result.find("FATAL: My message") != std::string::npos);
}
