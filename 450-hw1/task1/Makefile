CC=g++
CFLAGS= -std=c++11 -g -O3
OUT= vt-benchmark
RUN_TEST_JOB= run-benchmarks.py
LOGFILE= bmarks-vt

all: $(OUT)
	
dbg: $(OUT)
	gdb ./$(OUT)

$(OUT): vector-triad.cpp
	$(CC) $(CFLAGS) -o $(OUT) vector-triad.cpp
	./$(RUN_TEST_JOB) $(OUT) > $(LOGFILE).log

clean: 
	rm -rf $(OUT) *.dSYM
