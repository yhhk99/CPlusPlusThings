#include <iostream>
using namespace std;
void temperature(int t) {

  if (t == 100)
    throw "沸点！";
  else if (t == 0)
    throw "冰点！";
  else {
    cout << "temperatore=" << t << endl;
  }
}
int main() {
  try {
    temperature(0);   // L1
    temperature(10);  // L2
    temperature(100); // L3
  } catch (char const *s) {
    cout << s << endl;
  }
  
  return 0;
}


/// yc-note：演示如果没有catch只有throw会有什么问题
/// 异常会中断执行流程。当异常抛出后， try后面的code不会被执行
///
/// 1 异常是 “非局部跳转”（Non-local jump）。 异常不会像调用函数返回值那样“正常返回”，而是会展开调用栈，直接跳转到异常处理程序。
/// 2 异常处理流程和正常流程是两条路： 正常流程是顺利执行完所有语句-函数正常返回-继续执行后续调用； 异常流程是遇到throw立即中断-函数提前退出-跳过所有后续调用。
///
///
/// 小结： C++异常处理是有中断性--throw不会返回，而是流程紧急制动；一旦触发，整个try块立即停止，后续code全部失效。
/// 该场景适合需要“原子性”场景（如事务），但不适合处理相互独立的多个事件。