#include "WindowHelper.hpp"
#include <iostream>

struct EnumData {
    std::wstring className;
    std::vector<HWND>* results;
};

static BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
    auto data = reinterpret_cast<EnumData*>(lParam);
    wchar_t cls[256] = {};
    if (::GetClassNameW(hwnd, cls, _countof(cls)) > 0) {
        if (data->className == cls) {
            data->results->push_back(hwnd);
        }
    }
    return TRUE;
}

HWND WindowHelper::FindWindowByTitle(const std::wstring& title) {
    HWND hwnd = ::FindWindowW(nullptr, title.c_str());
    if (!hwnd) {
        std::wcerr << L"[!] FindWindowW failed (“" << title
            << L"”): " << GetLastError() << L"\n";
    }
    return hwnd;
}

std::vector<HWND> WindowHelper::EnumWindowsByClassName(const std::wstring& className) {
    std::vector<HWND> matches;
    EnumData data{ className, &matches };
    if (!::EnumWindows(EnumWindowsProc, reinterpret_cast<LPARAM>(&data))) {
        std::wcerr << L"[!] EnumWindows failed: "
            << GetLastError() << L"\n";
    }
    return matches;
}

std::wstring WindowHelper::GetWindowText(HWND hwnd) {
    int len = ::GetWindowTextLengthW(hwnd);
    if (len < 0) {
        std::wcerr << L"[!] GetWindowTextLengthW failed: "
            << GetLastError() << L"\n";
        return {};
    }
    std::wstring text(len, L'\0');
    // &text[0] gives a mutable buffer for GetWindowTextW
    if (!::GetWindowTextW(hwnd, &text[0], len + 1)) {
        std::wcerr << L"[!] GetWindowTextW failed: "
            << GetLastError() << L"\n";
        return {};
    }
    return text;
}
