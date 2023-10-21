#include <iostream>
#include <vector>
#include <time.h>

std::vector<double> allocate_linspace(double min, double max, const int n)
{
    const double dx = (max - min) / (double(n) - 1.0);
    std::vector<double> ret;
    ret.resize(n);
    // ret.resize(n);
    
    for(int i=0; i<n; i++) {
        ret[i]=(min + (i*dx));
    }

    return ret;
}


int main() {
    clock_t begin = clock();
    auto test = allocate_linspace(0.0, 100000.0, 100001);
    clock_t end = clock();

    double time_spent = (double)(end - begin);// / CLOCKS_PER_SEC;

    std::cout << "Linspace took " << time_spent << std::endl;

    return 0;
}
