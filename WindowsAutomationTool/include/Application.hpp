#pragma once
#include <string>
#include "ProcessHelper.hpp"
#include "WindowHelper.hpp"
#include "InputSimulator.hpp"

// Manages application lifecycle: parsing args, toggling GUI(future), main loop.
class Application {

public:
	Application();
	// Entry point: pass args/argv from main()
	int Run(int argc, char* argv[]);

private:
	void ToggleGUI(); //placeholder for GUI toggle
	bool guiEnabled_;
};