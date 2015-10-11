#include <iostream>
#include "include/benchmark.h"



int main(int argc, char **argv) {
    std::cout<<"Hilbert Morton Bench Version 2.0"<<std::endl;
    Benchmark* bench;

    int args=argc;
    int arg_dim=atoi(argv[1]);
    int arg_num_pts=atoi(argv[2]);
    int arg_max_depth=atoi(argv[3]);
    int arg_iter=atoi(argv[4]);

    //initializeHilbetTable(arg_dim);

    _InitializeHcurve();

    bench=new Benchmark(arg_max_depth,arg_dim,arg_num_pts,arg_iter);
    bench->run_bench();
    free(bench);

    return 0;
}