
#ifndef _OFFENSE_OPS_SUPPORT_H_
#define _OFFENSE_OPS_SUPPORT_H_

Vehicle*
createVehicle( char*    apOwnerUID,
               char*    apVehicleNum );

Vehicle*
insertVehicle( Vehicle* apVehicles,
               char*    apOwnerUID,
               char*    apVehicleNum );

Driver*
insertDriver( Driver*   apDrivers,
              char*     apOwnerUID,
              char*     apLicenseNum );

Driver*
createDriver( char*     apOwnerUID,
              char*     apLicenseNum );

char*
lookupUID( char*    apVehicleNum,
           Vehicle* apVehicles );

char*
lookupVehicle( char*    apOwnerUID,
               Vehicle* apVehicles );

int
updateOffense( char*    apOwnerUID,
               Driver*  apDrivers,
               int      aOffenseScore );

RevokeList*
insertRevoked( RevokeList*  apRevokeList,
               Driver*      apDriver,
               Vehicle*     apVehicles );

RevokeList*
createRevoked( Driver*      apDriver,
               Vehicle*     apVehicles );

#endif // _OFFENSE_OPS_SUPPORT_H_