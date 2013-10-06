// YuiOutDX.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

 extern "C" __declspec(dllexport) yui::Module* yui::DllLoadModule() {
	 return 0;
}


class TestOutput : public yui::Module {
	

};
