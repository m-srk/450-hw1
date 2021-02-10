#include <stdio.h>
#include <iostream>
#include <sys/time.h>

using namespace std;

void get_walltime(double* wcTime) {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    *wcTime = (double)(tp.tv_sec + tp.tv_usec/1000000.0);
}

double dummy_func(double* A, double* B, double* C, double* D) {
    cout << "Entered dummy_func !" << endl;
    double tmp = *(A + 2);
    return tmp;
}

void print_usage() {
    cout << "Usage : ./vt-benchmark <N_value> <R_value>" << endl;
    cout << "           N -> num times inner loop is run for benchmarking" << endl;
    cout << "           R -> num times outer loop is run" << endl;
}

double compute_mflops(int N, int R) {
    double St, End, Mflops;

    // init arrays and iterators
    int i,j,k;
    double *A = new double[N], 
        *B = new double[N], 
        *C = new double[N], 
        *D = new double[N];

    for (i=0; i<N; i++) {
        A[i] = 0.0; B[i] = 1.0; C[i] = 2.0; D[i] = 3.0;
    }

    get_walltime(&St);
    
    // triad benchmarking loop, with branching
    for (j=0; j<R; j++) {
        for (k=0; k<N; k++) {
            if (C[k] < 0) {
                A[k] = B[k] - C[k] * D[k];
            } else {
                A[k] = B[k] + C[k] * D[k];
            }
	    }
        // dummy call to prevent loop switching or optimization ->
        if (A[2] < 0) {
            dummy_func(A, B, C, D);
        }
    }

    get_walltime(&End);
    Mflops = R*N*(2.0)/((End-St)*1000000.0);

    // heap cleanup
    delete [] A; delete [] B; delete [] C; delete [] D;
    
    return Mflops;
}

int main (int argc, char** argv) {
    int N, R;
    if (argc > 3) {
        print_usage();
        exit(EXIT_FAILURE);
    } else if (argc == 3) {
        N = atoi(argv[1]);
        R = atoi(argv[2]);
        cout << compute_mflops(N, R) << endl;
    } else {
        // Incase of no args, defaults to values provided for N & R
        N = 1000;
        R = 1000000;
        cout << compute_mflops(N, R) << endl;
    }
    
    return 0;
}
