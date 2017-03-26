#include "rompp/dbconnection/DBConnectionBase.h"

DBConnectionBase
::DBConnectionBase():
    _host_name(""), _port(0), _db_name(""), _bulk_data(""), _user(""),
    _password(""), _indexes(std::vector<std::string>())
{
    // Nothing else.
}

DBConnectionBase
::~DBConnectionBase()
{
    // Nothing to do.
}

std::string
DBConnectionBase
::get_host_name() const
{
    return this->_host_name;
}

void
DBConnectionBase
::set_host_name(std::string const & host_name)
{
    this->_host_name = host_name;
}

int
DBConnectionBase
::get_port() const
{
    return this->_port;
}

void
DBConnectionBase
::set_port(int port)
{
    this->_port = port;
}

std::string const &
DBConnectionBase
::get_db_name() const
{
    return this->_db_name;
}

void
DBConnectionBase
::set_db_name(std::string const & db_name)
{
    this->_db_name = db_name;
}

std::string const &
DBConnectionBase
::get_bulk_data() const
{
    return this->_bulk_data;
}

void
DBConnectionBase
::set_bulk_data(std::string const & bulk_data)
{
    this->_bulk_data = bulk_data;
}

std::string
DBConnectionBase
::get_user() const
{
    return this->_user;
}

void
DBConnectionBase
::set_user(std::string const & user)
{
    this->_user = user;
}

std::string
DBConnectionBase
::get_password() const
{
    return this->_password;
}

void
DBConnectionBase
::set_password(std::string const & password)
{
    this->_password = password;
}

std::vector<std::string>
DBConnectionBase
::get_indexes() const
{
    return this->_indexes;
}

void
DBConnectionBase
::set_indexes(std::vector<std::string> const & indexes)
{
    this->_indexes = indexes;
}
