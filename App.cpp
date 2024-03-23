/*
 * Copyright 2024, Santiago Lema <santiago@lema.org>
 * All rights reserved. Distributed under the terms of the MIT license.
 */


#include "App.h"
#include "MainWindow.h"

#include <AboutWindow.h>
#include <Catalog.h>

#undef B_TRANSLATION_CONTEXT
#define B_TRANSLATION_CONTEXT "Application"

const char* kApplicationSignature = "application/x-vnd.slema-Atomique";


App::App()
	:
	BApplication(kApplicationSignature)
{
	MainWindow* mainWindow = new MainWindow();
	mainWindow->Show();
}


App::~App()
{
}


void
App::AboutRequested()
{
	BAboutWindow* about = new BAboutWindow(B_TRANSLATE_SYSTEM_NAME("Atomique.org"), kApplicationSignature);
	about->AddDescription(B_TRANSLATE("This is what I have to say here, nothing"));
	about->AddCopyright(2024, "Santiago Lema");
	about->AddExtraInfo("There is also some extra info here");
	about->Show();
}


int
main()
{
	App* app = new App();
	app->Run();
	delete app;
	return 0;
}
