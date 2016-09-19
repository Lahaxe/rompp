// Include Project files
#include "rompp/exception/Exception.h"

namespace rompp
{

Exception
::Exception(std::string const & message)
: _message(message)
{
    // Nothing else.
}

Exception
::~Exception() noexcept
{
    // Nothing to do.
}

char const *
Exception
::what() const noexcept
{
    return this->_message.c_str();
}

} // namespace rompp
