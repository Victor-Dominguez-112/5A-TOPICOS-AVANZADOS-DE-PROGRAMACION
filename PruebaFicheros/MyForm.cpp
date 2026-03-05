#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // "PruebaFicheros" es el namespace de tu proyecto
    PruebaFicheros::MyForm form;
    Application::Run(% form);

    return 0;
}