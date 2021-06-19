#include "lec70.h"

using namespace std;  //  std:: 생략가능

/*
  복사 생성자 오버로딩

  String s2 = s1;   //  복사 생성자 호출 됨

  이와 같은 형태로 기존 객체를 새로운 객체에 복사해서 생성 할 경우 
  복사 생성자가 호출 되어, 별도로 구현 하지 않아도 
  모든 멤버를 복사(얕은 복사) 하는 동작을 하게 됨
  ex) 
    String( const String &rhs ) {
      len = rhs.len;
      strData = rhs.strData;  //  얕은 복사임으로, 실행시 문제가 됨...
    }

  strData 에 대해 깊은 복사가 필요 함
*/

class String {

  private:
    char *strData;
    int len;

  public:

    String() {
      cout << "String()" << endl;
      strData = NULL;
      len = 0;
    }

    String( const char *str ) {
      cout << "String( const char * )" << endl;
      len = strlen( str );
      strData = new char[ len + 1 ];  //  길이(len) + 1('\0' 추가)
      cout << "strData 할당 : " << (void*)strData << endl;
      strcpy( strData, str );   //  깊은 복사
    }

    //  복사 생성자 오버로딩
    String( const String &rhs ) {
      cout << "String( const String &rhs )" << endl;
      len = rhs.len;
      // strData = rhs.strData;  //  얕은 복사임으로, 실행시 문제가 됨...
      //  다음과 같이 오류 수정
      strData = new char[len];
      cout << "strData 할당 : " << (void*)strData << endl;
      strcpy( strData, rhs.strData );   //  깊은 복사
      // String( rhs.GetStrData() );   //  해제시 아래와 같이 오류 발생 함...
      /*
String( const char * )
strData 할당 : 0x10db2d0
10
하이루~
String( const String &rhs )
String( const char * )
strData 할당 : 0x10db2f0
~String()
strData 해제 : 0x10db2f0
0
�E�H�]�f.�
~String()
free(): invalid pointer
signal: aborted (core dumped)
      */
    }

    ~String() {
      cout << "~String()" << endl;
      delete[] strData;
      cout << "strData 해제 : " << (void*)strData << endl;
      strData = NULL;
    }

    char *GetStrData() const {  //  포인터 리턴
      return strData;
    }

    int GetLen() const {
      return len;
    }

};

//  70. 깊은 복사와 얕은 복사 (2) - 복사 생성자 오버로딩
void lec70() {

  title_header( "70. 깊은 복사와 얕은 복사 (2) - 복사 생성자 오버로딩" );

  String s1( "하이루~" );
  cout << s1.GetLen() << endl;
  cout << s1.GetStrData() << endl;

  // String s2 = s1;   //  복사 생성자 호출 됨
  String s2( s1 );   //  복사 생성자 호출 됨
  cout << s2.GetLen() << endl;
  cout << s2.GetStrData() << endl;
}
