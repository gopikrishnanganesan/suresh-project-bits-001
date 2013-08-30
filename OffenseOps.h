/**
 * File     : OffenseOps.h
 * Type     : Interface
 * Comment  : Documentation and API prototypes for Offense Operations
 */
#ifndef _OFFENSE_OPS_H_
#define _OFFENSE_OPS_H_

/**
 * @brief Read vehicle information from file
 * Reads vehicle and owner information from text file supplied and constructs
 * the Vehicle data structure. The data structure is constructed on heap and
 * needs to be freed finally using freeVehicleList function.
 *
 * @param [in] apOwnersFile the relative/absolute file path to the text file
 *              that holds owner and vehicle information. If passed NULL, this
 *              internally defaults to "owners.txt". The file should have
 *              contents in the following format:
 *
 *              931259462468,MAN2940
 *              796407789026,ELI6177
 *              896681219516,ABC4407
 *              ...
 *
 *              Each line must have 12 character owner UID followed by a comma
 *              and then by a 7 character vehicle number. Lines that doesn't
 *              conform to the above specification are dropped while building
 *              the list
 * @return
 *      Handle to Vehicle data structure
 *      NULL in case of any error
 */
Vehicle*
populateVehicles( char* apOwnersFile );

/**
 * @brief Read driver information from file
 * Reads driver and license information from the text file supplied and builds
 * the Driver data structure. Allocates an initial score of 10 to each
 * driver when constructing the list.
 *
 * @param [in] apDriversFile the relative/absolute path to text file that holds
 *              driver and license information. If passed NULL,m this internally
 *              defaults to "drivers.txt". The contents in file should be of the
 *              format specified below:
 *
 *              931259462468,4431891729
 *              796407789026,9294384006
 *              896681219516,3067841797
 *              ...
 *
 *              Each line must have 12 character owner UID and 10 character
 *              license number separated by a comma. Lines that doesn't conform
 *              to above specification will be dropped while building the list
 *
 * @return
 *      Handle to Driver data structure on success
 *      NULL in case of any error/failure
 */
Driver*
populateDrivers( char*  apDriversFile );

/**
 * @brief Reads the offenses file and adjusts the score in the drivers list
 * Reads the offenses supplied in the text file and decrease the score of
 * a driver associated with the vehicle for minor and major offenses accordingly
 *
 * @param [in] apOffensesFile the relative/absolute path to the text file that
 *              holds offenses related data. If passed NULL, this internally
 *              defaults to "offenses.txt". The contents in file should be of
 *              the format mentioned below:
 *
 *              ABC3940 1
 *              LAV7823 0
 *              ELI6667 1
 *              ...
 *
 *              Each line should have 7 character vehicle number and a 1
 *              character offense code separated by a space. Non conforming
 *              lines will be dropped
 * @param[inout] apDrivers pointer to Driver list data structure. This will
 *              be updated according to the offenses commited by the drivers
 * @param[in]   apVehicles pointer to Vehicle list data. This will serve as
 *              a reference map between owner and vehicle
 */
void
updateOffenses( char*   apOffensesFile,
                Driver* apDrivers,
                Vehicle* apVehicles );

/**
 * @brief Retrieves drives whose license need to be revoked
 * Gets the list of all drivers whose score fell below zero. This will filter
 * the Driver list data using Vehicle list data as mapping reference
 *
 * @param[in]   apDrivers pointer to Driver list data
 * @param[in]   apVehicles pointer to Vehicle list data
 *
 * @return
 *      Handle to RevokeList data structure on success
 *      NULL on error/failure
 */
RevokeList*
markRevokedDrivers( Driver*     apDrivers,
                    Vehicle*    apVehicles );

/**
 * @brief Deallocates the memory to the RevokeList data structure allocated by
 * markRevokedDrivers
 *
 * @param[in] apRevoked pointer to RevokeList data structure
 */
void
freeRevokeList( RevokeList* apRevoked );

/**
 * @brief Deallocates the memory to the Driver data structure allocated by
 * populateDrivers
 *
 * @param[in] apDrivers pointer to Driver data structure
 */
void
freeDriverList( Driver* apDrivers );

/**
 * @brief Deallocates the memory to the Vehicle data structure allocated by
 * populateVehicles
 *
 * @param[in] apVehicles pointer to Vehicle data structure
 */
void
freeVehicleList( Vehicle* apVehicles );

#endif // _OFFENSE_OPS_H_
