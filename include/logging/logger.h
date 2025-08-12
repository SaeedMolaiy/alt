#pragma once

#include "log_type.h"

class logger
{

    log_type m_logger_level = log_type::none;

public:
    logger();
    explicit logger(const log_type& logger_level);

public:
    void set_logger_level(const log_type& logger_level);

public:
    void assert(const char* message);
    void debug(const char* message);
    void info(const char* message);
    void warning(const char* message);
    void error(const char* message);
    void critical(const char* message);

private:
    void log(const char* message, const log_type& log_type);
    bool must_log(const log_type& log_type);

private:
    const char* get_prefix(const log_type& log_type);
    const char* get_color(const log_type& log_type);

};