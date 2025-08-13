#include <iostream>

#include "logging/logger.h"

using std::cout;
using std::endl;

#define NEW_LINE "\n"
#define RESET_COLOR "\033[0m"

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

void logger::assert(const char* message) const
{
    log(message, log_type::assert);
}

void logger::debug(const char* message) const
{
    log(message, log_type::debug);
}

void logger::info(const char* message) const
{
    log(message, log_type::info);
}

void logger::warning(const char* message) const
{
    log(message, log_type::warning);
}

void logger::error(const char* message) const
{
    log(message, log_type::error);
}

void logger::critical(const char* message) const
{
    log(message, log_type::critical);
}

void logger::log(const char* message, const log_type& log_type) const
{
    if(!must_log(log_type))
        return;

    cout
        << get_color(log_type)
        << get_prefix(log_type)
        << message
        << RESET_COLOR
        << NEW_LINE;
}

bool logger::must_log(const log_type& log_type) const
{
    return log_type >= m_logger_level;
}

const char* logger::get_prefix(const log_type& log_type) const
{
    switch (log_type)
    {
        case log_type::none:
            return "[?] : ";

        case log_type::assert:
            return "[ASSERT] : ";

        case log_type::debug:
            return "[DEBUG] : ";

        case log_type::info:
            return "[INFO] : ";

        case log_type::warning:
            return "[WARNING] : ";

        case log_type::error:
            return "[ERROR] : ";

        case log_type::critical:
            return "[CRITICAL] : ";
    }

    return nullptr;
}

const char* logger::get_color(const log_type& log_type) const
{
    switch (log_type)
    {

        case log_type::none:
            return "\033[0m";

        case log_type::assert:
            return "\033[90m";

        case log_type::debug:
            return "\033[32m";

        case log_type::info:
            return "\033[36m";

        case log_type::warning:
            return "\033[33m";

        case log_type::error:
            return "\033[1;31m";

        case log_type::critical:
            return "\033[31m";

    }

    return nullptr;
}