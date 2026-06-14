// Eg12-5.cpp
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    char c[30] = "this is string";
    double d = -1234.8976;
    cout << setw(30) << left << setfill('*') << c << "----L1" << endl;
    cout << setw(30) << right << setfill('*') << c << "----L2" << endl;
    // showbase显示数值的基数前缀
    cout << dec << showbase << showpoint << setw(30) << d << "----L3" << "\n";
    // showpoint显示小数点
    cout << setw(30) << showpoint << setprecision(10) << d << "----L4" << "\n";
    // setbase(8)设置八进制
    cout << setw(30) << setbase(16) << 100 << "----L5"  << "\n";
}


/// yc-note 这部分的code和 10-4 中的code是不是很相似.
/// 使用流操纵符（stream manipulators）进行格式化输出。功能等同于 10-4中使用 cout.width(), cout.fill(), cout.setf()
///
/// 对比12-5 和 10-4 中差别 12-5，  使用流操作符， 10-4 使用成员函数。
/// |对比项    |   成员函数方式  |   流操作符方式  |
/// |代码长度   |   较长  |   简洁  |
/// |可读性    |   一般  |   更好（声明式  |
/// |持久性    |   有些要重复设置 |   大部分持久   |
/// |需要头文件  |   <iostream>  |   <iomanip>   |
///
/// 注意事项：
///     a setw()   是一次性的；
///     b setfill(), left/right, showbase 等都是持久的；
///     c setprecision() 是持久的；
///     d setbase() 只支持 8， 10， 16