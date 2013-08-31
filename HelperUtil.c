/**
 * File     : HelperUtil.c
 * Type     : Internal Implementation
 * Comment  : Helper functions used by Offense operations
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "HelperUtil.h"
#include "OffenseConfig.h"

int validateOwnerUID( char* apOwnerUID ) {
    if ( strcmp( apOwnerUID, "" ) != 0 && strlen( apOwnerUID ) == 12 ) {
        return SUCCESS;
    } else {
        return FAILURE;
    }
}

int validateVehicleNum( char* apVehicleNum ) {
    if ( strcmp( apVehicleNum, "" ) != 0 && strlen( apVehicleNum ) == 7 ) {
        return SUCCESS;
    } else {
        return FAILURE;
    }
}

int validateLicenseNum( char* apLicenseNum ) {
    if ( strcmp( apLicenseNum, "" ) != 0 && strlen( apLicenseNum ) == 10 ) {
        return SUCCESS;
    } else {
        return FAILURE;
    }
}

char* readEntireFile( char* apFileName ) {
    FILE*           pFile       = NULL;
    unsigned long   fileSize    = 0;
    char*           pFileBuff   = NULL;

    pFile = fopen( apFileName, "r" );
    if ( pFile == NULL ) {
        perror( "Error while opening file" );
        return NULL;
    }

    fseek( pFile, 0, SEEK_END );
    fileSize = ftell( pFile );
    fseek( pFile, 0, SEEK_SET );

    pFileBuff = ( char* ) malloc ( fileSize );
    if ( pFileBuff == NULL ) {
        perror( "Unable to allocate enough memory to read the file" );
        return NULL;
    }

    memset( pFileBuff, '\0', fileSize );
    fread( pFileBuff, 1, fileSize, pFile );
    fclose( pFile );

    return pFileBuff;
}

int isEmptyLine( char* apLine ) {
    if ( strcmp( apLine, "" ) == 0 ) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int codeToScore( char* apScore ) {
    if ( strcmp( apScore, "1") == 0 ) {
        return -5;
    } else if ( strcmp( apScore, "0" ) == 0 ) {
        return -1;
    } else {
        return 0;
    }
}

/**
 *******************************************************************************
 * Some versions of glibc doesn't have strsep implementation. Instead of using
 * the "fearsome strtok", I'm copying an implementation of strsep from github:
 * https://github.com/yasm/yasm/blob/master/libyasm/strsep.c
 *******************************************************************************
 */
char *
strSep(char **stringp, const char *delim)
{
    register char *s;
    register const char *spanp;
    register int c, sc;
    char *tok;

    if ((s = *stringp) == NULL)
            return (NULL);
    for (tok = s;;) {
            c = *s++;
            spanp = delim;
            do {
                    if ((sc = *spanp++) == c) {
                            if (c == 0)
                                    s = NULL;
                            else
                                    s[-1] = 0;
                            *stringp = s;
                            return (tok);
                    }
            } while (sc != 0);
    }
}
