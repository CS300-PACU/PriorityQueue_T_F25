#############################################################################
# File name:  Makefile
# Author:     
# Date:       Sept 1, 2021
# Class:      CS360
# Assignment: 
# Purpose:    
#############################################################################


ENSCRIPT_FLAGS=-C -T 2 -p - -M Letter -Ecpp --color -fCourier8
VALGRIND_FLAGS=-v --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all 

compiler=clang-16
# clang
# https://clang.llvm.org/cxx_status.html
# clang 16 still uses c++2b to represent c++23

CFLAGS=-fstandalone-debug -g -Wall


TARGETS=bin bin/scheduler
VALGRIND_FLAGS=-v --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all


all: ${TARGETS}

# DO NOT ALTER ANY CODE ABOVE THIS POINT EXCEPT THE COMMENT

# look at Makefile in your STACK assignment
# for a guide.

# Format:
# TARGET: DEPENDENCIES
# <TAB>COMMAND

# TODO: Fill in the dependencies and rule here
bin/pqueue.o:


# TODO: Fill in the dependencies and rule here
bin/scheduler.o:

# TODO: Fill in the dependencies and rule here
bin/scheduler:


# TODO: Fill in the dependencies and rule here
# use the STACK makefile as a guide
# Your PDF must be in this order:
# pqueue.c
# scheduler.c
# UnitTests.cpp
# Makefile
printAll:




# You DO NOT need to edit any of the following lines

valgrindScheduler: bin/scheduler
	valgrind ${VALGRIND_FLAGS} bin/scheduler

clean:
	rm -rf ${TARGETS} bin/*.o bin/*.pdf ./build

# build unit tests

build: CMakeLists.txt test/CMakeLists.txt
	cmake -S . -B ./build;
	cmake --build build --target clean;

build/test/TestsToRun: build test/UnitTests.cpp src/pqueue.c include/pqueue.h
	cmake --build build;

runUnittest: build/test/TestsToRun
	build/test/TestsToRun

valgrindUnittests: build/test/TestsToRun
	bash -c 'time valgrind ${VALGRIND_FLAGS} build/test/TestsToRun'

