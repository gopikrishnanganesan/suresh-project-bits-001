#ifndef _HELPER_UTIL_H_
#define _HELPER_UTIL_H_

int validateOwnerUID( char* apOwnerUID );

int validateVehicleNum( char* apVehicleNum );

int validateLicenseNum( char* apLicenseNum );

char* readEntireFile( char* apFileName );

int isEmptyLine( char* apLine );

int codeToScore( char* apScore );


#endif // _HELPER_UTIL_H_
