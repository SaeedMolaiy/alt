#include "memory_macros.h"

#include "core/compile_context.h"

compile_context::compile_context(const compile_options* compile_options)
{
    configure_logger();
    configure_compile_options(compile_options);
}

void compile_context::configure_logger()
{
    m_logger = new logger(log_type::assert);
}

void compile_context::configure_compile_options(const compile_options* compile_options)
{
    if(compile_options)
    {
        m_compile_options = compile_options;
    }
    else
    {
        m_compile_options =
                new class compile_options();

        m_logger->warning(
                "Falling back to default compile options.");
    }
}

compile_context::~compile_context()
{
    SAFE_DELETE(m_logger);
}