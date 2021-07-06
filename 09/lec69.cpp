#include "lec69.h"

using namespace std;  //  std:: 생략가능

/*
  아래 예제의 경우 깊은 복사가 2번 일어나며, 
  2개의 곧 사라질 객체가 생성되었다가, 소멸한다.

  이런 비효율적인 상황을 해결 하기 위해서는, 
  얕은 복사를 사용 하며, 소멸자가 1번만 호출 되도록 
  C++ 컴파일러는 '이동' 이라는 컨셉을 지원 함
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

String getName() {

  cout << "========== 2 ==========" << endl;

  String res( "AmadeusMK" );

  cout << "========== 3 ==========" << endl;

  return res;
}

//  69. 깊은 복사와 얕은 복사 (4) - 이동 시멘틱
void lec69() {

  title_header( "69. 깊은 복사와 얕은 복사 (4) - 이동 시멘틱" );

  String a;

  cout << "========== 1 ==========" << endl;

  a = getName();

  cout << "========== 4 ==========" << endl;
}

/*
실행결과: 깊은 복사가 2번 일어남

String() : 0x7fff02c02d28                     <=  String a
========== 1 ==========
========== 2 ==========
String( const char * ) : 0x7fff02c02d18       <=  String res( "AmadeusMK" );
strData 할당 : 0x223d2d0                      <=  메모리 공간 할당 후 깊은 복사. res 생성 됨
========== 3 ==========
operator=( const String & ) : 0x7fff02c02d28  <=  a 에 리턴값 전달. 임시객체 생성 전달
strData 해제 : 0
strData 할당 : 0x223d2f0                      <=  메모리 공간 할당 후 깊은 복사
~String() : 0x7fff02c02d18                    <=  res 소멸
strData 해제 : 0x223d2d0
========== 4 ==========
~String() : 0x7fff02c02d28                    <=  a 소멸
strData 해제 : 0x223d2f0
*/