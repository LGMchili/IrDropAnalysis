//
// Created by 骆少衡 on 2017/3/6.
//
#include "SolvingOneRow.h"
#include "Net.h"
#include <cassert>
#include <cmath>
#include <iostream>

void InitArrayD(const Node *node, double *d, int row) {
    assert(row >= 0 || row < N);
    if (row == 0)
        for (int i = 0; i < N; ++i) {
            d[i] = (node[(row + 1) * N + i].g_d * node[(row + 1) * N + i].v) - node[row * N + i].i;
        }
    else if (row == N - 1)
        for (int i = 0; i < N; ++i) {
            d[i] = (node[(row - 1) * N + i].g_u * node[(row - 1) * N + i].v) - node[row * N + i].i;
        }
    else
        for (int i = 0; i < N; ++i) {
            d[i] = (node[(row + 1) * N + i].g_d * node[(row + 1) * N + i].v) +
                    (node[(row - 1) * N + i].g_u * node[(row - 1) * N + i].v) - node[row * N + i].i;
        }
}

double mse(const Node *node, double *v) {
    double e(0);
    for (int i = 0; i < N * N; ++i) {
        e += pow(node[i].v - v[i], 2);
    }
    e = sqrt(e / (N * N));
    return e;
}

void SolvingOneRow(Node *node, int row) {
    assert(row > 1 || row < N - 1);
    double *u = new double[N];
    double *l = new double[N];
    double *d = new double[N];
    double *y = new double[N];
    InitArrayD(node, d, row);
    u[0] = node[row*N].G;
    for (int i = 1; i < N; ++i) {
        l[i] = -node[row * N + i].g_l / u[i - 1];
        u[i] = node[row * N + i].G + (l[i] * node[row * N + i - 1].g_r);
    }
    y[0] = d[0];
    for (int j = 1; j < N; ++j) {
        y[j] = d[j] - (l[j] * y[j - 1]);
    }
    node[row * N + N - 1].v = y[N - 1] / u[N - 1];
    for (int k = N - 2; k >= 0; --k) {
        node[row * N + k].v = (y[k] + node[row * N + k + 1].v * node[row * N + k].g_r) / u[k];
    }
    delete[] u;
    delete[] y;
    delete[] l;
    delete[] d;
}