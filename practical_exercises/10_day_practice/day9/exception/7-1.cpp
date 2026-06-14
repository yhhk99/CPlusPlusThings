// Eg10-9.cpp
#include <iostream>
using namespace std;

class A
{
	int a;

public:
	A(int i = 0) : a(i) {}
	~A() { cout << "in A destructor..." << endl; }
};

class B
{
	A obj[3];
	double* pb[10];

public:
	B(int k)
	{
		cout << "int B constructor..." << endl;
		for (int i = 0; i < 100; i++)
		{
			pb[i] = new double[20000000000];
			if (pb[i] == 0)
				throw i;
			else
				cout << "Allocated 20000000 doubles in pb[" << i << "]" << endl;
		}
	}
};

int main()
{
	try
	{
		B b(2);
	}
	catch (int e)
	{
		cout << "catch an exception when allocated pb[" << e << "]" << endl;
	}
}


/// yc-note: 上述是内存分配异常处理的经典案例，演示了构造函数中分配大量内存时，如何通过异常处理机制清理已分配的资源
/// 上述模拟功能：
///		在B类的构造函数中，尝试分配10个超大数组，如果某次内存分配失败就抛出异常。
///	实际效果：
///		由于内存不足，可能在第一次或第二次分配时就失败 (pb[0]=nullptr or pb[1]=nullptr),然后程序就跳到catch
/// 哈哈，搞笑， 我的电脑竟然跑不出来失败的例子/捂脸。。。。