#pragma once
#include <list>
#include <functional>

#include "Object.h"

class MulticastDelegate
{
public:
	template <class UserClass>
	void AddDynamic(UserClass* InUserObject, std::function<void(void*)> _Func)
	{
		m_Delegate.push_back(_Func);
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