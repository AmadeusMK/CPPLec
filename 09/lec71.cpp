#include "lec71.h"

using namespace std;  //  std:: 생략가능

/*
  명시적 형변환 explicit conversion
  묵시적 형변환 implicit conversion

  형변환도 연산자이며, 오버로딩 가능

  생성자나, 형변환 연산자 오버로딩시  
  explicit 을 앞에 추가 할 경우, 명시적으로 형변환할 경우에만 호출 되도록 함
  원하지 않는 타입으로 묵시적 변환이 일어나는것을 차단 함
*/

class Item {

  private:
    int num;
    string name;

  public:

    Item() : num(0), name("") {}

    Item( int num ) : num(num) {        //  변환 생성자 역할도 함...
      cout << "Item( int ) : " << num << endl;
    }

    Item( string name ) : name(name) {  //  변환 생성자 역할도 함...
      cout << "Item( string ) : " << name << endl;
    }

    Item( int num, string name ) : num(num), name(name) { //  변환 생성자 역할도 함...
      cout << "Item( int, string ) : " << num << " / " << name << endl;
    }

    void print() const {
      cout << num << " : " << name << endl;
    }

    //  int 로의 형변환 연산자 오버로딩
    operator int() const {
      return num;
    }

    //  string 으로의 형변환 연산자 오버로딩
    explicit operator string() const {
      return to_string( num ) + " : " + name;
    }

};

//  71. 묵시적 형변환 (1)
void lec71() {

  title_header( "71. 묵시적 형변환 (1)" );

  Item i1 = Item(1);
  Item i2(2);
  Item i3 = 3;

  //  명시적 형변환
  //  int 를 Item 으로 형변환. 변환 생성자 호출
  Item i4 = ( Item ) 4;

  //  묵시적 형변환
  //  33 을 담은 임시객체가 생성되고, i3 에 대입된 후 임시객체는 사라짐.
  //  이동대입연산자. VS 에서는 '=' 기호가 녹색으로 표시 됨
  i3 = 33;

  Item i5(5);
  i5 = string( "stone" );
  i5 = ( string ) "stone5";

  Item i6( 6, "glass" );

  Item i7 = { 7, "dirt" };
  i7 = { 77, "dirt7" };

  Item i8{ 8, "wood" };

  i1.print();
  i2.print();
  i3.print();
  i4.print();
  i5.print();
  i6.print();
  i7.print();
  i8.print();
}

/*
lec71() 실행결과: 

Item( int ) : 1                   <=  Item i1 = Item(1);
Item( int ) : 2                   <=  Item i2(2);
Item( int ) : 3                   <=  Item i3 = 3;
Item( int ) : 4                   <=  Item i4 = ( Item ) 4;
Item( int ) : 33                  <=  i3 = 33;
Item( int ) : 5                   <=  Item i5(5);
Item( string ) : stone            <=  i5 = string( "stone" );
Item( string ) : stone5           <=  i5 = ( string ) "stone5";
Item( int, string ) : 6 / glass   <=  Item i6( 6, "glass" );
Item( int, string ) : 7 / dirt    <=  Item i7 = { 7, "dirt" };
Item( int, string ) : 77 / dirt7  <=  i7 = { 77, "dirt7" };
Item( int, string ) : 8 / wood    <=  Item i8{ 8, "wood" };
1 :           <=  
2 :           <=  
33 :          <=  
4 :           <=  
0 : stone5    <=  i5 = string( "stone" ); 실행시 새로운 객체 생성. num 이 없음
6 : glass     <=  
77 : dirt7    <=  
8 : wood      <=  
*/

void println( string s ) {
  cout << s << endl;
}

void println( int n ) {
  cout << n << endl;
}

//  72. 묵시적 형변환 (2)
void lec72() {

  title_header( "72. 묵시적 형변환 (2)" );

  Item i7 = { 7, "dirt" };
  Item i8{ 8, "wood" };

  int itemNum1 = ( int ) i8;  //  명시적 형변환
  int itemNum2 = i7;          //  묵시적 형변환

  cout << itemNum1 << endl;
  cout << itemNum2 << endl;

  println( ( string ) i8 );   //  명시적 형변환

  //  println() 을 오버로딩 했음으로, 어떤 타입으로 형변환이 일어날지 알수 없음...
  //  형변환 연산자 오버로딩시 explicit 를 추가 해서 처리한 예제...
  println( i7 );              //  묵시적 형변환
  // println( ( int    ) i7 );
  println( ( string ) i7 );   //  string 형변환은 명시적(explicit)으로 하도록 수정
  
}