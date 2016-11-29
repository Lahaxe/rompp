/**
 * @file rompp/Cgi.h
 * @brief Common Gateway Interface
 * @details This files contains main class for CGI use.
 * @author Romain Lahaxe
 * @copyright 
 */

#ifndef _af7506ce_7cbe_4d45_a387_0f6d7b1fa43b
#define _af7506ce_7cbe_4d45_a387_0f6d7b1fa43b

/**
 * @brief 
 */
namespace rompp
{

/**
 * @brief 
 */
namespace cgi
{

const std::string AUTH_TYPE = "AUTH_TYPE";
const std::string CONTENT_TYPE = "CONTENT_TYPE";
const std::string CONTENT_LENGTH = "CONTENT_LENGTH";
const std::string GATEWAY_INTERFACE = "GATEWAY_INTERFACE";
const std::string HTTP_ACCEPT = "HTTP_ACCEPT";
const std::string HTTP_ACCEPT_LANGUAGE = "HTTP_ACCEPT_LANGUAGE"; 
const std::string HTTP_REFERER = "HTTP_REFERER";
const std::string HTTP_USER_AGENT = "HTTP_USER_AGENT";
const std::string HTTPS = "HTTPS";
const std::string PATH_INFO = "PATH_INFO";
const std::string PATH_TRANSLATED = "PATH_TRANSLATED";
const std::string QUERY_STRING = "QUERY_STRING";
const std::string REDIRECT_REQUEST = "REDIRECT_REQUEST";
const std::string REDIRECT_STATUS = "REDIRECT_STATUS";
const std::string REDIRECT_URL = "REDIRECT_URL";
const std::string REMOTE_ADDR = "REMOTE_ADDR";
const std::string REMOTE_HOST = "REMOTE_HOST";
const std::string REMOTE_IDENT = "REMOTE_IDENT";
const std::string REMOTE_USER = "REMOTE_USER";
const std::string REQUEST_METHOD = "REQUEST_METHOD";
const std::string SCRIPT_NAME = "SCRIPT_NAME";
const std::string SERVER_NAME = "SERVER_NAME";
const std::string SERVER_PORT = "SERVER_PORT";
const std::string SERVER_PROTOCOL = "SERVER_PROTOCOL";
const std::string SERVER_SOFTWARE = "SERVER_SOFTWARE";

/**
 * @brief Common Gateway Interface implementation
 */
class Cgi
{
public:
    /// @brief Create an instance of Cgi
    Cgi();

    /// @brief Destroy the instance of Cgi
    virtual ~Cgi();

    /**
     * @brief 
     * @return 
     */
    unsigned long get_server_port() const;

    /**
     * @brief 
     * @param server_port:
     */
    void set_server_port(unsigned long server_port);

    /**
     * @brief 
     * @return 
     */
    unsigned long get_content_length() const;

    /**
     * @brief 
     * @param content_length:
     */
    void set_content_length(unsigned long content_length);

    /**
     * @brief 
     * @return 
     */
    bool get_using_HTTPS() const;

    /**
     * @brief 
     * @param using_HTTPS:
     */
    void set_using_HTTPS(bool using_HTTPS);

    /**
     * @brief 
     * @return 
     */
    std::string get_server_software() const;

    /**
     * @brief 
     * @param server_software:
     */
    void set_server_software(std::string const & server_software);

    /**
     * @brief 
     * @return 
     */
    std::string get_server_name() const;

    /**
     * @brief 
     * @param server_name:
     */
    void set_server_name(std::string const & server_name);

    /**
     * @brief 
     * @return 
     */
    std::string get_gateway_interface() const;

    /**
     * @brief 
     * @param gateway_interface:
     */
    void set_gateway_interface(std::string const & gateway_interface);

    /**
     * @brief 
     * @return 
     */
    std::string get_server_protocol() const;

    /**
     * @brief 
     * @param server_protocol:
     */
    void set_server_protocol(std::string const & server_protocol);

    /**
     * @brief 
     * @return 
     */
    std::string get_request_method() const;

    /**
     * @brief 
     * @param request_method:
     */
    void set_request_method(std::string const & request_method);

    /**
     * @brief 
     * @return 
     */
    std::string get_path_info() const;

    /**
     * @brief 
     * @param path_info:
     */
    void set_path_info(std::string const & path_info);

    /**
     * @brief 
     * @return 
     */
    std::string get_path_translated() const;

    /**
     * @brief 
     * @param path_translated:
     */
    void set_path_translated(std::string const & path_translated);

    /**
     * @brief 
     * @return 
     */
    std::string get_script_name() const;

    /**
     * @brief 
     * @param script_name:
     */
    void set_script_name(std::string const & script_name);

    /**
     * @brief 
     * @return 
     */
    std::string get_query_string() const;

    /**
     * @brief 
     * @param query_string:
     */
    void set_query_string(std::string const & query_string);

    /**
     * @brief 
     * @return 
     */
    std::string get_remote_host() const;

    /**
     * @brief 
     * @param remote_host:
     */
    void set_remote_host(std::string const & remote_host);

    /**
     * @brief 
     * @return 
     */
    std::string get_remote_addr() const;

    /**
     * @brief 
     * @param remote_addr:
     */
    void set_remote_addr(std::string const & remote_addr);

    /**
     * @brief 
     * @return 
     */
    std::string get_auth_type() const;

    /**
     * @brief 
     * @param auth_type:
     */
    void set_auth_type(std::string const & auth_type);

    /**
     * @brief 
     * @return 
     */
    std::string get_remote_user() const;

    /**
     * @brief 
     * @param remote_user:
     */
    void set_remote_user(std::string const & remote_user);

    /**
     * @brief 
     * @return 
     */
    std::string get_remote_ident() const;

    /**
     * @brief 
     * @param remote_ident:
     */
    void set_remote_ident(std::string const & remote_ident);

    /**
     * @brief 
     * @return 
     */
    std::string get_content_type() const;

    /**
     * @brief 
     * @param content_type:
     */
    void set_content_type(std::string const & content_type);

    /**
     * @brief 
     * @return 
     */
    std::string get_accept() const;

    /**
     * @brief 
     * @param accept:
     */
    void set_accept(std::string const & accept);

    /**
     * @brief 
     * @return 
     */
    std::string get_user_agent() const;

    /**
     * @brief 
     * @param user_agent:
     */
    void set_user_agent(std::string const & user_agent);

    /**
     * @brief 
     * @return 
     */
    std::string get_redirect_request() const;

    /**
     * @brief 
     * @param redirect_request:
     */
    void set_redirect_request(std::string const & redirect_request);

    /**
     * @brief 
     * @return 
     */
    std::string get_redirect_URL() const;

    /**
     * @brief 
     * @param redirect_URL:
     */
    void set_redirect_URL(std::string const & redirect_URL);

    /**
     * @brief 
     * @return 
     */
    std::string get_redirect_status() const;

    /**
     * @brief 
     * @param redirect_status:
     */
    void set_redirect_status(std::string const & redirect_status);

    /**
     * @brief 
     * @return 
     */
    std::string get_referrer() const;

    /**
     * @brief 
     * @param referrer:
     */
    void set_referrer(std::string const & referrer);

    /**
     * @brief 
     * @return 
     */
    std::string get_accept_language_string() const;

    /**
     * @brief 
     * @param accept_language_string:
     */
    void set_accept_language_string(std::string const & accept_language_string);

    /**
     * @brief 
     * @return 
     */
    std::string get_input_content() const;

    /**
     * @brief 
     * @param input_content:
     */
    void set_input_content(std::string const & input_content);

    void read();

    void write();

    std::string to_string() const;

protected:

private:
    /// @brief Contains value of SERVER_PORT
    unsigned long _server_port;

    /// @brief Contains value of CONTENT_LENGTH
    unsigned long _content_length;

    /// @brief Contains value of HTTPS
    bool _using_HTTPS;

    /// @brief Contains value of SERVER_SOFTWARE
    std::string _server_software;

    /// @brief Contains value of SERVER_NAME
    std::string _server_name;

    /// @brief Contains value of GATEWAY_INTERFACE
    std::string _gateway_interface;

    /// @brief Contains value of SERVER_PROTOCOL
    std::string _server_protocol;

    /// @brief Contains value of REQUEST_METHOD
    std::string _request_method;

    /// @brief Contains value of PATH_INFO
    std::string _path_info;

    /// @brief Contains value of PATH_TRANSLATED
    std::string _path_translated;

    /// @brief Contains value of SCRIPT_NAME
    std::string _script_name;

    /// @brief Contains value of QUERY_STRING
    std::string _query_string;
    
    /// @brief Contains value of REMOTE_HOST
    std::string _remote_host;

    /// @brief Contains value of REMOTE_ADDR
    std::string _remote_addr;

    /// @brief Contains value of AUTH_TYPE
    std::string _auth_type;

    /// @brief Contains value of REMOTE_USER
    std::string _remote_user;

    /// @brief Contains value of REMOTE_IDENT
    std::string _remote_ident;

    /// @brief Contains value of CONTENT_TYPE
    std::string _content_type;
    
    /// @brief Contains value of HTTP_ACCEPT
    std::string _accept;

    /// @brief Contains value of HTTP_USER_AGENT
    std::string _user_agent;

    /// @brief Contains value of REDIRECT_REQUEST
    std::string _redirect_request;

    /// @brief Contains value of REDIRECT_URL
    std::string _redirect_URL;

    /// @brief Contains value of REDIRECT_STATUS
    std::string _redirect_status;

    /// @brief Contains value of HTTP_REFERER
    std::string _referrer;

    /// @brief Contains value of HTTP_ACCEPT_LANGUAGE
    std::string _accept_language_string;

    /// @brief current input data
    std::string _input_content;

    /// @brief Read data from the standard input
    void _read_input_content();

};

} // namespace cgi

} // namespace rompp

#endif // _af7506ce_7cbe_4d45_a387_0f6d7b1fa43b

