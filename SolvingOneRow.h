//
// Created by 骆少衡 on 2017/3/6.
//

#ifndef IR_DROP_SOLVINGONEROW_H
#define IR_DROP_SOLVINGONEROW_H
#include "Net.h"
#define N 5
void InitArrayD(const Node* node,double *d,int row);
void SolvingOneRow(Node *node,int row);
double mse(const Node* node,double *v);
#endif //IR_DROP_SOLVINGONEROW_H
