// Eg10-12.cpp
#include <iostream>
using namespace std;

class BasicException
{
public:
    char* Where() { return "BasicException..."; }
};

class FileSysException : public BasicException
{
public:
    char* Where() { return "FileSysException..."; }
};

class FileNotFound : public FileSysException
{
public:
    char* Where() { return "FileNotFound..."; }
};

class DiskNotFound : public FileSysException
{
public:
    char* Where() { return "DiskNotFound..."; }
};

int main()
{
    try
    {
        //         .....  //程序代码
        throw FileSysException();
    }
    catch (DiskNotFound p)
    {
        cout << p.Where() << endl;
    }
    catch (FileNotFound p)
    {
        cout << p.Where() << endl;
    }
    catch (FileSysException p)
    {
        cout << p.Where() << endl;
    }
    catch (BasicException p)
    {
        cout << p.Where() << endl;
    }
    try
    {
        //        .....  //程序代码
        throw DiskNotFound();
    }
    catch (BasicException p)
    {
        cout << p.Where() << endl;
    }
    catch (FileSysException p)
    {
        cout << p.Where() << endl;
    }
    catch (DiskNotFound p)
    {
        cout << p.Where() << endl;
    }
    catch (FileNotFound p)
    {
        cout << p.Where() << endl;
    }
}


/// yc-note: 演示 C++ 异常处理中，catch 块的匹配顺序和向上转型（upcasting）机制
/// code通过两个try和一组继承关系异常的类，展示“编译器按照顺序匹配catch块，且会有限匹配基类“这一容易出错的行为。
/// code中有异常基类A， 派生类B-A， 派生类C-B， 派生类D-B，且每个类都有一个虚函数，用于返回标识自身类型的字符串。 在派生类B-A中抛出异常， 之后在派生类D-B抛出异常。
/// 针对code的说明：
///     第一个try，抛出FilesSysException 异常， 之后会根据catch从上到下匹配，异常类型，当匹配成功后，执行异常语句块。注意，这里匹配的是基类引用（或值）， 因为FileSysException的引用可以绑定到自身对象。
///     第二个try，抛出DiskNotFound 类型的对象。之后在catch中进行匹配，因为 DiskNotFound 是 BasicException 的子孙类，基类引用/指针可以指向派生类对象。这是向上转型（upcasting）。
///
/// 说明：
/// 虽然code基本类似，但是第一try是catch 派生类 FilesSysException，因此执行的是派生类中的信息；
/// 而第二个try从上到下先catch 基类BasicException，再catch 派生类 DiskNotFound，但是因为 DiskNotFound继承自FileSysException，
/// FileSysException继承自BasicException，因此会存在 DiskNotFound异常向上传递的问题
///
/// 注意： 根据上述案例需要明确：
///     a catch块的顺序至关重要：必须将最具体的派生类异常放到前面，最通用的积累异常放到后面。
///     b 避免对象切片： 捕获异常时，应该使用 catch (const ExceptionType& e) （用引用）而不是 catch (ExceptionType e) （用传值）。
///         用传值不仅会导致派生类信息被切掉，还可能会产生额外的拷贝开销。
///     c 理解异常匹配的单一性： try只会进入第一个匹配的catch块。