#include "ex77.h"

using namespace std;  //  std:: 생략가능

/*
*/

//  77. 9부 종합문제 2
void ex77() {

  title_header( "77. 9부 종합문제 2" );

  ex77_1();
}

//  class 로 만들수 있지만, 쓸데 없이 길어짐.
struct Point {
  int x, y;
};

class Polygon {

  private:
    int nPoints;
    Point *points;

  public:
    Polygon() {
      cout << "Polygon() : " << this << endl;
      nPoints = 0;
      points  = NULL;
    }

    Polygon( const int nPoints, const Point *points ) : nPoints( nPoints ) {
      cout << "Polygon( int , Point* ) : " << this << endl;
      this->points = new Point[nPoints];
      for ( int i = 0 ; i < nPoints ; i++ ) {
        this->points[i] = points[i];
      }
    }

    //  복사 생성자 구현
    Polygon( const Polygon &rhs ) {

      cout << "Polygon( Polygon& ) : " << this << endl;

      nPoints = rhs.nPoints;

      //  깊은 복사
      points = new Point[nPoints];
      for ( int i = 0 ; i < nPoints ; i++ ) {
        points[i] = rhs.points[i];  //  Point 의 각 요소는 int 형임으로, 깊은 복사가 일어남...
      }

      cout << "깊은 복사" << endl;
    }

    //  이동 생성자 구현
    Polygon( Polygon &&rhs ) {

      cout << "Polygon( Polygon&& ) : " << this << endl;

      nPoints = rhs.nPoints;

      //  얕은 복사
      points  = rhs.points;

      cout << "얕은 복사" << endl;
    }

    ~Polygon() {
      cout << "~Polygon : " << this << endl;
      delete[] points;
    }

    // void 

    //  복사 대입 연산자 구현
    Polygon &operator=( const Polygon &rhs ) {

      cout << "Polygon &operator=( Polygon& ) : " << this << endl;

      if ( this != &rhs ) { //  자기 자신이 아닐경우에만 실행...

        nPoints = rhs.nPoints;

        delete[] points;

        //  깊은 복사
        points = new Point[nPoints];
        for ( int i = 0 ; i < nPoints ; i++ ) {
          points[i] = rhs.points[i];  //  Point 의 각 요소는 int 형임으로, 깊은 복사가 일어남...
        }
      }

      cout << "깊은 복사" << endl;

      return *this;
    }

    //  이동 대입 연산자 구현
    Polygon &operator=( Polygon &&rhs ) {

      cout << "Polygon &operator=( Polygon&& ) : " << this << endl;

      if ( this != &rhs ) { //  자기 자신이 아닐경우에만 실행...

        nPoints = rhs.nPoints;

        delete[] points;

        //  얕은 복사
        points = rhs.points;

        rhs.points = NULL;
      }

      cout << "얕은 복사" << endl;

      return *this;
    }

    int GetNPoints() const {
      return nPoints;
    }

    Point *GetPoints() const {
      if ( nPoints == 0 ) return NULL;
      return points;
    }
};

Polygon getSquare() {
  Point points[4] ={ {0,0}, {1,0}, {1,1}, {0,1} };
  Polygon p( 4, points );
  return p;
}

void ex77_1() {

  Polygon a;
  a = getSquare();  //  얕은 객체 복사 2회

  //  Polygon b(a);
  Polygon b = a;    //  깊은 객체 복사 1회

  Polygon c;
  c = a;            //  깊은 객체 복사 1회

  int nPoints = c.GetNPoints();
  Point *points = c.GetPoints();
  for ( int i = 0 ; i < nPoints ; i++ ) {
    cout <<  "(" << points[i].x << "," << points[i].y << ")" << endl;
  }

}

/*
실행결과:

Polygon() : 0x7ffd505c61d0
Polygon( int , Point* ) : 0x7ffd505c61c0
Polygon &operator=( Polygon&& ) : 0x7ffd505c61d0
얕은 복사
~Polygon : 0x7ffd505c61c0
Polygon( Polygon& ) : 0x7ffd505c61a0
깊은 복사
Polygon() : 0x7ffd505c6190
Polygon &operator=( Polygon& ) : 0x7ffd505c6190
깊은 복사
(0,0)
(1,0)
(1,1)
(0,1)
~Polygon : 0x7ffd505c6190
~Polygon : 0x7ffd505c61a0
~Polygon : 0x7ffd505c61d0
*/