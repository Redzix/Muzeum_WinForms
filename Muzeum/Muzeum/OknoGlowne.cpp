#include "OknoGlowne.h"
#include "Classes.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<String^>^ args){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Muzeum::OknoGlowne form;
	Application::Run(%form);

}


