//
// Created by yuvalol on 26/05/2021.
//
#include <iostream>
#include <vector>
using namespace std;

int main (int argc, char *argv[]) {
    double T = std::stod(argv[0]);
    double lambda = std::stod(argv[1]);
    double miu = std::stod(argv[2]);
    vector<double> g1;
    for (int i = 3 ; i < argc; i++){
        g1.push_back(std::stod(argv[i]));
    }
}