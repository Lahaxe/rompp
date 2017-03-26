#ifndef _c1dd5050_d52a_4223_8ee4_a74f693cb10f
#define _c1dd5050_d52a_4223_8ee4_a74f693cb10f

// Include Standard library
#include <memory>
#include <string>
#include <vector>

class DBConnectionBase
{
public:
    /// @brief Smart pointer for an instance of DBConnectionBase
    typedef std::shared_ptr<DBConnectionBase> Pointer;
    /// @brief Smart pointer for an instance of DBConnectionBase
    typedef std::shared_ptr<DBConnectionBase const> ConstPointer;

    virtual ~DBConnectionBase();

    std::string get_host_name() const;

    void set_host_name(std::string const & host_name);

    int get_port() const;

    void set_port(int port);

    std::string const & get_db_name() const;

    void set_db_name(std::string const & db_name);

    std::string const & get_bulk_data() const;

    void set_bulk_data(std::string const & bulk_data);

    std::string get_user() const;

    void set_user(std::string const & user);

    std::string get_password() const;

    void set_password(std::string const & password);

    std::vector<std::string> get_indexes() const;

    void set_indexes(std::vector<std::string> const & indexes);

    virtual bool is_connected() const = 0;

    virtual bool connect() = 0;

    virtual bool disconnect() = 0;

protected:
    DBConnectionBase();

    DBConnectionBase(DBConnectionBase const & other);

    DBConnectionBase& operator=(DBConnectionBase const & other);

private:
    /// Database Host name
    std::string _host_name;

    /// Database Port
    int _port;

    std::string _db_name;

    std::string _bulk_data;

    std::string _user;

    std::string _password;

    /// Database Indexes
    std::vector<std::string> _indexes;

};

#endif // _c1dd5050_d52a_4223_8ee4_a74f693cb10f
