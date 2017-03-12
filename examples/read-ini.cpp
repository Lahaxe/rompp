// Include Standard library
#include <cstdlib>
#include <iostream>
#include <sstream>

// Include Rompp files
#include <rompp/logger/Logger.h>
#include <rompp/configuration/ConfigurationINI.h>

int main(int argc, char *argv[])
{
    auto logger = Logger::instance();
    int status = EXIT_FAILURE;
    try
    {
        logger.initialize_default("DEBUG");

        std::stringstream message;
        message << "Begin " << std::string(argv[0]);
        logger.info(message.str());

        auto conf = ConfigurationINI::New(argv[1]);
        conf->read();

        std::stringstream message2;
        message2 << "\nkey 'ma_section.macle'="
                 << conf->get_value("ma_section.macle")
                 << "\nkey 'ma_section.notfind' exists = "
                 << conf->contains_key("ma_section.notfind");
        logger.info(message2.str());

        status = EXIT_SUCCESS;
    }
    catch (std::exception & exc)
    {
        std::stringstream message;
        message << exc.what();
        logger.fatal(message.str());
    }

    std::stringstream message;
    message << "End " << std::string(argv[0]);
    logger.info(message.str());

    return status;
}

