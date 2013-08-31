/**
 * File     : HelperUtil.h
 * Type     : Internal Interface
 * Comment  : Prototypes of Helper functions used by Offense operations
 */
#ifndef _HELPER_UTIL_H_
#define _HELPER_UTIL_H_

/** Validates owner UID and returns SUCCESS if valid, FAILURE otherwise */
int
validateOwnerUID( char* apOwnerUID );

/** Validates vehicle number and returns SUCCESS if valid, FAILURE otherwise */
int
validateVehicleNum( char* apVehicleNum );

/** Validates license number and returns SUCCESS if valid, FAILURE otherwise */
int
validateLicenseNum( char* apLicenseNum );

/** Reads entire file contents into heap and returns a pointer to it */
char*
readEntireFile( char* apFileName );

/** Checks if an line is emtpy and return TRUE if so, FALSE otherwise */
int
isEmptyLine( char* apLine );

/** Converts the given offense code to offense score that can be subtracted */
int
codeToScore( char* apScore );

char *
strSep(char **stringp, const char *delim);

#endif // _HELPER_UTIL_H_
