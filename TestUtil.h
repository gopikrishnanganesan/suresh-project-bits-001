#ifndef _TEST_UTIL_H_
#define _TEST_UTIL_H_

void success( const char* apTestName,
              const char* apAPIName,
              const char* apMessage );

void failure( const char* apTestName,
              const char* apAPIName,
              const char* apMessage );


#endif // _TEST_UTIL_H_
