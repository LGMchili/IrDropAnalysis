#include <iostream>
#include "Net.h"
#include "SolvingOneRow.h"
int main() {
    int iterate_cnt = 0;
    Net net(N) ;
    double e = 0;
    double *v = new double[N*N];
    double *d = new double[N];
    while (iterate_cnt < 100){
        for (int j = 0; j < N*N; ++j) {
            v[j] = net.node[j].v;
        }
        for (int i = 0; i < N; ++i) {
            SolvingOneRow(net.node,i);
        }
        e=mse(net.node,v);
        std::cout <<e
                  << "\n";
        iterate_cnt++;
        if (e<1e-8) break;
    }
    std::cout <<iterate_cnt<< std::endl;
    net.print_v();

    delete [] v;
    return 0;
}