/**
 * File     : OffenseConfig.h
 * Type     : Internal Configuration Entries
 * Comment  : All configurations used by revoke application
 */
#ifndef _OFFENSE_CONFIG_H_
#define _OFFENSE_CONFIG_H_

#define DEFAULT_OWNERS_FILE     "owners.txt"    /** Default owners input file */
#define DEFAULT_DRIVERS_FILE    "drivers.txt"   /** Default drivers input file */
#define DEFAULT_OFFENSES_FILE   "offenses.txt"  /** Default offenses input file */
#define INITIAL_DRIVER_SCORE    10              /** Intial driver score */
#define REVOKE_CUTOFF_SCORE     0               /** Score for license cutoff */

/** C doesn't support boolean, so just wrapping them */
#define SUCCESS     1
#define FAILURE     0
#define TRUE        1
#define FALSE       0


#endif // _OFFENSE_CONFIG_H_
