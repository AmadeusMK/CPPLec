#include "lec65.h"

using namespace std;  //  std:: 생략가능

/*
  정적 할당 : 프로그램 실행이나, 함수 실행과 동시에 메모리 할당. ex) int a;
  동적 할당 : 프로그램 실행 중에 변수를 메모리에 할당 하는 것. 주로 배열을 동적 할당 함
*/

//  65. 동적 할당
void lec65() {

  title_header( "65. 동적 할당" );

  // dynamic_assign();

  // dynamic_array_assign();

  dynamic_class_assign();
}

void dynamic_assign() {

  title_header( "포인터 사용" );

  // int a = 5; 또는 int a(5);
  int *a = new int(5);    //  메모리 공간 할당 및 값(5) 저장

  cout << a << endl;
  cout << *a << endl;

  *a = 10;
  cout << a << endl;
  cout << *a << endl;

  delete a;   //  메모리 공간 해제
}

void dynamic_array_assign() {

  title_header( "배열 동적 할당" );

  int *arr;   //  &arr[0] 와 동일한 의미
  int len;    //  len 길이 만큼의 배열을 할당

  cout << "동적 할당할 배열 길이 입력 : ";
  cin >> len;

  arr = new int[len];

  for ( int i ; i < len ; i++ ) {
    arr[i] = len - i;
  }

  for ( int i ; i < len ; i++ ) {
    cout << arr[i] << endl;
  }

  delete[] arr;   //  배열의 메모리 공간 전체를 해제
}

class Vector2 {

  private:
    float x, y;

  public:
    Vector2() : x(0), y(0) {
      cout << this << " : Vector2()" << endl;
    }
    Vector2( const float x, const float y ) : x(x), y(y) {
      cout << this << " : Vector2( const float x, const float y )" << endl;
    }
    ~Vector2() {
      cout << this << " : ~Vector2()" << endl;
    }
    float GetX() const { return x; }
    float GetY() const { return y; }
};

void dynamic_class_assign() {

  title_header( "객체(class) 동적 할당" );

  Vector2 *d1 = new Vector2();
  Vector2 *d2 = new Vector2( 3, 2 );

  cout << "d1 : " << d1 << endl;
  cout << "d2 : " << d1 << endl;

  cout << "d1 : ( " << d1->GetX() << ", " << d1->GetY() << " )" << endl;
  cout << "d2 : ( " << d2->GetX() << ", " << d2->GetY() << " )" << endl;

  delete d1;
  delete d2;
}