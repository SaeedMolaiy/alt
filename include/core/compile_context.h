#pragma once

#include "logging/logger.h"
#include "options/compile_options.h"

class compile_context
{

private:
    const compile_options* m_compile_options;
    const logger* m_logger;

public:
    compile_context(const compile_options* compile_options);
    ~compile_context();

private:
    void configure_logger();
    void configure_compile_options(const compile_options* compile_options);

};