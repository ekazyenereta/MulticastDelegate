#include <iostream>
#include <functional>
#include "MulticastDelegate.h"

DECLARE_DYNAMIC_DELEGATE(ClassDelegateA);

class ClassA : public Object
{
public:
	ClassA() {
	}
	~ClassA() {}
	void func() {
		std::cout << "func : "  << std::endl;
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
	ClassDelegateA mdelegate;
};

int main()
{
	void func();
	ClassA classA;

	classA.mdelegate.AddDynamic(&classA, std::bind(&ClassA::func, classA));
	classA.mdelegate.AddDynamic(&classA, std::bind(&ClassA::func, classA));
	classA.mdelegate.AddDynamic(&classA, std::bind(&ClassA::func, classA));
	classA.mdelegate.AddDynamic(&classA, std::bind(&ClassA::func, classA));
	classA.mdelegate.AddDynamic(&classA, std::bind(&ClassA::func, classA));
	classA.mdelegate.AddDynamic(&classA, std::bind(&ClassA::func, classA));

	classA.mdelegate.Broadcast();

	std::system("PAUSE");
}
