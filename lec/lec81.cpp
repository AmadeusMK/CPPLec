#include "lec81.h"

using namespace std;  //  std:: 생략가능

class Weapon {

  protected:
    int power;

  public:
    Weapon( int power ) : power( power ) {
      cout << "Weapon(int)" << endl;
    }

    //  가상함수 ( virtual )
    //  호출이될수도 있고, 안될수도 있음...
    //  컴파일시 결정 하지 않고, 실행시점에서 호출 여부 결정
    virtual void Use() {
      cout << "Weapon::Use()" << endl;
    }
};

class Sword : public Weapon {

  private:
    void Swing() {
      cout << "Swing sword!!!" << endl;
    }

  public:
    Sword( int power ) : Weapon( power ) {
      cout << "Sword(int)" << endl;
    }

    //  가상함수 ( virtual ) 오버라이딩
    void Use() {
      cout << "Sword::Use()" << endl;
      Swing();
    }

};

class Magic : public Weapon {

  private:
    int manaCost;

    void Cast() {
      cout << "Cast magic!!!" << endl;
    }

  public:
    Magic( int power, int manaCost ) : Weapon( power ), manaCost( manaCost ) {
      cout << "Magic( int, int )" << endl;
    }

    //  가상함수 ( virtual ) 오버라이딩
    void Use() {
      cout << "Magic::Use()" << endl;
      Cast();
    }

};

//  81. 가상 함수와 동적 바인딩
void lec81() {

  title_header( "81. 가상 함수와 동적 바인딩" );

  Sword mySword( 10 );
  Magic myMagic( 15, 7 );

  // mySword.Use();
  // myMagic.Use();

  title_header( "가상 함수 (virtual) 호출" );

  Weapon *curruntWeapon;
 
  curruntWeapon = &mySword;

  //  Weapon 의 Use() 호출 => Weapon 의 Use() 에 virtual 붙여줌
  //  실행시점에서 어떤 Use() 를 호출할지 결정
  curruntWeapon->Use();
}