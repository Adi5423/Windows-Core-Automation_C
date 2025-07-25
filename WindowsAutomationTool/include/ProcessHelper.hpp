#pragma once

#include <Windows.h>
#include <string>

// Wraps Win32 CreateProcess to launch external executables.
class ProcessHelper {
public:
    // Launch the given application (full path or command).
    // Returns true on success; on failure logs via std::wcerr.
    static bool Launch(const std::wstring& applicationPath, const std::wstring& args = L"");
};
