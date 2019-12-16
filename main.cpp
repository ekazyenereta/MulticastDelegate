#include <iostream>
#include <functional>
#include "MulticastDelegate.h"

struct ClassA : public Object
{
public:
	ClassA() {
	}
	~ClassA() {}
	void func() {
		std::cout << "func" << std::endl;
	}
public:
	MulticastDelegate mdelegate;
};

struct ClassB : public Object
{
public:
	ClassB() {
	}
	~ClassB() {}
	void func() {
		std::cout << "func!?" << std::endl;
	}
public:
	MulticastDelegate mdelegate;
};

int main()
{
	void func();
	ClassA classA;


	std::function<void(void*)> members = std::bind(&ClassA::func, classA);
	std::list< std::function< void(Object*) >> sdelegate;
	sdelegate.push_back(members);


	classA.mdelegate.AddDynamic(&classA, std::bind(&ClassA::func, classA));
	classA.mdelegate.AddDynamic(&classA, std::bind(&ClassA::func, classA));
	classA.mdelegate.AddDynamic(&classA, std::bind(&ClassA::func, classA));
	classA.mdelegate.AddDynamic(&classA, std::bind(&ClassA::func, classA));
	classA.mdelegate.AddDynamic(&classA, std::bind(&ClassA::func, classA));
	classA.mdelegate.AddDynamic(&classA, std::bind(&ClassA::func, classA));

	for (auto& mdelegate : classA.mdelegate.m_Delegate)
	{
		mdelegate(&classA);
	}

	std::system("PAUSE");
}
