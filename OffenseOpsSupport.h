/**
 * File     : OffenseOpsSupport.h
 * Type     : Internal Interface
 * Comment  : Prototype declarations for the supporting functions used by
 *            Offense operations
 */
#ifndef _OFFENSE_OPS_SUPPORT_H_
#define _OFFENSE_OPS_SUPPORT_H_

/**
 * @brief create a vehicle structure in heap
 *
 * @param[in] apOwnerUID owner UID, 12 characters long
 * @param[in] apVehicleNum vehicle number, 7 characters long
 *
 * @return
 *      Handle to created Vehicle structure on success
 *      NULL on out-of-memory/error/failure
 */
Vehicle*
createVehicle( char*    apOwnerUID,
               char*    apVehicleNum );

/**
 * @brief creates and inserts a Vehicle into the existing Vehicle list
 *
 * @param[in] apVehicles pointer to existing Vehicle list
 * @param[in] apOwnerUID owner UID, 12 characters long
 * @param[in] apVehicleNum vehicle number, 7 characters long
 *
 * @return
 *      Handle to the updated Vehicle structure
 */
Vehicle*
insertVehicle( Vehicle* apVehicles,
               char*    apOwnerUID,
               char*    apVehicleNum );

/**
 * @brief creates and inserts a Driver into the existing Driver list
 *
 * @param[in] apDrivers pointer to existing Driver list
 * @param[in] apOwnerUID owner UID, 12 characters long
 * @param[in] apLicenseNum license number, 10 characters long
 *
 * @return
 *      Handle to the updated Driver structure
 */
Driver*
insertDriver( Driver*   apDrivers,
              char*     apOwnerUID,
              char*     apLicenseNum );

/**
 * @brief create a driver structure in heap
 *
 * @param[in] apOwnerUID owner UID, 12 characters long
 * @param[in] apLicenseNum license number, 10 characters long
 *
 * @return
 *      Handle to created Vehicle structure on success
 *      NULL on out-of-memory/error/failure
 */
Driver*
createDriver( char*     apOwnerUID,
              char*     apLicenseNum );

/**
 * @brief lookup the owner UID that has the given vehicle number
 *
 * @param[in] apVehicleNum vehicle number, 7 characters long
 * @param[in] apVehicles pointer to existing Vehicle list
 *
 * @return
 *      owner UID if the entry exists in Vehicle list
 *      NULL if the entry doesn't exist
 */
char*
lookupUID( char*    apVehicleNum,
           Vehicle* apVehicles );

/**
 * @brief lookup the Vehicle owned by a owner UID
 *
 * @param[in] apOwnerUID owner UID, 12 characters long
 * @param[in] apVehicles pointer to existing Vehicle list
 *
 * @return
 *      owner UID if the entry exists in Vehicle list
 *      NULL if the entry doesn't exist
 */
char*
lookupVehicle( char*    apOwnerUID,
               Vehicle* apVehicles );

/**
 * @brief Updates a single offense against a driver in the drivers list
 *
 * @param[in] apOwnerUID owner UID, 12 characters long
 * @param[in] apDrivers pointer to existing Driver list
 * @param[in] aOffenseScore score of offense to be subtracted from the driver
 *            score
 *
 * return
 *      SUCCESS in case updation was success
 *      FAILURE in case if match was not found to update
 */
int
updateOffense( char*    apOwnerUID,
               Driver*  apDrivers,
               int      aOffenseScore );

/**
 * @brief creates and inserts a RevokeList entry into the existing RevokeList
 *
 * @param[in] apRevokeList pointer to existing revoked list
 * @param[in] apDriver the driver to be added to the revoked list
 * @param[in] apVehicles the vehicles structure to search for vehicles
 *            associated with the driver
 *
 * @return
 *      Handle to the updated RevokeList structure
 */
RevokeList*
insertRevoked( RevokeList*  apRevokeList,
               Driver*      apDriver,
               Vehicle*     apVehicles );

/**
 * @brief creates a RevokeList entry in the heap
 *
 * @param[in] apDriver the driver to be added to the revoked list
 * @param[in] apVehicles the vehicles structure to search for vehicles
 *            associated with the driver
 *
 * @return
 *      Handle to the updated Driver structure
 *      NULL on out-of-memory/error/failure
 */
RevokeList*
createRevoked( Driver*      apDriver,
               Vehicle*     apVehicles );

#endif // _OFFENSE_OPS_SUPPORT_H_
