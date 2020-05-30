#include <iostream>
#include "MulticastDelegate.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(ClassDelegate0);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(ClassDelegate1, int);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(ClassDelegate2, int, int);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(ClassDelegate3, int, int, int);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(ClassDelegate4, int, int, int, int);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FiveParams(ClassDelegate5, int, int, int, int, int);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(ClassDelegate6, int, int, int, int, int, int);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SevenParams(ClassDelegate7, int, int, int, int, int, int, int);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_EightParams(ClassDelegate8, int, int, int, int, int, int, int, int);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_NineParams(ClassDelegate9, int, int, int, int, int, int, int, int, int);

class DelegateTest
{
public:
	ClassDelegate0 eveDrawParam;
	ClassDelegate1 eveSetParam;
	ClassDelegate1 eveUpdate;
};


class DataClass
{
private:
	int value = 0;

public:
	DataClass(DelegateTest* world)
	{
		world->eveSetParam.AddDynamic1(&DataClass::SetData, this);
		world->eveDrawParam.AddDynamic0(&DataClass::Draw, this);
	}
	~DataClass() {}

private:
	void SetData(int value)
	{
		this->value = value;
	}
	void Draw()
	{
		std::cout << "Data : " << value << std::endl;
	}
};

class Control
{
private:
	DelegateTest* pWorld = nullptr;
public:
	Control(DelegateTest* world)
	{
		pWorld = world;
		world->eveUpdate.AddDynamic1(&Control::Update, this);
	}
	~Control() {}

private:
	void Update(int value)
	{
		pWorld->eveSetParam.Broadcast(value);
		pWorld->eveDrawParam.Broadcast();
	}
};

int main()
{
	DelegateTest delegateTest;
	DataClass dataClass(&delegateTest);
	Control dontrol(&delegateTest);

	delegateTest.eveSetParam.Broadcast(50);
	delegateTest.eveDrawParam.Broadcast();

	delegateTest.eveUpdate.Broadcast(100);

	std::system("PAUSE");
}
