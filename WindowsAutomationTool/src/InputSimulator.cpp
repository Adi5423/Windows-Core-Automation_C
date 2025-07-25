#include "InputSimulator.hpp"
#include <iostream>

bool InputSimulator::SendKeystroke(WORD vkCode) {
    INPUT inputs[2] = {};

    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = vkCode;

    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = vkCode;
    inputs[1].ki.dwFlags = KEYEVENTF_KEYUP;

    UINT sent = ::SendInput(2, inputs, sizeof(INPUT));
    if (sent != 2) {
        std::cerr << "[!] SendInput(vk=" << vkCode
            << ") sent=" << sent
            << " err=" << ::GetLastError() << "\n";
        return false;
    }
    return true;
}

bool InputSimulator::SendTextInput(const std::wstring& text) {
    for (wchar_t ch : text) {
        SHORT vk = ::VkKeyScanW(ch);
        if (vk == -1) {
            std::wcerr << L"[!] Cannot map char '" << ch << L"'\n";
            continue;
        }
        if (!SendKeystroke(LOBYTE(vk))) {
            return false;
        }
    }
    return true;
}

bool InputSimulator::SendMouseClick(int x, int y, DWORD flags) {
    if (!::SetCursorPos(x, y)) {
        std::cerr << "[!] SetCursorPos(" << x << "," << y
            << ") failed: " << ::GetLastError() << "\n";
        return false;
    }
    INPUT input = {};
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = flags;
    if (::SendInput(1, &input, sizeof(input)) != 1) {
        std::cerr << "[!] SendInput(mouse) err=" << ::GetLastError() << "\n";
        return false;
    }
    return true;
}
