//
// Created by 骆少衡 on 2017/3/6.
//
#ifndef IR_DROP_NET_H
#define IR_DROP_NET_H
class Node{
public:
    Node():v(0),i(0.1),g_u(1),g_d(1),g_r(1),g_l(1),G(4){}
    double v;
    double i;
    double g_u,g_d,g_r,g_l;
    double G;
};
class Net{
public:
    Net(int x){
        node = new Node[x * x];
        for (int i = 0; i < x; ++i) {
            node[i].G = (i==0||i==x-1)?2:3;
            node[i+x*(x-1)].G = (i==0||i==x-1)?2:3;
            node[i*x].G = (i==0||i==x-1)?2:3;
            node[i*x+x-1].G = (i==0||i==x-1)?2:3;
        }
//        node[0].G = 2;
//        node[x].G = 2;
        row_ = x;
        col_ = x;
    }
    ~Net(){delete [] node;}
    void print_v() const ;
    void print_G() const ;
    Node *node;
    int row_;
    int col_;
};

#endif //IR_DROP_NET_H
