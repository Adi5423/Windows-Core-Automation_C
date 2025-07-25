#pragma once

#include <Windows.h>
#include <string>

// Wraps SendInput for keyboard and mouse, with proper error checks.
class InputSimulator {
public:
    // Press & release a single virtual‑key code.
    static bool SendKeystroke(WORD vkCode);

    // Type a UTF‑16 string by mapping each wchar via VkKeyScanW.
    static bool SendTextInput(const std::wstring& text);

    // Move cursor to (x,y) and click. Default is left‑button down+up.
    static bool SendMouseClick(int x, int y, DWORD flags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP);
};
