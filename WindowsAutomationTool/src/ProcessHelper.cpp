#include "ProcessHelper.hpp"
#include <iostream>
#include <vector>

bool ProcessHelper::Launch(const std::wstring& path, const std::wstring& args) {
    STARTUPINFOW si{ sizeof(si) };
    PROCESS_INFORMATION pi{};

    // Build a mutable command‐line buffer
    std::wstring cmd = L"\"" + path + L"\" " + args;
    // Copy into a modifiable array (must include space for null)
    std::vector<wchar_t> cmdLine(cmd.begin(), cmd.end());
    cmdLine.push_back(0);

    if (!::CreateProcessW(
        nullptr,
        cmdLine.data(),     // now LPWSTR
        nullptr, nullptr,
        FALSE, 0, nullptr, nullptr,
        &si, &pi))
    {
        std::wcerr << L"[!] CreateProcessW failed for " << path
            << L" err=" << GetLastError() << L"\n";
        return false;
    }

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return true;
}
