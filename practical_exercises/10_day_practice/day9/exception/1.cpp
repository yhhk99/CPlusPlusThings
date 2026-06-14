// Eg10-1.cpp
#include <iostream>
using namespace std;
int main() {
  cout << "1--befroe try block..." << endl;
  try {
    cout << "2--Inside try block..." << endl;
    throw 10;     // yc-note： 这里抛出int类型异常
    cout << "3--After throw ...." << endl;    // yc：这里就永远不会被执行了
  } catch (int i) {     // yc-note： 匹配int类型。 捕获int类型异常。
    cout << "4--In catch block1 ... exception..errcode  is.." << i << endl;
  } catch (char *s) {   // yc-note：匹配char类型。 但是，这里永远不会被执行。。 注意，这里可以使用const char *s 或 string s 替换。
    cout << "5--In catch block2 ... exception..errcode is.." << s << endl;
  }
  cout << "6--After Catch...";
  
}
