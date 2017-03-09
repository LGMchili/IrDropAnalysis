#include <iostream>

class Node{
public:
    Node():v(0),i(0),g_u(0),g_d(0),g_r(0),g_l(0),G(0){}
    float v;
    float i;
    int g_u,g_d,g_r,g_l;
    int G = g_u + g_d + g_r + g_l;
};
