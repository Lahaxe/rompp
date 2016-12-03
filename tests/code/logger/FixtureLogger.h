#ifndef _d5e4cb8f_57ec_4889_a680_8042751d9ca6
#define _d5e4cb8f_57ec_4889_a680_8042751d9ca6

#include <iostream>
#include <sstream>
#include <string>

// Include Project files
#include "../FixtureBase.h"

class FixtureLogger : public FixtureBase
{
public:
    FixtureLogger() : FixtureBase()
    {
        // redirect standard output to stringstream
        this->_old_buffer = std::cout.rdbuf(this->_stream.rdbuf());
    }

    virtual ~FixtureLogger()
    {
        // set the default output
        std::cout.rdbuf(this->_old_buffer);
    }
    
    std::string stream() const
    {
        return this->_stream.str();
    }

protected:

private:
    std::stringstream _stream;
    std::streambuf* _old_buffer;

};

#endif // _d5e4cb8f_57ec_4889_a680_8042751d9ca6
