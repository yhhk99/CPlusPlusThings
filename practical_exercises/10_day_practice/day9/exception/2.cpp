// Eg10-2.cpp
#include <iostream>
using namespace std;
int main() {
  cout << "1--befroe try block..." << endl;
  try {
    cout << "2--Inside try block..." << endl;
    throw 10;     // yc-note： 这里抛出int类型异常。
    cout << "3--After throw ...." << endl;
  } catch (double i) { //仅此与例10.1不同   // yc-note： 匹配double数据类型。该行永远不会被触发
    cout << "4--In catch block1 .. an int type is.." << i << endl;
  }
  cout << "5--After Catch...";
  
  return 0;
}


/// yc-note: 这里line 8 抛出int异常， 到line10，int 和double不匹配，因此跳过line11-line15.
/// 注意： C++异常处理的关键规则是
///   规则1: 类型必须精确匹配。异常匹配不执行标准类转换（int-double）
///   规则2: 未捕获异常的后果。 程序会调用std::terminate() 终止
///
/// 如何修复上述问题：
///   方法1 使用正确的catch类型： catch(int i)
///   方法2 使用多态catch（捕获多种异常类型）
///   方法3 使用万能catch兜底： catch(...)
///