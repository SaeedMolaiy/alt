#include "memory_macros.h"

#include "core/options/compile_options.h"
#include "core/compile_context.h"

static compile_options get_compile_options()
{
    static compile_options options;

    return options;
}

int main()
{
    compile_options options = get_compile_options();
    compile_context* compile_context =
            new class compile_context(&options);

    try
    {
    }
    catch(...)
    {
        SAFE_DELETE(compile_context);
    }
}