#ifndef _8aa168b7_c9ed_4275_9015_4c35e12a876b
#define _8aa168b7_c9ed_4275_9015_4c35e12a876b

#include "FixtureBase.h"

class FixtureConfiguration : public FixtureBase
{
public:
    std::string file;

    /// @brief Create Fixture
    FixtureConfiguration(): FixtureBase(), file("")
    {
        // Nothing else.
    };

    /// @brief Destroy the fixture.
    virtual ~FixtureConfiguration()
    {
        // Nothing to do.
    };

    /// @brief Create a template and save the file into temporary directory.
    void create_template_file()
    {
        // Creation du template
        std::stringstream file_content;
        file_content << "";

        this->file = this->_create_file("nom_du_fichier.extension",
                                        file_content.str());
    };

};

#endif // _8aa168b7_c9ed_4275_9015_4c35e12a876b
