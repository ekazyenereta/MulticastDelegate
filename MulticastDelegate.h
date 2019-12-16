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

//#define DECLARE_DYNAMIC_DELEGATE;
//#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam;
//#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams;
//#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams;
//#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams;
//#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams;
//#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams;
//#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_SevenParams;
//#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_EightParams;
//#define DECLARE_DYNAMIC_MULTICAST_DELEGATE_NineParams;