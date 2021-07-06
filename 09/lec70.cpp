#include "lec70.h"

using namespace std;  //  std:: 생략가능

/*
  임시객체는 r-value
  &&r 은 r-value 참조자
  ex) String &&r = getString();
*/

class String {

  private:

    char *strData;
    int len;

    //  메모리 공간 할당
    void alloc( int len ) {
      strData = new char[ len + 1 ];  //  길이(len) + 1('\0' 추가)
      cout << "strData 할당 : " << (void*)strData << endl;
    }

    //  할당된 메모리 공간 해제
    void release() {
      delete[] strData;
      cout << "strData 해제 : " << (void*)strData << endl;
    }


  public:

    String() {
      cout << "String() : " << this << endl;
      strData = NULL;
      len = 0;
    }

    String( const char *str ) {
      cout << "String( const char * ) : " << this << endl;
      len = strlen( str );
      alloc( len );             //  메모리 공간 할당
      strcpy( strData, str );   //  깊은 복사
    }

    //  복사 생성자 오버로딩
    String( const String &rhs ) {
      cout << "String( const String & ) : " << this << endl;
      len = rhs.len;
      alloc( len );             //  메모리 공간 할당
      strcpy( strData, rhs.strData );   //  깊은 복사
    }

    //  임시객체는 r-value 이며 
    //  &&rhs 는 r-value 참조
    //  얖은 복사 실행
    String( String &&rhs ) {
      cout << "String( String && ) : " << this << endl;
      len = rhs.len;
      strData = rhs.strData;  //  얕은 복사
      rhs.strData = NULL;     //  rhs 의 소멸자가 호출 되더라도 기존의 strData 는 남게 됨
    }

    ~String() {
      cout << "~String() : " << this << endl;
      release();                //  할당된 메모리 공간 해제
      strData = NULL;
    }

    //  연산자 오버로딩
    String &operator=( const String &rhs ) {
      cout << "operator=( const String & ) : " << this << endl;
      if ( this != &rhs ) { //  인자로 받은 &rhs 와는 의미가 다름...
        len = rhs.len;
        release();              //  기존 할당된 메모리 공간 해제
        alloc( len );           //  메모리 공간 할당
        strcpy( strData, rhs.strData );   //  깊은 복사
      }
      return *this;
    }

    //  임시객체는 r-value 이며
    //  &&rhs 는 r-value 참조
    //  얖은 복사 실행
    String &operator=( String &&rhs ) {
      cout << "operator=( String && ) : " << this << endl;
      len = rhs.len;
      strData = rhs.strData;  //  얕은 복사
      rhs.strData = NULL;     //  rhs 의 소멸자가 호출 되더라도 기존의 strData 는 남게 됨
      return *this;
    }

    char *GetStrData() const {  //  포인터 리턴
      return strData;
    }

    int GetLen() const {
      return len;
    }

    void SetStrData( const char *str ) {
      cout << "void SetStrData( const char * ) : " << this << " / " << str << endl;
      len = strlen( str );
      alloc( len );
      strcpy( strData, str );
    }
};

String getString() {

  cout << "========== 2 ==========" << endl;

  String res( "AmadeusMK" );

  cout << "========== 3 ==========" << endl;

  return res;
}

//  70. 깊은 복사와 얕은 복사 (5) - 이동 생성자와 이동 대입 연산자
void lec70() {

  title_header( "70. 깊은 복사와 얕은 복사 (5) - 이동 생성자와 이동 대입 연산자" );

  String a;

  cout << "========== 1 ==========" << endl;

  a = getString();

  cout << "========== 4 ==========" << endl;

}

/*
실행결과: 깊은 복사가 한번만 일어남(최초 메모리 할당시)

String() : 0x7ffd30014cb8                 <=  String a
========== 1 ==========
========== 2 ==========
String( const char * ) : 0x7ffd30014ca8   <=  String res( "AmadeusMK" );
strData 할당 : 0xcda2e0                   <=  메모리 공간 할당 후 깊은 복사. res 생성 됨
========== 3 ==========
operator=( String && ) : 0x7ffd30014cb8   <=  
~String() : 0x7ffd30014ca8                <=  res 소멸
strData 해제 : 0
========== 4 ==========
~String() : 0x7ffd30014cb8                <=  a 소멸
strData 해제 : 0xcda2e0                   <=  a 가 소멸되지만, 메모리 주소는 res 에서 할당한 주소

*/