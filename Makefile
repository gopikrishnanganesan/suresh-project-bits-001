CC=gcc
CFLAGS=-Wall -O2
COMMON=OffenseOps.o HelperUtil.o OffenseOpsSupport.o
TESTOBJ=TestPopulateVehicles.o TestPopulateDrivers.o TestUpdateOffenses.o

test : TestPopulateVehicles TestPopulateDrivers TestUpdateOffenses

TestPopulateVehicles: TestPopulateVehicles.o $(COMMON)
	$(CC) -o $@ $^

TestPopulateDrivers: TestPopulateDrivers.o $(COMMON)
	$(CC) -o $@ $^

TestUpdateOffenses: TestUpdateOffenses.o $(COMMON)
	$(CC) -o $@ $^

OffenseOps.o : OffenseOps.c

OffenseOpsSupport.o : OffenseOpsSupport.c

HelperUtil.o : HelperUtil.c

TestPopulateVehicles.o : TestPopulateVehicles.c

TestPopulateDrivers.o : TestPopulateDrivers.c

TestUpdateOffenses.o : TestUpdateOffenses.c




clean:
	rm -f *o TestPopulateVehicles TestPopulateDrivers TestUpdateOffenses
