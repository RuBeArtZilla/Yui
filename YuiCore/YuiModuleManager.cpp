#include "YuiModuleManager.h"

//-----------------------------------------------------------------------------
yui::ModuleManager::ModuleManager(Module * parent) : Module(parent){
	version_ = MODULE_MANAGER_VERSION;
	enabled_ = true;
}

//-----------------------------------------------------------------------------
yui::ModuleList yui::ModuleManager::modules(){
	return modules_;
}

//-----------------------------------------------------------------------------
bool yui::ModuleManager::add(Module * pModule){
	if (pModule){
		modules_.push_back(pModule);
		pModule->set_parent(this);
		return true;
	}
	return false;
}

//-----------------------------------------------------------------------------
bool yui::ModuleManager::addnload(Module * pModule){
	if (pModule){
		Module * pOldParent = pModule->parent();
		pModule->set_parent(this);
		if (pModule->load()){
			modules_.push_back(pModule);
			return true;
		}
		else{
			pModule->set_parent(pOldParent);
		}
	}
	return false;
}
//-----------------------------------------------------------------------------
bool yui::ModuleManager::scannload(std::wstring paths) {
	
	return false;
}