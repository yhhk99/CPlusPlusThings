#include <iostream>
using namespace std;
void temperature(int t) {
  try {
    if (t == 100)
      throw "It's at the boiling point.";
    else if (t == 0)
      throw "It reached the freezing point";
    else
      cout << "the temperature is OK..." << endl;
  } catch (int x) {
    cout << "temperature=" << x << endl;
  } catch (char const *s) {
    cout << s << endl;
  }
}
int main() {
  temperature(0);   // L1
  temperature(10);  // L2
  temperature(100); // L3
  
  return 0;
}

/// yc-note：
/// 异常处理的基本机制： try-throw-catch
///   try监控放在里面的code； throw 抛出，检测到错误条件的类型化信息； catch捕获对应类型化信息，并执行相应的catch块处理错误
/// 异常处理的类型匹配规则：基于数据类型，而不是基于值；如果改变抛出的类型，匹配会失败
///
/// 业务逻辑与错误处理的分离：函数内部专注于业务逻辑，有异常只负责上报（throw）；
///