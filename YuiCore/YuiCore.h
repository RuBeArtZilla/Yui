#ifndef YUI_CORE_H
#define YUI_CORE_H
#pragma once

#include <list>
//#include <string>
namespace yui {
	
	#ifdef YUI_HEADER_EXPORT
	#define YUI_HEADER_API extern "C" __declspec(dllexport) 
	#else
	#define YUI_HEADER_API extern "C" __declspec(dllimport) 
	#endif
	
	typedef unsigned long Version;

	class Module {
	
	protected:
		Module* parent_;
		Version version_;
		bool	enabled_;

	public:
		Module(Module* parent = 0) : parent_(parent){enabled_ = false;};
		virtual ~Module(){};

		virtual Module* parent() const {return parent_;};
		virtual void set_parent(Module* parent){parent_ = parent;};

		virtual Version version() const {return version_;};

		virtual bool enabled() const {return enabled_;};

		virtual bool load(){return enabled_ = true;};
		virtual bool unload(){return enabled_ = false;};

	private:
		Module(const Module&){};
		virtual void operator=(const Module&){};
	};

	typedef std::list<Module*> ModuleList;
	typedef std::list<Module*>::iterator ModuleListIterator;

	YUI_HEADER_API Module* DllLoadModule(); 
}

#endif /* YUI_CORE_H */