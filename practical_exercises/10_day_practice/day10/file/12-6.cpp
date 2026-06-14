// 12-6.cpp
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char const* argv[])
{
    fstream ioFile;
    ioFile.open("./a.dat", ios::out);
    ioFile << "张三" << "  " << 76 << " " << 98 << " " << 67 << endl; // L3
    ioFile << "李四" << "  " << 89 << " " << 70 << " " << 60 << endl;
    ioFile << "王十" << "  " << 91 << " " << 88 << " " << 77 << endl;
    ioFile << "黄二" << "  " << 62 << " " << 81 << " " << 75 << endl;
    ioFile << "刘六" << "  " << 90 << " " << 78 << " " << 67 << endl;
    ioFile.close();
    ioFile.open("./a.dat", ios::in | ios::binary);
    char name[10];
    int chinese, math, computer;
    cout << "姓名\t" << "英语\t" << "数学\t" << "计算机\t" << "总分" << endl;
    ioFile >> name;
    while (!ioFile.eof())
    {
        ioFile >> chinese >> math >> computer;
        cout << name << "\t" << chinese << "\t" << math << "\t" << computer << "\t" << chinese + math + computer << endl;
        ioFile >> name;
    }
    ioFile.close();

    return 0;
}

/// yc-note: 实现演示 C++ 文件流（fstream）的基本读写操作。 向文件中写数据，之后再从文件中读数据
/// 上述code的执行逻辑： 以输出模式打开文件  --  写入数据 -- 关闭文件 -- 以输入模式重新打开文件 -- 读取并计算总分 -- 关闭文件
///
/// 注意：上述写入时，用的是文本模式(ios::out), 读取时用的是二进制模式(ios::binary)。实际操作中，读写模式应该保持一致，否则可能在不同操作系统上出问题。
///
/// 上述code中可能存在的问题：
///
///     a 读写模式不一致；
///     b 数组大小固定， 可能溢出；
///     c eof() 的使用方式不严谨。 参考如下修改：
// int main(int argc, char const* argv[])
// {
//     fstream outFile;
//     outFile.open("./a.dat", ios::out);
//     outFile << "张三" << "  " << 76 << " " << 98 << " " << 67 << endl; // L3
//     outFile << "李四" << "  " << 89 << " " << 70 << " " << 60 << endl;
//     outFile << "王十" << "  " << 91 << " " << 88 << " " << 77 << endl;
//     outFile << "黄二" << "  " << 62 << " " << 81 << " " << 75 << endl;
//     outFile << "刘六" << "  " << 90 << " " << 78 << " " << 67 << endl;
//     outFile.close();
//
//     fstream inFile;
//     inFile.open("./a.dat", ios::in);
//     // char name[10];
//     string name;
//     int chinese, math, computer;
//     cout << "姓名\t" << "英语\t" << "数学\t" << "计算机\t" << "总分" << endl;
//     // while (!ioFile.eof())
//
//     while (inFile >> name >> chinese >> math >> computer    )
//     {
//         cout << name << "\t" << chinese << "\t" << math << "\t" << computer << "\t"  << chinese + math + computer << endl;
//     }
//     inFile.close();
//
//     return 0;
// }
