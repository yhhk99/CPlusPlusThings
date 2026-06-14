#include <iostream>
using namespace std;
//函数原型
// put(char c)
// write(const char*c, int n)
int main()
{
    char c;
    char a[50] = "this is a string...";
    cout << "use get() input char:";
    while ((c = cin.get()) != '\n')
    {
        cout.put(c);                // yc-note 输出 字符c
        cout.put('\n');             // yc-note 输出 换行符
        cout.put('t').put('h').put('i').put('s').put('\n');     // yc-note 链式调用，输出this并换行
        cout.write(a, 12).put('\n');        // yc-note 输出字符数组a的前12个字符，并换行
        cout << "look"
            << "\t here!" << endl;
    }
}

/// yc-note： C++ 字符/字符串输出成员函数 put() 和 write() 的用法。
///     cout.put(char c) —— 输出单个字符
///     cout.write(const char* str, int n) —— 输出指定长度的字符串
///
///  注意：
///     a cout.write() 不会自动添加结尾符
///         cout.write(a, 50), 如果a长度小于50，会输出数组越界的内容
///     b 链式调用的等价写法:
///         cout.put('t').put('h').put('i').put('s').put('\n');
///         cout("this");
///
/// 小结： 上述代码演示了 C++ 输出流的两大成员函数：put() 用于输出单个字符并支持链式调用，write() 用于输出指定长度的字符串（不受 \0 限制）。