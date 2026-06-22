#include "../../include/utils/Logger.hpp"
#include "../../include/utils/Colors.hpp"

#include <fstream>
#include <iostream>

namespace
{
    void writeLog(
        const std::string& level,
        const std::string& message)
    {
        std::ofstream log(
            "shigosagdb.log",
            std::ios::app);

        log
            << "[" << level << "] "
            << message
            << '\n';
    }
}

void Logger::info(const std::string& message)
{
    std::cout
        << Colors::GREEN
        << "[INFO] "
        << message
        << Colors::RESET
        << '\n';

    writeLog("INFO", message);
}

void Logger::warning(const std::string& message)
{
    std::cout
        << Colors::YELLOW
        << "[WARN] "
        << message
        << Colors::RESET
        << '\n';

    writeLog("WARN", message);
}

void Logger::error(const std::string& message)
{
    std::cout
        << Colors::RED
        << "[ERROR] "
        << message
        << Colors::RESET
        << '\n';

    writeLog("ERROR", message);
}

void Logger::banner()
{
    std::cout
        << Colors::CYAN
        << Colors::BOLD
        << "\n"
        << "=====================================\n"
        << "          ShigosagDB Engine          \n"
        << "       Lightweight C++ Database      \n"
        << "=====================================\n\n"
        << Colors::RESET;
}