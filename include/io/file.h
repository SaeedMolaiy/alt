#pragma once

#include <string>

using std::string;

class file
{
public:
    file() = delete;
    file(const file&) = delete;
    file& operator=(const file&) = delete;

public:
    static const string* read_all_lines(const char* file_path);
};