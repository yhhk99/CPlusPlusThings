// Eg10-5.cpp
#include <iostream>
using namespace std;

void handler(int n) throw(int, char, double) {
  if (n == 1)
    throw n;
  if (n == 2)
    throw 'x';
  if (n == 3)
    throw 1.1;
}
int main() {
  cout << "Before handler..." << endl;
  try {
    handler(1);
  } catch (int i) {
    cout << "catch an integer..." << endl;
  } catch (char c) {
    cout << "catch an char..." << endl;
  } catch (double d) {
    cout << "catch an double..." << endl;
  }
  
}

/// yc-note: 动态异常规范（Dynamic Exception Specification），可能已经废弃，但在其他项目中仍然可见
///
/// 动态异常规范被废弃的原因：
///   1 运行时检查，而不是编译时； 2 性能开销； 3 不是所有类型都支持； 4 部分特化问题
///
/// 现代方案的替代：自C++11起引入 noexcept 替代动态异常规范。
///
///