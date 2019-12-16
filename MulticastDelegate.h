#pragma once
#include <list>
#include <functional>

#include "Object.h"

class MulticastDelegate
{
public:
	template <class UserClass, class _Fx>
	void AddDynamic(UserClass* InUserObject, _Fx&& _Func)
	{
		std::function<void(void*)> function = std::bind(_Func, InUserObject);
		m_Delegate.push_back(function);
	}
public:
	std::list<std::function<void(Object*)>> m_Delegate;
};

