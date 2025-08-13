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
    void assert(const char* message) const ;
    void debug(const char* message) const ;
    void info(const char* message) const ;
    void warning(const char* message) const ;
    void error(const char* message) const ;
    void critical(const char* message) const ;

private:
    void log(const char* message, const log_type& log_type) const ;
    bool must_log(const log_type& log_type) const ;

private:
    const char* get_prefix(const log_type& log_type) const ;
    const char* get_color(const log_type& log_type) const;

};