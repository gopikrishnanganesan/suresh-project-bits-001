/**
 * File     : TestUtil.h
 * Type     : Internal Test Interface
 * Comment  : Prototypes for Helper utilties for test cases status printing :-)
 */
#ifndef _TEST_UTIL_H_
#define _TEST_UTIL_H_

/** Print API passed message */
void success( const char* apTestName,
              const char* apAPIName,
              const char* apMessage );

/** Print API failed message and abort the program */
void failure( const char* apTestName,
              const char* apAPIName,
              const char* apMessage );

#endif // _TEST_UTIL_H_
