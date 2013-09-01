================================================================================

STUDENT INFORMATION:
Name        : Suresh Kumar
ID Number   : 2013HZ11001
Email       : 2013hz11001@wilp.bits-pilani.ac.in
================================================================================

FILES DESCRIPTION:
    Makefile            : Application GNU makefile

    Offense.h           : Top level data structures used by application
    OffenseOps.h        : Operations on the data structures - Prototype
    OffenseOps.c        : Operations on the data structures - Implementation
    OffenseOpsSupport.h : Support Operations - Prototype
    OffenseOpsSupport.c : Support Operations - Implementation
    HelperUtil.h        : Application wide helper functions - Prototype
    HelperUtil.c        : Application helper functions - Implementation
    OffenseConfig.h     : Application wide configuration parameters

    TestPopulateDrivers.c   : Test for populateDrivers API
    TestPopulateVehicles.c  : Test for populateVehicles API
    TestUpdateOffenses.c    : Test for updateOffenses API
    TestRevokeList.c        : Test for markRevokedDrivers API
    TestUtil.h              : Test utility - Prototype
    TestUtil.c              : Test utility - Implementation
================================================================================

COMPILATION / BUILD:

    make
        Generates a target executable `revoke' in the current directory. This is
        the main application binary

    make test
        Generates following testing executables for each API:
        TestPopulateDrivers
        TestPopulateVehicles
        TestRevokeList
        TestUpdateOffenses

    make clean
        Removes all the generated executables and object files
================================================================================

ENVIRONMENT:
    Compiler    : gcc version 4.2.1
                  GNU Make version 3.81
    OS          : Mac OS X version 10.7.5, 64-bit
================================================================================

CODING CONVENTIONS:
    1. camelCase for function names and local variables
    2. CamelCase for file names
    3. `p' prefix for pointer variables
    4. `a' prefix for function arguments
    5. 4-space indentation, no-tabs ( except for Makefile )
    6. Doxygen-style comments
================================================================================

SOURCE CONTROL:
    https://github.com/gopikrishnanganesan/suresh-project-bits-001
================================================================================
