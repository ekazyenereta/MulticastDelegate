#pragma once
#include <list>
#include <functional>

#include "Object.h"

#define DECLARE_DYNAMIC_DELEGATE(DelegateName) class DelegateName { struct Delegate { Delegate(Object* InUserObject, const std::function<void()> Func) :Func(Func), InUserObject(InUserObject) {}std::function<void()> Func;Object* InUserObject = nullptr;};std::list<Delegate> m_Delegate;public:void AddDynamic(Object* InUserObject, const std::function<void()> Func){m_Delegate.push_back(Delegate(InUserObject, Func));}void Broadcast(){for (auto& mdelegate : m_Delegate)mdelegate.Func();}};


class MulticastDelegate
{
	struct Delegate
	{
		Delegate(Object* InUserObject, const std::function<void()> Func) :Func(Func), InUserObject(InUserObject) {}
		std::function<void()> Func;
		Object* InUserObject = nullptr;
	};
	std::list<Delegate> m_Delegate;
public:
	void AddDynamic(Object* InUserObject, const std::function<void()> Func)
	{
		m_Delegate.push_back(Delegate(InUserObject, Func));
	}
	void Broadcast()
	{
		for (auto& mdelegate : m_Delegate)
			mdelegate.Func();
	}
};


//template<typename _Ty1>
//class MulticastDelegate
//{
//	struct Delegate
//	{
//		Delegate(Object* InUserObject, const std::function<void(_Ty1)> Func) :Func(Func), InUserObject(InUserObject) {}
//		std::function<void(_Ty1)> Func;
//		Object* InUserObject = nullptr;
//	};
//public:
//	void AddDynamic(Object* InUserObject, const std::function<void(_Ty1)> Func)
//	{
//		m_Delegate.push_back(Delegate(InUserObject, Func));
//	}
//public:
//	std::list<Delegate> m_Delegate;
//};


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