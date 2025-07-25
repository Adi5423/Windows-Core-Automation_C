# WindowsAutomationTool

A pure C++ Windows automation toolkit — built from scratch using only the native Windows API (`windows.h`).  
No wrappers, no dependencies, no high-level abstractions.  
Just direct Win32 calls for true system-level automation.

## Features

- **Keyboard & Mouse Simulator**  
  Simulate keystrokes and mouse clicks using `SendInput`.  
  Type text, send virtual-key codes, and automate mouse actions.

- **Process Launcher**  
  Start any executable using `CreateProcessW`.  
  Example: Launch Notepad and automate its window.

- **Window Manager**  
  Find, enumerate, and interact with windows by class name or title.  
  Use `EnumWindows`, `FindWindowW`, and related APIs for robust window control.

- **Modular Architecture**  
  Each feature is encapsulated in its own class:  
  - `InputSimulator` — Keyboard/mouse input  
  - `ProcessHelper` — Process launching  
  - `WindowHelper` — Window enumeration and manipulation  
  - `Application` — Main automation flow  
  No precompiled headers, no external packages.

## Why This Project?

Most automation tools rely on high-level wrappers or scripting languages.  
This project demonstrates how to automate Windows at the lowest level, directly via Win32 API calls.  
It’s ideal for learning, debugging, or building robust automation tools without third-party dependencies.

## Getting Started

### Prerequisites

- **Windows 10/11** (x64 recommended)
- **Visual Studio 2022** (or later)
- **C++14** or newer

### Build Instructions

1. **Clone the repository**  
```bash
git clone <repo-url>
```

2. **Open the solution in Visual Studio**  
- Open `WindowsAutomationTool.sln` (or create a new project and add the source files).

3. **Build the project**  
- Select `Release` or `Debug` configuration.
- Press `Ctrl+Shift+B` or use the __Build Solution__ command.

### Run Instructions

1. **Run the executable**  
- Press `F5` (Start Debugging) or run the built `.exe` from the output directory.

2. **Demo Flow**  
- The tool will:
  - Launch Notepad
  - Wait for its window to appear
  - Bring Notepad to the foreground
  - Type “Hello from Win32 automation!” into Notepad

3. **Customize**  
- Modify `Application.cpp` to automate other processes or windows.
- Use `InputSimulator`, `ProcessHelper`, and `WindowHelper` for advanced automation.

## Code Overview

- `include/InputSimulator.hpp` — Keyboard/mouse simulation API
- `include/ProcessHelper.hpp` — Process launching API
- `include/WindowHelper.hpp` — Window enumeration/manipulation API
- `include/Application.hpp` — Main application class
- `src/InputSimulator.cpp` — Implementation of input simulation
- `src/ProcessHelper.cpp` — Implementation of process launching
- `src/WindowHelper.cpp` — Implementation of window management
- `src/Application.cpp` — Main automation flow

## Example: Automating Notepad
```text
const stdwstring notepad = L"C:\Windows\System32\notepad.exe"; ProcessHelperLaunch(notepad); HWND hwnd = WindowHelperFindWindowByTitle(L"Untitled - Notepad"); SetForegroundWindow(hwnd); InputSimulatorSendTextInput(L"Hello from Win32 automation!\n");
```


## Extending the Project

- Add more error handling and logging.
- Support for more input types (mouse drag, hotkeys, etc.).
- Automate other applications or system dialogs.
- Build a GUI for interactive automation.

## Philosophy

> “Bypass all layers and talk directly to the OS.”  
> No Python, no wrappers — just C++ and Win32.

## License

[MIT License](LICENSE)

---

**LinkedIn Post Inspiration:**  
Just hit a major milestone on my Windows automation project — built *completely from scratch* in pure C++ using the native Windows API (`windows.h`)!  
No wrappers. No dependencies. No high-level abstractions.  
Just raw `Win32`, `SendInput`, `EnumWindows`, `CreateProcessW`, and friends — coded directly.

What I built:
- A low-level **keyboard and mouse simulator** using `SendInput`
- A *process launcher* via `CreateProcessW`
- A *window manager* that can find, enumerate, and interact with windows by class/title
- All of this modularized into a clean architecture, no precompiled headers or external packages

C++ is a bit exhausting sometimes, but the end results always satisfy by core logics and perfect implementation of everything.  
Still need to implement a lot of error checks and features overall, but the base is ready.  
This is just the beginning — but such a cool feeling when you bypass all layers and talk directly to the OS.

---

*For questions or contributions, feel free to open an issue or pull request!*