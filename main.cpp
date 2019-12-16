#include <iostream>
#include <functional>
#include "MulticastDelegate.h"

class ClassA : public Object
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

class ClassB : public Object
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

	classA.mdelegate.AddDynamic(&classA, &ClassA::func);
	classA.mdelegate.AddDynamic(&classA, &ClassA::func);
	classA.mdelegate.AddDynamic(&classA, &ClassA::func);
	classA.mdelegate.AddDynamic(&classA, &ClassA::func);
	classA.mdelegate.AddDynamic(&classA, &ClassA::func);
	classA.mdelegate.AddDynamic(&classA, &ClassA::func);

	for (auto& mdelegate : classA.mdelegate.m_Delegate)
	{
		mdelegate(&classA);
	}

	std::system("PAUSE");
}
