//
// Created by 骆少衡 on 2017/3/6.
//
#include <iostream>
#include "Net.h"
void Net::print_v() const {
    for (int i = row_ -1; i >= 0; --i) {
        for (int j = 0; j <row_; ++j) {
            std::cout << node[i * row_ + j].v
                      << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

void Net::print_G() const {
    for (int i = row_ -1; i >= 0; --i) {
        for (int j = 0; j <row_; ++j) {
            std::cout << node[i * row_ + j].G
                      << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}
