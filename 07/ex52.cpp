#include "ex52.h"

//  52. 종합문제
void ex52() {

  title_header( "52. 종합문제" );

  // ex52_1();
  ex52_2();
}

/*
  1. 이름과 점수를 입력 받고, 다음과 같이 출력

  이름 입력 : 양재웅
  점수 입력 : 80
  양재웅님의 점수는 80점입니다.
*/
void ex52_1() {

  string name;
  string score;

  cout << "이름 입력 : ";
  cin >> name;

  cout << "점수 입력 : ";
  cin >> score;

  cout << name << "님의 점수는 " << score << "점입니다." << endl;
}

/*
  2. 범위 기반 for 문을 사용하여 이차원 배열 출력
*/
void ex52_2() {

  int arr[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };

  // //  27강 참고...
  // for ( int ( *row )[3] = arr ; row < arr + 2 ; row++ ) {
  //   for ( int *col = *row ; col < *row + 3 ; col++ ) {
  //     cout << *col << " ";
  //   }
  //   cout << endl;
  // }

  // for ( int ( &rows )[3] : arr ) {
  //   for ( int &cols : rows ) {
  //     cout << cols << " ";
  //   }
  //   cout << endl;
  // }

  //  auto 
  for ( auto &rows : arr ) {      //  레퍼런스 변수 사용
    for ( int &cols : rows ) {    //  레퍼런스 변수 사용. 이부분은 cols 로 사용해도 됨
    // for ( int cols : rows ) {     //  cols 도 가능
      cout << cols << " ";
    }
    cout << endl;
  }

}