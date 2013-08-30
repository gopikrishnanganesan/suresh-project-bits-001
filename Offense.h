#ifndef _OFFENSE_H_
#define _OFFENSE_H_


#define VEHICLE_NUM_SZ  7   /** Vehicle Number is 7 characters long */
#define OWNER_UID_SZ    12  /** Owner UID is 12 characters long */
#define LICENSE_NUM_SZ  10  /** License Number is 10 characters long */


/**
 *
 */
typedef struct Vehicle {
    char            vehicleNum[VEHICLE_NUM_SZ+1];
    char            ownerUID[OWNER_UID_SZ+1];
    struct Vehicle* pNext;
} Vehicle;

typedef struct Driver {
    char            ownerUID[OWNER_UID_SZ+1];
    char            licenseNum[LICENSE_NUM_SZ+1];
    int             score;
    struct Driver*  pNext;
} Driver;

typedef struct RevokeList {
    char            ownerUID[OWNER_UID_SZ+1];
    char            licenseNum[LICENSE_NUM_SZ+1];
    char            vehicleNum[VEHICLE_NUM_SZ+1];
    struct RevokeList*  pNext;
} RevokeList;



#endif // _OFFENSE_H_
