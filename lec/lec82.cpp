#include "lec82.h"

using namespace std;  //  std:: 생략가능

/*
  lec79.cpp 복사...
*/

//  82. 상속이 필요한 이유 (2)
void lec82() {

  title_header( "82. 상속이 필요한 이유 (2)" );

  lec82_1();

  lec82_2();
}

class Message {

  public:

    Message( int sendTime, string sendName ) {
      this->sendTime = sendTime;
      this->sendName = sendName;
    }

    int    GetSendTime() const { return sendTime; }
    string GetSendName() const { return sendName; }

    //  가상함수(virtual) 추가
    //  자체로는 풀력할 내용이 없음으로, 공백("") 리턴
    virtual string GetContent() const { return ""; }

  private:
    int    sendTime;
    string sendName;
};

class TextMessage : public Message {

  public:

    TextMessage( int sendTime, string sendName, string sendText ) 
      : Message( sendTime, sendName ) {
      this->sendText = sendText;
    }

    string GetSendText() const { return sendText; }

    //  가상함수(virtual) 오버라이딩
    string GetContent() const { return sendText; }

  private:
    string sendText;
};

class Image {

  public:

    Image( string imgName, string imgPath ) {
      this->imgName = imgName;
      this->imgPath = imgPath;
    }

    operator string() {
      return imgName + ":" + imgPath;
    }

  private:
    string imgName;
    string imgPath;
};

class ImageMessage : public Message {

  public:

    ImageMessage( int sendTime, string sendName, Image *image ) 
      : Message( sendTime, sendName ) {
      this->image    = image;
    }

    Image  *GetImage()   const { return image;    }

    //  가상함수(virtual) 오버라이딩
    string GetContent() const {
      return ( string ) *image;
    }

  private:
    Image  *image;
};

// void PrintMessage( TextMessage *m ) {
//   cout << "보낸 시간 : " << m->GetSendTime() << endl;
//   cout << "보낸 사람 : " << m->GetSendName() << endl;
//   cout << "보낸 내용 : " << m->GetContent() << endl;
//   cout << endl;
// }

// void PrintMessage( ImageMessage *m ) {
//   cout << "보낸 시간 : " << m->GetSendTime() << endl;
//   cout << "보낸 사람 : " << m->GetSendName() << endl;
//   cout << "보낸 내용 : " << ( string ) *m->GetImage() << endl;
//   cout << endl;
// }

//  가상함수를 정의해서 함수 하나로 처리...
void PrintMessage( Message *m ) {
  cout << "보낸 시간 : " << m->GetSendTime() << endl;
  cout << "보낸 사람 : " << m->GetSendName() << endl;
  cout << "보낸 내용 : " << m->GetContent() << endl;
  cout << endl;
}

//  레퍼런스 변수로 받음...
void PrintMessage( const Message &m ) {
  cout << "보낸 시간 : " << m.GetSendTime() << endl;
  cout << "보낸 사람 : " << m.GetSendName() << endl;
  cout << "보낸 내용 : " << m.GetContent() << endl;
  cout << endl;
}

void lec82_1() {

  title_header( "가상 함수 추가" );

  //  ex)
  //  두들 : 안녕~?
  //  두들 : [강아지 사진]

  Image *p_dogImage = new Image( "강아지", "강아지사진경로" );

  TextMessage *hello = new TextMessage( 10, "두들", "안녕~?" );
  ImageMessage *dog  = new ImageMessage( 20, "두들", p_dogImage );

  title_header( "함수 하나로 호출 처리..." );

  PrintMessage( hello );
  PrintMessage( dog );

  title_header( "레퍼런스 변수를 파라미터로 받음" );

  PrintMessage( *hello );
  PrintMessage( *dog );

  //  메모리 해제
  delete hello;
  delete dog;
  delete p_dogImage;
}

void lec82_2() {

  title_header( "포인터배열" );

  Message *messages[] = {
    new TextMessage( 10, "두들", "안녕~?" ),
    new ImageMessage( 20, "두들", new Image( "강아지", "강아지사진경로" ) )
  };

  for ( Message *m : messages ) {
    PrintMessage( *m );
  }

  // delete[] *messages;   //  Segmentation fault (core dumped) 에러나는데...
}