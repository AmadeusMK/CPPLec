#include "lec79.h"

using namespace std;  //  std:: 생략가능

/*

*/

class Message {

  public:

    Message( int sendTime, string sendName ) {
      this->sendTime = sendTime;
      this->sendName = sendName;
    }

    int    GetSendTime() const { return sendTime; }
    string GetSendName() const { return sendName; }

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

  private:
    Image  *image;
};

//  79. 상속이 필요한 이유 (1)
void lec79() {

  title_header( "79. 상속이 필요한 이유 (1)" );

  //  ex)
  //  두들 : 안녕~?
  //  두들 : [강아지 사진]

  Image *p_dogImage = new Image( "강아지", "강아지사진경로" );

  TextMessage *hello = new TextMessage( 10, "두들", "안녕~?" );
  ImageMessage *dog  = new ImageMessage( 20, "두들", p_dogImage );

  cout << "보낸 시간 : " << hello->GetSendTime() << endl;
  cout << "보낸 사람 : " << hello->GetSendName() << endl;
  cout << "보낸 내용 : " << hello->GetSendText() << endl;
  cout << endl;

  cout << "보낸 시간 : " << dog->GetSendTime() << endl;
  cout << "보낸 사람 : " << dog->GetSendName() << endl;
  cout << "보낸 내용 : " << ( string ) *dog->GetImage() << endl;
  cout << endl;

  //  메모리 해제
  delete hello;
  delete dog;
  delete p_dogImage;

}