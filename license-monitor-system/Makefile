CC=gcc
CFLAGS=-W -Wall -O2
COMMON=OffenseOps.o HelperUtil.o OffenseOpsSupport.o TestUtil.o
TESTOBJ=TestPopulateVehicles.o TestPopulateDrivers.o TestUpdateOffenses.o TestRevokeList.o

all : revoke

test : TestPopulateVehicles TestPopulateDrivers TestUpdateOffenses TestRevokeList

revoke : revoke.o $(COMMON)

TestPopulateVehicles: TestPopulateVehicles.o $(COMMON)
	$(CC) -o $@ $^

TestPopulateDrivers: TestPopulateDrivers.o $(COMMON)
	$(CC) -o $@ $^

TestUpdateOffenses: TestUpdateOffenses.o $(COMMON)
	$(CC) -o $@ $^

TestRevokeList: TestRevokeList.o $(COMMON)
	$(CC) -o $@ $^


OffenseOps.o : OffenseOps.c

OffenseOpsSupport.o : OffenseOpsSupport.c

HelperUtil.o : HelperUtil.c

TestPopulateVehicles.o : TestPopulateVehicles.c

TestPopulateDrivers.o : TestPopulateDrivers.c

TestUpdateOffenses.o : TestUpdateOffenses.c

TestUtil.o : TestUtil.c

revoke.o : revoke.c

clean:
	rm -f *o TestPopulateVehicles TestPopulateDrivers TestUpdateOffenses TestRevokeList revoke
