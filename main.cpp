#include <iostream>
#include <functional>
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

class FuncClass
{
public:
	void func0() {
		std::cout << "func : " << std::endl;
	}
	void func1(int value1) {
		std::cout << "func : " << value1 << std::endl;
		nValue += value1;
	}
	void func2(int value1, int value2) {
		std::cout << "func : " << value1 << value2 << std::endl;
		nValue += value1 + value2;
	}
	void func3(int value1, int value2, int value3) {
		std::cout << "func : " << value1 << value2 << value3 << std::endl;
		nValue += value1 + value2 + value3;
	}
	void func4(int value1, int value2, int value3, int value4) {
		std::cout << "func : " << value1 << value2 << value3 << value4 << std::endl;
		nValue += value1 + value2 + value3 + value4;
	}
	void func5(int value1, int value2, int value3, int value4, int value5) {
		std::cout << "func : " << value1 << value2 << value3 << value4 << value5 << std::endl;
		nValue += value1 + value2 + value3 + value4 + value5;
	}
	void func6(int value1, int value2, int value3, int value4, int value5, int value6) {
		std::cout << "func : " << value1 << value2 << value3 << value4 << value5 << value6 << std::endl;
		nValue += value1 + value2 + value3 + value4 + value5 + value6;
	}
	void func7(int value1, int value2, int value3, int value4, int value5, int value6, int value7) {
		std::cout << "func : " << value1 << value2 << value3 << value4 << value5 << value6 << value7 << std::endl;
		nValue += value1 + value2 + value3 + value4 + value5 + value6 + value7;
	}
	void func8(int value1, int value2, int value3, int value4, int value5, int value6, int value7, int value8) {
		std::cout << "func : " << value1 << value2 << value3 << value4 << value5 << value6 << value7 << value8 << std::endl;
		nValue += value1 + value2 + value3 + value4 + value5 + value6 + value7 + value8;
	}
	void func9(int value1, int value2, int value3, int value4, int value5, int value6, int value7, int value8, int value9) {
		std::cout << "func : " << value1 << value2 << value3 << value4 << value5 << value6 << value7 << value8 << value9 << std::endl;
		nValue += value1 + value2 + value3 + value4 + value5 + value6 + value7 + value8 + value9;
	}
public:
	int nValue = 0;
};

void Func1(const int i);
void Func1(const int i)
{
	std::cout << i << std::endl;
}

int main()
{
	int nValue = 1;
	FuncClass funcClass;
	ClassDelegate0 class0;
	ClassDelegate1 class1;
	ClassDelegate2 class2;
	ClassDelegate3 class3;
	ClassDelegate4 class4;
	ClassDelegate5 class5;
	ClassDelegate6 class6;
	ClassDelegate7 class7;
	ClassDelegate8 class8;
	ClassDelegate9 class9;

	class0.AddDynamic0(&FuncClass::func0, &funcClass);
	class0.Broadcast();

	class1.AddDynamic1(&FuncClass::func1, &funcClass);
	class1.Broadcast(nValue);

	class2.AddDynamic2(&FuncClass::func2, &funcClass);
	class2.Broadcast(nValue, nValue);

	class3.AddDynamic3(&FuncClass::func3, &funcClass);
	class3.Broadcast(nValue, nValue, nValue);

	class4.AddDynamic4(&FuncClass::func4, &funcClass);
	class4.Broadcast(nValue, nValue, nValue, nValue);

	class5.AddDynamic5(&FuncClass::func5, &funcClass);
	class5.Broadcast(nValue, nValue, nValue, nValue, nValue);

	class6.AddDynamic6(&FuncClass::func6, &funcClass);
	class6.Broadcast(nValue, nValue, nValue, nValue, nValue, nValue);

	class7.AddDynamic7(&FuncClass::func7, &funcClass);
	class7.Broadcast(nValue, nValue, nValue, nValue, nValue, nValue, nValue);

	class8.AddDynamic8(&FuncClass::func8, &funcClass);
	class8.Broadcast(nValue, nValue, nValue, nValue, nValue, nValue, nValue, nValue);

	class9.AddDynamic9(&FuncClass::func9, &funcClass);
	class9.Broadcast(nValue, nValue, nValue, nValue, nValue, nValue, nValue, nValue, nValue);

	std::cout << "func nValue: " << funcClass.nValue << std::endl;

	class1.__Internal_AddDynamic(&Func1);
	class1.Broadcast(10);

	std::system("PAUSE");
}
