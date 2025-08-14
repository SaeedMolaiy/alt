#include "io/file.h"

#include <fstream>
#include <sstream>
#include <stdexcept>

using std::ifstream;
using std::ostringstream;
using std::runtime_error;

const string* file::read_all_lines(const char* file_path)
{
    ifstream file_stream(file_path);

    if (!file_stream.is_open())
        throw runtime_error("Unable to open file.");

    ostringstream buffer;
    buffer << file_stream.rdbuf();

    static string content;
    content = buffer.str();

    return &content;
}