// Eg10-6.cpp
#include <iostream>
using namespace std;
void Errhandler(int n) throw() {
  try {
    if (n == 1)
      throw n;
    if (n == 2)
      throw "dx";
    if (n == 3)
      throw 1.1;
  } catch (...) {
    cout << "catch an exception..." << endl;
  }
}
int main() {
  Errhandler(1);
  Errhandler(2);
  Errhandler(3);
  
  return 0;
}

/// yc-note: 这里是为了说明catch(...) 能够捕获任何类型的异常问题。
///
/// 1 catch(...) 的典型使用场景：
///   a 防止异常泄漏（本例）；
///   b 异常隔离（让程序继续运行）；
///   c 资源清理兜底
///   d 记录未知异常
///
/// 2 catch(...) 局限性：
///   a 无法获取异常的具体信息： 不清楚抛出异常类型； 不清楚抛出异常的值；只知道发生了异常；
///   b 不能针对不同的类型做不同的处理： 所有异常的处理方式都是一样的；
///   c 使用时有建议顺序： 先捕获具体的标准异常，再捕获已知的具体类型，然后捕获其他已知异常，最后使用万能捕获兜底；
