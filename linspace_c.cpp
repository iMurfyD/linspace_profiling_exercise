#include <time.h>
#include <stdio.h>
#include <stdlib.h>

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
    clock_t begin = clock();
    double* test = allocate_linspace(0.0, 100000.0, 100001);
    clock_t end = clock();

    double time_spent = (double)(end - begin);// / CLOCKS_PER_SEC;

    printf("Linspace took %f\n", time_spent);

    free(test);

    return 0;
}
