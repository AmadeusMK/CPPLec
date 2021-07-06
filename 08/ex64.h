#include <iostream>
#include "../util/utils.h"

using namespace std;  //  std:: 생략가능

//  64. 8부(클래스) 종합문제 - 2
void ex64();

class MyClass {

  public:
    MyClass();
    void Check( MyClass* );

    static int cnt;

  private:
    int num;
    char ch;
};