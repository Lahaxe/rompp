#ifndef _30684acf_09cd_4ccb_ba5e_0677c61d1905
#define _30684acf_09cd_4ccb_ba5e_0677c61d1905

// Include Standard library
#include <exception>
#include <string>

/**
 * @brief Main namespace
 */
namespace rompp
{

/**
 * @brief Base class for exceptions.
 */
class Exception: public std::exception
{
public:
    /**
     * @brief Message string constructor.
     * @param message: Details of the exception
     */
    Exception(std::string const & message="");

    /// @brief Destructor.
    virtual ~Exception() noexcept;

    /**
     * @brief Return the reason for the exception.
     * @return Return Details of the exception.
     */
    virtual const char* what() const noexcept;

protected:
    /// @brief Message of the exception.
    std::string _message;

private:

};

} // namespace rompp

#endif // _30684acf_09cd_4ccb_ba5e_0677c61d1905
