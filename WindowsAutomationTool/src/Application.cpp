#include "Application.hpp"
#include <iostream>
#include <thread> // for sleep
#include <chrono> // for seconds

Application::Application()
	: guiEnabled_(false)
{ }

int Application::Run(int argc, char* argv[]) {
    std::cout << "Windows Automation Tool v0.1\n";

    // 1) Launch Notepad
    const std::wstring notepad = L"C:\\Windows\\System32\\notepad.exe";
    if (!ProcessHelper::Launch(notepad)) {
        return 1;
    }

    // 2) Wait for the window to appear
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // 3) Find the Notepad window by title
    HWND hwnd = WindowHelper::FindWindowByTitle(L"Untitled - Notepad");
    if (!hwnd) {
        return 1;
    }

    // 4) Activate it (bring to foreground)
    SetForegroundWindow(hwnd);

    // 5) Type some text
    InputSimulator::SendTextInput(L"Hello from Win32 automation!\n");

    std::cout << "Demo complete. Exiting.\n";
    return 0;
}

void Application::ToggleGUI() {
    guiEnabled_ = !guiEnabled_;
    std::cout << "[*] GUI mode "
        << (guiEnabled_ ? "enabled" : "disabled")
        << "\n";
}