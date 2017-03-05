// Include Standard library
#include <iostream> // for std::cin
#include <sstream> // for std::stringstream

// Include boost files
#include <boost/algorithm/string.hpp>

// Include Project files
#include "rompp/cgi/Cgi.h"
#include "rompp/tools/environment.h"

namespace rompp
{

namespace cgi
{

Cgi::Cgi():
    _server_port(0), _content_length(0), _using_HTTPS(false), 
    _server_software(""), _server_name(""), _gateway_interface(""), 
    _server_protocol(""), _request_method(""), _path_info(""), 
    _path_translated(""), _script_name(""), _query_string(""), _remote_host(""), 
    _remote_addr(""), _auth_type(""), _remote_user(""), _remote_ident(""), 
    _content_type(""), _accept(""), _user_agent(""), _redirect_request(""), 
    _redirect_URL(""), _redirect_status(""), _referrer(""), 
    _accept_language_string(""), _input_content("")
{
    // Nothing else.
}

Cgi::~Cgi()
{
    // Nothing to do.
}

unsigned long Cgi::get_server_port() const
{
    return this->_server_port;
}

void Cgi::set_server_port(unsigned long server_port)
{
    this->_server_port = server_port;
}

unsigned long Cgi::get_content_length() const
{
    return this->_content_length;
}

void Cgi::set_content_length(unsigned long content_length)
{
    this->_content_length = content_length;
}

bool Cgi::get_using_HTTPS() const
{
    return this->_using_HTTPS;
}

void Cgi::set_using_HTTPS(bool using_HTTPS)
{
    this->_using_HTTPS = using_HTTPS;
}

std::string Cgi::get_server_software() const
{
    return this->_server_software;
}

void Cgi::set_server_software(std::string const & server_software)
{
    this->_server_software = server_software;
}

std::string Cgi::get_server_name() const
{
    return this->_server_name;
}

void Cgi::set_server_name(std::string const & server_name)
{
    this->_server_name = server_name;
}

std::string Cgi::get_gateway_interface() const
{
    return this->_gateway_interface;
}

void Cgi::set_gateway_interface(std::string const & gateway_interface)
{
    this->_gateway_interface = gateway_interface;
}

std::string Cgi::get_server_protocol() const
{
    return this->_server_protocol;
}

void Cgi::set_server_protocol(std::string const & server_protocol)
{
    this->_server_protocol = server_protocol;
}

std::string Cgi::get_request_method() const
{
    return this->_request_method;
}

void Cgi::set_request_method(std::string const & request_method)
{
    this->_request_method = request_method;
}

std::string Cgi::get_path_info() const
{
    return this->_path_info;
}

void Cgi::set_path_info(std::string const & path_info)
{
    this->_path_info = path_info;
}

std::string Cgi::get_path_translated() const
{
    return this->_path_translated;
}

void Cgi::set_path_translated(std::string const & path_translated)
{
    this->_path_translated = path_translated;
}

std::string Cgi::get_script_name() const
{
    return this->_script_name;
}

void Cgi::set_script_name(std::string const & script_name)
{
    this->_script_name = script_name;
}

std::string Cgi::get_query_string() const
{
    return this->_query_string;
}

void Cgi::set_query_string(std::string const & query_string)
{
    this->_query_string = query_string;
}

std::string Cgi::get_remote_host() const
{
    return this->_remote_host;
}

void Cgi::set_remote_host(std::string const & remote_host)
{
    this->_remote_host = remote_host;
}

std::string Cgi::get_remote_addr() const
{
    return this->_remote_addr;
}

void Cgi::set_remote_addr(std::string const & remote_addr)
{
    this->_remote_addr = remote_addr;
}

std::string Cgi::get_auth_type() const
{
    return this->_auth_type;
}

void Cgi::set_auth_type(std::string const & auth_type)
{
    this->_auth_type = auth_type;
}

std::string Cgi::get_remote_user() const
{
    return this->_remote_user;
}

void Cgi::set_remote_user(std::string const & remote_user)
{
    this->_remote_user = remote_user;
}

std::string Cgi::get_remote_ident() const
{
    return this->_remote_ident;
}

void Cgi::set_remote_ident(std::string const & remote_ident)
{
    this->_remote_ident = remote_ident;
}

std::string Cgi::get_content_type() const
{
    return this->_content_type;
}

void Cgi::set_content_type(std::string const & content_type)
{
    this->_content_type = content_type;
}

std::string Cgi::get_accept() const
{
    return this->_accept;
}

void Cgi::set_accept(std::string const & accept)
{
    this->_accept = accept;
}

std::string Cgi::get_user_agent() const
{
    return this->_user_agent;
}

void Cgi::set_user_agent(std::string const & user_agent)
{
    this->_user_agent = user_agent;
}

std::string Cgi::get_redirect_request() const
{
    return this->_redirect_request;
}

void Cgi::set_redirect_request(std::string const & redirect_request)
{
    this->_redirect_request = redirect_request;
}

std::string Cgi::get_redirect_URL() const
{
    return this->_redirect_URL;
}

void Cgi::set_redirect_URL(std::string const & redirect_URL)
{
    this->_redirect_URL = redirect_URL;
}

std::string Cgi::get_redirect_status() const
{
    return this->_redirect_status;
}

void Cgi::set_redirect_status(std::string const & redirect_status)
{
    this->_redirect_status = redirect_status;
}

std::string Cgi::get_referrer() const
{
    return this->_referrer;
}

void Cgi::set_referrer(std::string const & referrer)
{
    this->_referrer = referrer;
}

std::string Cgi::get_accept_language_string() const
{
    return this->_accept_language_string;
}

void Cgi::set_accept_language_string(std::string const & accept_language_string)
{
    this->_accept_language_string = accept_language_string;
}

std::string Cgi::get_input_content() const
{
    return this->_input_content;
}

void Cgi::set_input_content(std::string const & input_content)
{
    this->_input_content = input_content;
}

void Cgi::read()
{
    this->_server_software = tools::get_env_variable(SERVER_SOFTWARE);
    this->_server_name = tools::get_env_variable(SERVER_NAME);
    this->_gateway_interface = tools::get_env_variable(GATEWAY_INTERFACE);
    this->_server_protocol = tools::get_env_variable(SERVER_PROTOCOL);

    std::string port = tools::get_env_variable(SERVER_PORT);
    this->_server_port = std::atol(port.c_str());

    this->_request_method = tools::get_env_variable(REQUEST_METHOD);
    this->_path_info = tools::get_env_variable(PATH_INFO);
    this->_path_translated = tools::get_env_variable(PATH_TRANSLATED);
    this->_script_name = tools::get_env_variable(SCRIPT_NAME);
    this->_query_string = tools::get_env_variable(QUERY_STRING);
    this->_remote_host = tools::get_env_variable(REMOTE_HOST);
    this->_remote_addr = tools::get_env_variable(REMOTE_ADDR);
    this->_auth_type = tools::get_env_variable(AUTH_TYPE);
    this->_remote_user = tools::get_env_variable(REMOTE_USER);
    this->_remote_ident = tools::get_env_variable(REMOTE_IDENT);
    this->_content_type = tools::get_env_variable(CONTENT_TYPE);

    std::string length = tools::get_env_variable(CONTENT_LENGTH);
    this->_content_length = std::atol(length.c_str());

    this->_accept = tools::get_env_variable(HTTP_ACCEPT);
    this->_user_agent = tools::get_env_variable(HTTP_USER_AGENT);
    this->_redirect_request = tools::get_env_variable(REDIRECT_REQUEST);
    this->_redirect_URL = tools::get_env_variable(REDIRECT_URL);
    this->_redirect_status = tools::get_env_variable(REDIRECT_STATUS);
    this->_referrer = tools::get_env_variable(HTTP_REFERER);
    this->_accept_language_string = tools::get_env_variable(HTTP_ACCEPT_LANGUAGE);

    std::string https = tools::get_env_variable(HTTPS);
    boost::to_upper(https);
    this->_using_HTTPS = (https == "ON");
    
    if (this->get_content_length() > 0)
    {
        this->_read_input_content();
    }
}

void Cgi::write()
{
    // todo
}

std::string Cgi::to_string() const
{
    std::stringstream stream;
    
    stream << SERVER_SOFTWARE << "=" << this->get_server_software() << "\n";
    stream << SERVER_NAME << "=" << this->get_server_name() << "\n";
    stream << GATEWAY_INTERFACE << "=" << this->get_gateway_interface() << "\n";
    stream << SERVER_PROTOCOL << "=" << this->get_server_protocol() << "\n";
    stream << SERVER_PORT << "=" << this->get_server_port() << "\n";
    stream << REQUEST_METHOD << "=" << this->get_request_method() << "\n";
    stream << PATH_INFO << "=" << this->get_path_info() << "\n";
    stream << PATH_TRANSLATED << "=" << this->get_path_translated() << "\n";
    stream << SCRIPT_NAME << "=" << this->get_script_name() << "\n";
    stream << QUERY_STRING << "=" << this->get_query_string() << "\n";
    stream << REMOTE_HOST << "=" << this->get_remote_host() << "\n";
    stream << REMOTE_ADDR << "=" << this->get_remote_addr() << "\n";
    stream << AUTH_TYPE << "=" << this->get_auth_type() << "\n";
    stream << REMOTE_USER << "=" << this->get_remote_user() << "\n";
    stream << REMOTE_IDENT << "=" << this->get_remote_ident() << "\n";
    stream << CONTENT_TYPE << "=" << this->get_content_type() << "\n";
    stream << CONTENT_LENGTH << "=" << this->get_content_length() << "\n";
    stream << HTTP_ACCEPT << "=" << this->get_accept() << "\n";
    stream << HTTP_USER_AGENT << "=" << this->get_user_agent() << "\n";
    stream << REDIRECT_REQUEST << "=" << this->get_redirect_request() << "\n";
    stream << REDIRECT_URL << "=" << this->get_redirect_URL() << "\n";
    stream << REDIRECT_STATUS << "=" << this->get_redirect_status() << "\n";
    stream << HTTP_REFERER << "=" << this->get_referrer() << "\n";
    stream << HTTP_ACCEPT_LANGUAGE << "=" << this->get_accept_language_string()
           << "\n";
    stream << HTTPS << "=" << this->get_using_HTTPS() << "\n";
    stream << "Data" << "=" << this->get_input_content() << "\n";
    
    return stream.str();
}

void Cgi::_read_input_content()
{
    const unsigned int size = this->get_content_length();

    // characters
    char c;
    while (std::cin.get(c))
    {
        this->_input_content.push_back(c);

        if (this->_input_content.size() == size)
        {
            break;
        }
    }
}

} // namespace cgi

} // namespace rompp
