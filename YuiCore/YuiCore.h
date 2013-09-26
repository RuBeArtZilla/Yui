#ifndef YUI_CORE_H
#define YUI_CORE_H

namespace yui {
	
	typedef unsigned long Version;

	class Module {
	
	private:
		Module* parent_;
		Version version_;

	public:
		Module(Module* parent = 0) : parent_(parent){};
		virtual ~Module(){};
	
		virtual Module* parent() const {return parent_;};
		virtual void set_parent(Module* parent){parent_ = parent;};

		virtual Version version() const {return version_;};

	private:
		Module(const Module&);
		virtual void operator=(const Module&) = 0;
	};

}

#endif /* YUI_CORE_H */