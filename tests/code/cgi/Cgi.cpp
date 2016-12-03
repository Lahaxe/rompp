#define BOOST_TEST_MODULE ModuleCgi
// Include boost files
#include <boost/test/unit_test.hpp>

// Include Project files
#include "rompp/cgi/Cgi.h"
#include "rompp/tools/environment.h"

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Constructor / Destructor
 */
BOOST_AUTO_TEST_CASE(Constructor)
{
    auto cgi = new rompp::cgi::Cgi();
    BOOST_REQUIRE(cgi != nullptr);
    delete cgi;
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Accessors
 */
BOOST_AUTO_TEST_CASE(Accessors)
{
    rompp::cgi::Cgi cgi;

    BOOST_CHECK_EQUAL(cgi.get_accept(), "");
    BOOST_CHECK_EQUAL(cgi.get_accept_language_string(), "");
    BOOST_CHECK_EQUAL(cgi.get_auth_type(), "");
    BOOST_CHECK_EQUAL(cgi.get_content_length(), 0);
    BOOST_CHECK_EQUAL(cgi.get_content_type(), "");
    BOOST_CHECK_EQUAL(cgi.get_gateway_interface(), "");
    BOOST_CHECK_EQUAL(cgi.get_input_content(), "");
    BOOST_CHECK_EQUAL(cgi.get_path_info(), "");
    BOOST_CHECK_EQUAL(cgi.get_path_translated(), "");
    BOOST_CHECK_EQUAL(cgi.get_query_string(), "");
    BOOST_CHECK_EQUAL(cgi.get_redirect_request(), "");
    BOOST_CHECK_EQUAL(cgi.get_redirect_status(), "");
    BOOST_CHECK_EQUAL(cgi.get_redirect_URL(), "");
    BOOST_CHECK_EQUAL(cgi.get_referrer(), "");
    BOOST_CHECK_EQUAL(cgi.get_remote_addr(), "");
    BOOST_CHECK_EQUAL(cgi.get_remote_host(), "");
    BOOST_CHECK_EQUAL(cgi.get_remote_ident(), "");
    BOOST_CHECK_EQUAL(cgi.get_remote_user(), "");
    BOOST_CHECK_EQUAL(cgi.get_request_method(), "");
    BOOST_CHECK_EQUAL(cgi.get_script_name(), "");
    BOOST_CHECK_EQUAL(cgi.get_server_name(), "");
    BOOST_CHECK_EQUAL(cgi.get_server_port(), 0);
    BOOST_CHECK_EQUAL(cgi.get_server_protocol(), "");
    BOOST_CHECK_EQUAL(cgi.get_server_software(), "");
    BOOST_CHECK_EQUAL(cgi.get_user_agent(), "");
    BOOST_CHECK_EQUAL(cgi.get_using_HTTPS(), false);

    cgi.set_accept("accept");
    cgi.set_accept_language_string("accept_language_string");
    cgi.set_auth_type("auth_type");
    cgi.set_content_length(10);
    cgi.set_content_type("content_type");
    cgi.set_gateway_interface("gateway_interface");
    cgi.set_input_content("input_content");
    cgi.set_path_info("path_info");
    cgi.set_path_translated("path_translated");
    cgi.set_query_string("query_string");
    cgi.set_redirect_request("redirect_request");
    cgi.set_redirect_status("redirect_status");
    cgi.set_redirect_URL("redirect_URL");
    cgi.set_referrer("referrer");
    cgi.set_remote_addr("remote_addr");
    cgi.set_remote_host("remote_host");
    cgi.set_remote_ident("remote_ident");
    cgi.set_remote_user("remote_user");
    cgi.set_request_method("request_method");
    cgi.set_script_name("script_name");
    cgi.set_server_name("server_name");
    cgi.set_server_port(10);
    cgi.set_server_protocol("server_protocol");
    cgi.set_server_software("server_software");
    cgi.set_user_agent("user_agent");
    cgi.set_using_HTTPS(true);

    BOOST_CHECK_EQUAL(cgi.get_accept(), "accept");
    BOOST_CHECK_EQUAL(cgi.get_accept_language_string(), "accept_language_string");
    BOOST_CHECK_EQUAL(cgi.get_auth_type(), "auth_type");
    BOOST_CHECK_EQUAL(cgi.get_content_length(), 10);
    BOOST_CHECK_EQUAL(cgi.get_content_type(), "content_type");
    BOOST_CHECK_EQUAL(cgi.get_gateway_interface(), "gateway_interface");
    BOOST_CHECK_EQUAL(cgi.get_input_content(), "input_content");
    BOOST_CHECK_EQUAL(cgi.get_path_info(), "path_info");
    BOOST_CHECK_EQUAL(cgi.get_path_translated(), "path_translated");
    BOOST_CHECK_EQUAL(cgi.get_query_string(), "query_string");
    BOOST_CHECK_EQUAL(cgi.get_redirect_request(), "redirect_request");
    BOOST_CHECK_EQUAL(cgi.get_redirect_status(), "redirect_status");
    BOOST_CHECK_EQUAL(cgi.get_redirect_URL(), "redirect_URL");
    BOOST_CHECK_EQUAL(cgi.get_referrer(), "referrer");
    BOOST_CHECK_EQUAL(cgi.get_remote_addr(), "remote_addr");
    BOOST_CHECK_EQUAL(cgi.get_remote_host(), "remote_host");
    BOOST_CHECK_EQUAL(cgi.get_remote_ident(), "remote_ident");
    BOOST_CHECK_EQUAL(cgi.get_remote_user(), "remote_user");
    BOOST_CHECK_EQUAL(cgi.get_request_method(), "request_method");
    BOOST_CHECK_EQUAL(cgi.get_script_name(), "script_name");
    BOOST_CHECK_EQUAL(cgi.get_server_name(), "server_name");
    BOOST_CHECK_EQUAL(cgi.get_server_port(), 10);
    BOOST_CHECK_EQUAL(cgi.get_server_protocol(), "server_protocol");
    BOOST_CHECK_EQUAL(cgi.get_server_software(), "server_software");
    BOOST_CHECK_EQUAL(cgi.get_user_agent(), "user_agent");
    BOOST_CHECK_EQUAL(cgi.get_using_HTTPS(), true);
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Read CGI parameters
 */
BOOST_AUTO_TEST_CASE(ReadCGI)
{
    // Prepare environment
    rompp::tools::set_env_variable(rompp::cgi::AUTH_TYPE, "auth_type");
    rompp::tools::set_env_variable(rompp::cgi::CONTENT_LENGTH, "0");
    rompp::tools::set_env_variable(rompp::cgi::CONTENT_TYPE, "content_type");
    rompp::tools::set_env_variable(rompp::cgi::GATEWAY_INTERFACE,
                                   "gateway_interface");
    rompp::tools::set_env_variable(rompp::cgi::HTTPS, "ON");
    rompp::tools::set_env_variable(rompp::cgi::HTTP_ACCEPT, "accept");
    rompp::tools::set_env_variable(rompp::cgi::HTTP_ACCEPT_LANGUAGE,
                                   "accept_language_string");
    rompp::tools::set_env_variable(rompp::cgi::HTTP_REFERER, "referrer");
    rompp::tools::set_env_variable(rompp::cgi::HTTP_USER_AGENT, "user_agent");
    rompp::tools::set_env_variable(rompp::cgi::PATH_INFO, "path_info");
    rompp::tools::set_env_variable(rompp::cgi::PATH_TRANSLATED,
                                   "path_translated");
    rompp::tools::set_env_variable(rompp::cgi::QUERY_STRING, "query_string");
    rompp::tools::set_env_variable(rompp::cgi::REDIRECT_REQUEST,
                                   "redirect_request");
    rompp::tools::set_env_variable(rompp::cgi::REDIRECT_STATUS,
                                   "redirect_status");
    rompp::tools::set_env_variable(rompp::cgi::REDIRECT_URL, "redirect_URL");
    rompp::tools::set_env_variable(rompp::cgi::REMOTE_ADDR, "remote_addr");
    rompp::tools::set_env_variable(rompp::cgi::REMOTE_HOST, "remote_host");
    rompp::tools::set_env_variable(rompp::cgi::REMOTE_IDENT, "remote_ident");
    rompp::tools::set_env_variable(rompp::cgi::REMOTE_USER, "remote_user");
    rompp::tools::set_env_variable(rompp::cgi::REQUEST_METHOD, "request_method");
    rompp::tools::set_env_variable(rompp::cgi::SCRIPT_NAME, "script_name");
    rompp::tools::set_env_variable(rompp::cgi::SERVER_NAME, "server_name");
    rompp::tools::set_env_variable(rompp::cgi::SERVER_PORT, "10");
    rompp::tools::set_env_variable(rompp::cgi::SERVER_PROTOCOL,
                                   "server_protocol");
    rompp::tools::set_env_variable(rompp::cgi::SERVER_SOFTWARE,
                                   "server_software");

    // Warning: cannot test Input Content

    // Create object CGI
    rompp::cgi::Cgi cgi;
    // Read data
    cgi.read();

    // Test result
    BOOST_CHECK_EQUAL(cgi.get_accept(), "accept");
    BOOST_CHECK_EQUAL(cgi.get_accept_language_string(), "accept_language_string");
    BOOST_CHECK_EQUAL(cgi.get_auth_type(), "auth_type");
    BOOST_CHECK_EQUAL(cgi.get_content_length(), 0);
    BOOST_CHECK_EQUAL(cgi.get_content_type(), "content_type");
    BOOST_CHECK_EQUAL(cgi.get_gateway_interface(), "gateway_interface");
    BOOST_CHECK_EQUAL(cgi.get_input_content(), "");
    BOOST_CHECK_EQUAL(cgi.get_path_info(), "path_info");
    BOOST_CHECK_EQUAL(cgi.get_path_translated(), "path_translated");
    BOOST_CHECK_EQUAL(cgi.get_query_string(), "query_string");
    BOOST_CHECK_EQUAL(cgi.get_redirect_request(), "redirect_request");
    BOOST_CHECK_EQUAL(cgi.get_redirect_status(), "redirect_status");
    BOOST_CHECK_EQUAL(cgi.get_redirect_URL(), "redirect_URL");
    BOOST_CHECK_EQUAL(cgi.get_referrer(), "referrer");
    BOOST_CHECK_EQUAL(cgi.get_remote_addr(), "remote_addr");
    BOOST_CHECK_EQUAL(cgi.get_remote_host(), "remote_host");
    BOOST_CHECK_EQUAL(cgi.get_remote_ident(), "remote_ident");
    BOOST_CHECK_EQUAL(cgi.get_remote_user(), "remote_user");
    BOOST_CHECK_EQUAL(cgi.get_request_method(), "request_method");
    BOOST_CHECK_EQUAL(cgi.get_script_name(), "script_name");
    BOOST_CHECK_EQUAL(cgi.get_server_name(), "server_name");
    BOOST_CHECK_EQUAL(cgi.get_server_port(), 10);
    BOOST_CHECK_EQUAL(cgi.get_server_protocol(), "server_protocol");
    BOOST_CHECK_EQUAL(cgi.get_server_software(), "server_software");
    BOOST_CHECK_EQUAL(cgi.get_user_agent(), "user_agent");
    BOOST_CHECK_EQUAL(cgi.get_using_HTTPS(), true);
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: Write CGI parameters
 */
BOOST_AUTO_TEST_CASE(WriteCGI)
{
    // Create CGI
    rompp::cgi::Cgi cgi;
    cgi.set_accept("accept");
    cgi.set_accept_language_string("accept_language_string");
    cgi.set_auth_type("auth_type");
    cgi.set_content_length(0);
    cgi.set_content_type("content_type");
    cgi.set_gateway_interface("gateway_interface");
    cgi.set_input_content("");
    cgi.set_path_info("path_info");
    cgi.set_path_translated("path_translated");
    cgi.set_query_string("query_string");
    cgi.set_redirect_request("redirect_request");
    cgi.set_redirect_status("redirect_status");
    cgi.set_redirect_URL("redirect_URL");
    cgi.set_referrer("referrer");
    cgi.set_remote_addr("remote_addr");
    cgi.set_remote_host("remote_host");
    cgi.set_remote_ident("remote_ident");
    cgi.set_remote_user("remote_user");
    cgi.set_request_method("request_method");
    cgi.set_script_name("script_name");
    cgi.set_server_name("server_name");
    cgi.set_server_port(10);
    cgi.set_server_protocol("server_protocol");
    cgi.set_server_software("server_software");
    cgi.set_user_agent("user_agent");
    cgi.set_using_HTTPS(true);

    // Warning: cannot test Input Content

    // Write data
    cgi.write();

    // Test result
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::AUTH_TYPE), "auth_type");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::CONTENT_LENGTH), "0");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::CONTENT_TYPE), "content_type");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::GATEWAY_INTERFACE),
        "gateway_interface");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::HTTPS), "ON");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::HTTP_ACCEPT), "accept");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::HTTP_ACCEPT_LANGUAGE),
        "accept_language_string");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::HTTP_REFERER), "referrer");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::HTTP_USER_AGENT),
        "user_agent");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::PATH_INFO), "path_info");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::PATH_TRANSLATED),
        "path_translated");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::QUERY_STRING), "query_string");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::REDIRECT_REQUEST),
        "redirect_request");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::REDIRECT_STATUS),
        "redirect_status");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::REDIRECT_URL), "redirect_URL");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::REMOTE_ADDR), "remote_addr");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::REMOTE_HOST), "remote_host");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::REMOTE_IDENT), "remote_ident");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::REMOTE_USER), "remote_user");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::REQUEST_METHOD),
        "request_method");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::SCRIPT_NAME), "script_name");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::SERVER_NAME), "server_name");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::SERVER_PORT), "10");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::SERVER_PROTOCOL),
        "server_protocol");
    BOOST_CHECK_EQUAL(
        rompp::tools::get_env_variable(rompp::cgi::SERVER_SOFTWARE),
        "server_software");
}

/******************************* TEST Nominal **********************************/
/**
 * Nominal test case: To_string function
 */
BOOST_AUTO_TEST_CASE(ToString)
{
    // Create CGI
    rompp::cgi::Cgi cgi;
    cgi.set_accept("accept");
    cgi.set_accept_language_string("accept_language_string");
    cgi.set_auth_type("auth_type");
    cgi.set_content_length(13);
    cgi.set_content_type("content_type");
    cgi.set_gateway_interface("gateway_interface");
    cgi.set_input_content("input_content");
    cgi.set_path_info("path_info");
    cgi.set_path_translated("path_translated");
    cgi.set_query_string("query_string");
    cgi.set_redirect_request("redirect_request");
    cgi.set_redirect_status("redirect_status");
    cgi.set_redirect_URL("redirect_URL");
    cgi.set_referrer("referrer");
    cgi.set_remote_addr("remote_addr");
    cgi.set_remote_host("remote_host");
    cgi.set_remote_ident("remote_ident");
    cgi.set_remote_user("remote_user");
    cgi.set_request_method("request_method");
    cgi.set_script_name("script_name");
    cgi.set_server_name("server_name");
    cgi.set_server_port(10);
    cgi.set_server_protocol("server_protocol");
    cgi.set_server_software("server_software");
    cgi.set_user_agent("user_agent");
    cgi.set_using_HTTPS(true);

    std::stringstream expected_result;
    expected_result << "SERVER_SOFTWARE=server_software\n"
                    << "SERVER_NAME=server_name\n"
                    << "GATEWAY_INTERFACE=gateway_interface\n"
                    << "SERVER_PROTOCOL=server_protocol\n"
                    << "SERVER_PORT=10\n"
                    << "REQUEST_METHOD=request_method\n"
                    << "PATH_INFO=path_info\n"
                    << "PATH_TRANSLATED=path_translated\n"
                    << "SCRIPT_NAME=script_name\n"
                    << "QUERY_STRING=query_string\n"
                    << "REMOTE_HOST=remote_host\n"
                    << "REMOTE_ADDR=remote_addr\n"
                    << "AUTH_TYPE=auth_type\n"
                    << "REMOTE_USER=remote_user\n"
                    << "REMOTE_IDENT=remote_ident\n"
                    << "CONTENT_TYPE=content_type\n"
                    << "CONTENT_LENGTH=13\n"
                    << "HTTP_ACCEPT=accept\n"
                    << "HTTP_USER_AGENT=user_agent\n"
                    << "REDIRECT_REQUEST=redirect_request\n"
                    << "REDIRECT_URL=redirect_URL\n"
                    << "REDIRECT_STATUS=redirect_status\n"
                    << "HTTP_REFERER=referrer\n"
                    << "HTTP_ACCEPT_LANGUAGE=accept_language_string\n"
                    << "HTTPS=1\n"
                    << "Data=input_content\n";

    BOOST_REQUIRE_EQUAL(cgi.to_string(), expected_result.str());
}
