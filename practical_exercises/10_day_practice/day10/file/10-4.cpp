#include <iostream>
using namespace std;

int main(int argc, char const* argv[])
{
    char c[30] = "this is string";
    double d = -1231.232;
    cout.width(30);             // yc-note 设置输出宽度为30
    cout.fill('*');              // yc-note 设置填充字符为*
    cout.setf(ios::left);       // yc-note 设置对齐方式为左对齐
    cout << c << "----L1" << endl;   // yc-note: 左对齐：c 填充内容 ----L1
    cout.width(30);
    cout.fill('-');
    cout.setf(ios::right);
    cout << c << "----L2" << endl;      // yc-note： 右对齐： 填充物 c ----L1
    cout.setf(ios::dec | ios::showbase | ios::showpoint);
        // yc-note dec： 十进制默认显示； showbase： 显示进制前缀（十进制无前缀）； showpoint： 强制显示小数点；

    cout.width(30);
    cout << d << "----L3" << "\n";      // yc-note -----------------------1231.23----L3
    cout.setf(ios::showpoint);
    cout.precision(10);             // yc-note 设置有效数字为10位
    cout.width(30);
    cout << d << "----L4" << "\n";          // yc-note -1231.232000
    cout.width(30);
    cout.setf(ios::oct, ios::basefield);    // yc-note oct： 清除进制标志； basefield： 设置为八进制
    cout << 100 << "----L5" << "\n";

    return 0;
}


/// yc-note： C++格式化输出，演示如何使用流操作器来控制控制台输出的对齐格式、填充字符、数字进制、和浮点数精度。
///
/// 核心功能是通过cout的成员函数 width(), fill(), setf(), precision() 来格式化输出字符串和浮点数以及整数
///
///
