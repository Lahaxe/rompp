#ifndef _d5e4cb8f_57ec_4889_a680_8042751d9ca6
#define _d5e4cb8f_57ec_4889_a680_8042751d9ca6

// Include Project files
#include "../FixtureBase.h"
#include "rompp/logger/Logger.h"

class FixtureLogger : public FixtureBase
{
public:
    FixtureLogger() : FixtureBase()
    {
        Logger::instance();
    }

    virtual ~FixtureLogger()
    {
        Logger::delete_instance();
    }

protected:

private:

};

#endif // _d5e4cb8f_57ec_4889_a680_8042751d9ca6
