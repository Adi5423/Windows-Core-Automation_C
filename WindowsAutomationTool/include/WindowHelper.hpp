#pragma once

#include <Windows.h>
#include <vector>
#include <string>

// Simplifies common Win32 widnow operations :
// *Find windows by title or class
// *Enumerating top-level windows
// *Retriving window text, with error checks

class WindowHelper {
public:
	// Find the first top-level widnow with the exact title 
	// Returns NULL on failure (see GetLastError()).
	static HWND FindWindowByTitle(const std::wstring& title);

	//Enumarate all top-level windows matching the given class name.
	// Returns an empty vector on failure (or no matches).
	static std::vector<HWND> EnumWindowsByClassName(const std::wstring& className);

	// Get the window's current text(caption).
	// Returns empty string on failure (see GetLastError()).
	static std::wstring GetWindowText(HWND hwnd);

}; 
