#include "rompp/dbconnection/MySQLConnection.h"

#include <qt5/QtCore/QString>

MySQLConnection::Pointer
MySQLConnection
::New()
{
    return Pointer(new MySQLConnection());
}

MySQLConnection
::MySQLConnection():
    DBConnectionBase(), _connection()
{
    // Nothing else.
}

MySQLConnection
::~MySQLConnection()
{
    if (this->is_connected())
    {
        this->disconnect();
    }
}

bool
MySQLConnection
::is_connected() const
{
    return this->_connection.isValid() && this->_connection.isOpen();
}

bool
MySQLConnection
::connect()
{
    if (!this->is_connected())
    {
        this->_connection =
                QSqlDatabase::addDatabase("QMYSQL",
                                          QString(this->get_db_name().c_str()));

        this->_connection.setHostName(QString(this->get_host_name().c_str()));
        this->_connection.setPort(this->get_port());
        this->_connection.setDatabaseName(QString(this->get_db_name().c_str()));
        this->_connection.setUserName(QString(this->get_user().c_str()));
        this->_connection.setPassword(QString(this->get_password().c_str()));

        this->_connection.open();
    }

    return this->is_connected();
}

bool
MySQLConnection
::disconnect()
{
    if (this->is_connected())
    {
        this->_connection.close();

        QSqlDatabase::removeDatabase(QString(this->get_db_name().c_str()));
    }

    return !this->is_connected();
}
