#include <iostream>
using namespace std;

class BasicException
{
public:
    virtual string Where() { return "BasicException..."; }
};

class FileSysException : public BasicException
{
public:
    virtual string Where() { return "FileSysException..."; }
};

class FileNotFound : public FileSysException
{
public:
    virtual string Where() { return "FileNotFound..."; }
};

class DiskNotFound : public FileSysException
{
public:
    virtual string Where() { return "DiskNotFound..."; }
};

int main()
{
    try
    {
        //        .....  //程序代码
        DiskNotFound err;
        throw &err;
    }
    catch (BasicException* p)
    {
        cout << p->Where() << endl;
    }
}



/// yc-note： 这里验证的应该是异常捕获和虚函数之间的关系。 验证异常捕获与虚函数机制之间的配合关系
///
/// 1 异常捕获的向上转型：
/// 2 虚函数的动态绑定： 通过基类指针调用派生类的Where()