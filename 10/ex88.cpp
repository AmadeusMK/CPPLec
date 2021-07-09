#include "ex88.h"

using namespace std;  //  std:: 생략가능

//  88. 10부 종합문제 2 (상속)
void ex88() {

  title_header( "88. 10부 종합문제 2 (상속)" );

  //  상속과 가상 함수를 사용해 중복되는 코드를 줄임
  ex88_1();

  ex88_2();

  // ex88_3();
}

/*  --------------------------------------------------------------------------------  */

enum LogLevels{
  DEBUG,      //  0
  INFO,       //  1
  WARNING,    //  2
  ERROR,      //  3
  FATAL       //  4
};

const char* const LEVEL_HEADINGS[] = {
  "DEBUG",
  "INFO",
  "WARNING",
  "ERROR",
  "FATAL"
};

class Logger {

  protected:
    int minLevel;

    virtual void DoLogJob( const string &s, int level ) = 0;
    // string LogMessage( const string &s, const int level ) {
    //   if ( level >= minLevel ) {
    //     return "[" + LEVEL_HEADINGS[level] + "] " + s.c_str() + "\n";
    //   }
    // }

  public:

    Logger( int minLevel ) : minLevel( minLevel ) {}
    virtual ~Logger() {}

    void Log( const string &s, const int level ) {
      if ( level >= minLevel ) {
        DoLogJob( s, level );
      }
    }

    int GetMinLevel() const { return minLevel; }

};

class FileLogger : public Logger {

  private:
    // int minLevel;
    FILE *logFile;

  public:

    //  생성자에서 minLevel 은 부모클래스 생성자 호출해서 설정
    // FileLogger( const int minLevel, const string &fileName ) : minLevel( minLevel ) {
    //   logFile = fopen( fileName.c_str(), "a" );
    // }
    FileLogger( const int minLevel, const string &fileName ) : Logger( minLevel ) {
      logFile = fopen( fileName.c_str(), "a" );
    }

    ~FileLogger() {
      fclose( logFile );
    }

    //  level 에 따른 판단은 부모 클래스의 Log 로 올리고
    //  실제 로그를 출력하는 DoLogJob() 함수를 오버라이딩 함
    // void Log( const string &s, const int level ) {
    //   if ( level >= minLevel ) {
    //     fprintf( logFile, "[%s] %s\n", LEVEL_HEADINGS[level], s.c_str() );
    //   }
    // }

  protected:
    void DoLogJob( const string &s, const int level ) {
      fprintf( logFile, "[%s] %s\n", LEVEL_HEADINGS[level], s.c_str() );
    }

    //  Logger 로 이동
    // int GetMinLevel() const { return minLevel; }
};

class ConsoleLogger : public Logger {

  // private:
  //   int minLevel;

  public:

    //  생성자에서 minLevel 은 부모클래스 생성자 호출해서 설정
    // ConsoleLogger( const int minLevel ) : minLevel( minLevel ) {}
    ConsoleLogger( const int minLevel ) : Logger( minLevel ) {}

    //  level 에 따른 판단은 부모 클래스의 Log 로 올리고
    //  실제 로그를 출력하는 DoLogJob() 함수를 오버라이딩 함
    // void Log( const string &s, const int level ) {
    //   if ( level >= minLevel ) {
    //     printf( "[%s] %s\n", LEVEL_HEADINGS[level], s.c_str() );
    //   }
    // }

  protected:
    void DoLogJob( const string &s, const int level ) {
      printf( "[%s] %s\n", LEVEL_HEADINGS[level], s.c_str() );
    }

    //  Logger 로 이동
    // int GetMinLevel() const { return minLevel; }
};

void ex88_1() {

  title_header( "상속과 가상 함수를 사용해 중복되는 코드를 줄임" );

  ConsoleLogger c( LogLevels::WARNING );
  c.Log( "abc", LogLevels::ERROR   );
  c.Log( "def", LogLevels::INFO    );
  c.Log( "ghi", LogLevels::WARNING );

  // FileLogger f( LogLevels::DEBUG, "ex88.log.txt" );
  Logger *f = new FileLogger( LogLevels::DEBUG, "ex88.log.txt" );
  f->Log( "abc", LogLevels::ERROR   );
  f->Log( "def", LogLevels::INFO    );
  f->Log( "ghi", LogLevels::WARNING );
}

/*  --------------------------------------------------------------------------------  */
/*  --------------------------------------------------------------------------------  */

void testLogger( Logger &logger ) {

  logger.Log( "abc", LogLevels::ERROR   );
  logger.Log( "def", LogLevels::INFO    );
  logger.Log( "ghi", LogLevels::WARNING );

}

void testLogger( Logger *logger ) {

  logger->Log( "abc", LogLevels::ERROR   );
  logger->Log( "def", LogLevels::INFO    );
  logger->Log( "ghi", LogLevels::WARNING );

}

void ex88_2() {

  title_header( "로그를 출력하는 공통 함수 사용" );

  ConsoleLogger c( LogLevels::WARNING );
  testLogger( c );

  // FileLogger f( LogLevels::DEBUG, "ex88.log.txt" );
  Logger *f = new FileLogger( LogLevels::DEBUG, "ex88.log.txt" );
  testLogger( f );

}

/*  --------------------------------------------------------------------------------  */
/*  --------------------------------------------------------------------------------  */

// void ex88_3() {

//   title_header( "" );


// }

/*  --------------------------------------------------------------------------------  */
