// Eg12-7.cpp
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    char ch;
    ofstream out("/test.dat", ios::out | ios::binary); // L1
    for (int i = 0; i < 90; i++)
    {
        if (i > 0 && (i % 30) == 0)
            out.put('\n');
        out.put(i);
        out.put(' ');
    }
    out.close();
    ifstream in("/test.dat", ios::in | ios::binary);
    while (in.get(ch))
        cout << ch;
    in.close();
}


/// yc-note: 以二进制模式向文件写入原始字节数据，然后再逐个字节读回并输出的过程。
///
///