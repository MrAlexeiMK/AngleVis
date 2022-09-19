#include "AngleVis.h"
#include <Windows.h>

using namespace AngleVisualizer;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew AngleVis());
}