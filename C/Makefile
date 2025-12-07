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
	g++ -std=c++11 $(CFLAGS) -o rr driver.o schedule_rr.o list.o CPU.o

fcfs: driver.o list.o CPU.o schedule_fcfs.o
	g++ -std=c++11 $(CFLAGS) -o fcfs driver.o schedule_fcfs.o list.o CPU.o

priority: driver.o list.o CPU.o schedule_priority.o
	g++ -std=c++11 $(CFLAGS) -o priority driver.o schedule_priority.o list.o CPU.o

schedule_fcfs.o: schedule_fcfs.cpp
	g++ -std=c++11 $(CFLAGS) -c schedule_fcfs.cpp

driver.o: driver.c
	gcc $(CFLAGS) -c driver.c

schedule_priority.o: schedule_priority.cpp
	g++ -std=c++11 $(CFLAGS) -c schedule_priority.cpp

schedule_rr.o: schedule_rr.cpp
	g++ -std=c++11 $(CFLAGS) -c schedule_rr.cpp

list.o: list.c list.h
	gcc $(CFLAGS) -c list.c

CPU.o: CPU.c cpu.h
	gcc $(CFLAGS) -c CPU.c
