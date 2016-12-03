#ifndef _1ab956bb_8e98_4801_9870_4f80d1772907
#define _1ab956bb_8e98_4801_9870_4f80d1772907

// Include Project files
#include "../FixtureBase.h"
#include "rompp/tools/file.h"

class FixtureFile : public FixtureBase
{
public:
    FixtureFile() : FixtureBase()
    {
        // Nothing else.
    }

    virtual ~FixtureFile()
    {
        // Nothing to do.
    }

    void create_csv_file()
    {
        this->_create_temp_directory();

        std::string const filename = "TestFile.csv";
        std::string const text = "cell_1.1\tcell_1.2\ncell_2.1\tcell_2.2";
        this->_create_file(filename, text);
    }

protected:

private:

};

#endif // _1ab956bb_8e98_4801_9870_4f80d1772907
