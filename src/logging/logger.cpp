#include <iostream>

#include "logging/logger.h"

using std::cout;
using std::endl;

logger::logger() : logger(log_type::warning)
{
}

logger::logger(const log_type& logger_level)
{
    set_logger_level(logger_level);
}

void logger::set_logger_level(const log_type& logger_level)
{
    m_logger_level = logger_level;
}

void logger::assert(const char* message)
{
    log(message, log_type::assert);
}

void logger::debug(const char* message)
{
    log(message, log_type::debug);
}

void logger::info(const char* message)
{
    log(message, log_type::info);
}

void logger::warning(const char* message)
{
    log(message, log_type::warning);
}

void logger::error(const char* message)
{
    log(message, log_type::error);
}

void logger::critical(const char* message)
{
    log(message, log_type::critical);
}

void logger::log(const char* message, const log_type& log_type)
{
    if(!must_log(log_type))
        return;

    cout << message << "\n";
}

bool logger::must_log(const log_type& log_type)
{
    return log_type >= m_logger_level;
}