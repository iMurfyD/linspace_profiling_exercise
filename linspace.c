#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BILLION 1000000000L;

double* allocate_linspace(double min, double max, const int n)
{
    const double dx = (max - min) / ((double) n - 1.0);
    double* ret = (double *) malloc (n * sizeof(double));
    
    for(int i=0; i<n; i++) {
        ret[i]=(min + (i*dx));
    }

    return ret;
}


int main() {
    struct timespec start, stop;
    long double time_spent;

    //clock_gettime(CLOCK_REALTIME, &start);
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &start);
    double* test = allocate_linspace(0.0, 1000000.0, 1000001);
    //clock_gettime(CLOCK_REALTIME, &stop);
    //clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &stop);

    time_spent = (stop.tv_sec - start.tv_sec) + ((double) stop.tv_nsec - (double) start.tv_nsec) / BILLION;

    printf("stop nsec - start nsec = %ld\n", stop.tv_nsec - start.tv_nsec);
    printf("Linspace took %Lf\n", time_spent);

    free(test);

    return 0;
}
