// Eg10-7.cpp
#include <iostream>
using namespace std;
//内部再次throw异常的时候，函数不要带throw()
void Errhandler(int n)
{
	try
	{
		if (n == 1)
			throw n; // yc-note： first throw 1
		cout << "all is ok..." << endl;
	}
	catch (int n)
	{
		cout << "catch an int exception inside..." << n << endl; // yc-note: second output info
		throw n; //再次抛出本catch捕获的异常      // yc-note： third throw 1
	}
}

int main()
{
	try
	{
		Errhandler(1);
	}
	catch (int x)
	{
		cout << "catch int an exception in main..." << x << endl; // yc-note： fourth output info
	}
	cout << "....End..." << endl;

	return 0;
}

/// yc-note:演示异常的嵌套处理和重新抛出机制，验证try-catch 的层级关系和异常传播。
///
/// 1 异常的层级传播： 不是所有异常都必须立即处理； 可在不同的层级处理不同的异常； 底层可以“部分处理“后继续向上传递
/// 2
///
