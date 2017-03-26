#ifndef _0d298b76_8cb2_4d72_b1d2_e93ab4e787df
#define _0d298b76_8cb2_4d72_b1d2_e93ab4e787df

// Include Qt files
#include <qt5/QtSql/QSqlDatabase>

// Include project files
#include "rompp/dbconnection/DBConnectionBase.h"

class MySQLConnection : public DBConnectionBase
{
public:
    /// @brief Smart pointer for an instance of MySQLConnection
    typedef std::shared_ptr<MySQLConnection> Pointer;
    /// @brief Smart pointer for an instance of MySQLConnection
    typedef std::shared_ptr<MySQLConnection const> ConstPointer;

    static Pointer New();

    virtual ~MySQLConnection();

    virtual bool is_connected() const;

    virtual bool connect();

    virtual bool disconnect();

protected:
    MySQLConnection();

    MySQLConnection(MySQLConnection const & other);

    MySQLConnection& operator=(MySQLConnection const & other);

private:
    QSqlDatabase _connection;

};

#endif // _0d298b76_8cb2_4d72_b1d2_e93ab4e787df
