CC=g++
CFLAGS= -std=c++11 -g -O3
OUT_BRANCHED= triad-branched
RUN_TEST_JOB= run-benchmarks.py
LOGFILE= bmarks-branched

all: branched-a branched-b branched-c 
 
branched-a: triad-with-branching-a.cpp  
	$(CC) $(CFLAGS) -o $(OUT_BRANCHED)-a triad-with-branching-a.cpp
	./$(RUN_TEST_JOB) $(OUT_BRANCHED)-a > $(LOGFILE)-a.log

branched-b: triad-with-branching-b.cpp  
	$(CC) $(CFLAGS) -o $(OUT_BRANCHED)-b triad-with-branching-b.cpp
	./$(RUN_TEST_JOB) $(OUT_BRANCHED)-b > $(LOGFILE)-b.log

branched-c: triad-with-branching-c.cpp  
	$(CC) $(CFLAGS) -o $(OUT_BRANCHED)-c triad-with-branching-c.cpp
	./$(RUN_TEST_JOB) $(OUT_BRANCHED)-c > $(LOGFILE)-c.log

clean: 
	rm -rf $(OUT_BRANCHED)-* *.dSYM
