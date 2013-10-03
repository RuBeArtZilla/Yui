#ifndef YUI_MODULE_MANAGER_H
#define YUI_MODULE_MANAGER_H
#pragma once

#include "YuiCore.h"

namespace yui{
	
	#define MODULE_MANAGER_VERSION 0x0101

	class ModuleManager : public Module {
	
	private:
		ModuleList modules_;

	public:
		ModuleManager(Module * parent = 0);
	
	};
}

#endif /* YUI_MODULE_MANAGER_H */