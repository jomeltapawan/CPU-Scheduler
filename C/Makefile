# makefile for scheduling program
#
# make rr - for round-robin scheduling
# make fcfs - for FCFS scheduling
# make sjf - for SJF scheduling
# make priority - for priority scheduling


CC=gcc
CFLAGS=-Wall

clean:
	rm -rf *.o
	rm -rf fcfs
	rm -rf sjf
	rm -rf rr
	rm -rf priority


rr: driver.o list.o CPU.o schedule_rr.o
	g++ $(CFLAGS) -o rr driver.o schedule_rr.o list.o CPU.o

fcfs: driver.o list.o CPU.o schedule_fcfs.o
	g++ $(CFLAGS) -o fcfs driver.o schedule_fcfs.o list.o CPU.o

priority: driver.o list.o CPU.o schedule_priority.o
	g++ $(CFLAGS) -o priority driver.o schedule_priority.o list.o CPU.o

schedule_fcfs.o: schedule_fcfs.cpp
	g++ $(CFLAGS) -c schedule_fcfs.cpp

driver.o: driver.c
	$(CC) $(CFLAGS) -c driver.c

schedule_priority.o: schedule_priority.cpp
	g++ $(CFLAGS) -c schedule_priority.cpp

schedule_rr.o: schedule_rr.cpp
	g++ $(CFLAGS) -c schedule_rr.cpp

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

CPU.o: CPU.c cpu.h
	$(CC) $(CFLAGS) -c CPU.c
