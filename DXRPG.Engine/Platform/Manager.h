#pragma once
#include <Platform/Platform.h>

	template<class R, typename S>
	class __DLLEXPORT Manager
	{
	public:
		Manager() {};

		virtual ~Manager() {
		};

		virtual void Add(const S& id, const R& resource);
		virtual void Remove(const S& id);
		virtual void Bind(const S& id);
		virtual void Unbind(const S& id);
	private:

	};

