#ifndef _OFFENSE_H_
#define _OFFENSE_H_

/**
 *
 */
typedef struct Vehicle {
    char            vehicleNum[8];
    char            ownerUID[13];
    struct Vehicle* pNextVehicle;
} Vehicle;

typedef struct Driver {
    char            ownerUID[13];
    char            licenseNum[11];
    int             score;
    struct Driver*  pNextDriver;
} Driver;

typedef struct RevokeList {
    char            ownerUID[13];
    char            licenseNum[11];
    char            vehicleNum[8];
    struct RevokeList*  pNext;
} RevokeList;



#endif // _OFFENSE_H_
