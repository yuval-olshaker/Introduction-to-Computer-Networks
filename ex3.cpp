//
// Created by yuvalol on 26/05/2021.
//
#include <iostream>
#include <vector>
using namespace std;


vector<double> get_times(double T, double lambda){
    vector <double> as;
    a0 = 0.0; /* a convention */
    as.push_back(a0);
    while(as[as.size()-1] < T) {
        as.push_back(as[as.size()-1] + Exponential(1 / λ));
    }
    return as;
}

int main (int argc, char *argv[]) {
    double T = stod(argv[0]);
    double lambda = stod(argv[1]);
    double miu = stod(argv[2]);
    vector<double> ps;
    for (int i = 3 ; i < argc; i++){
        ps.push_back(stod(argv[i]));
    }

    vector<double> arrivel_times = get_times(double T, double lambda);
    vector<double> queue;
    vector<pair<int,double>> amounts;
    X = 0;
    Y = 0;
    for (int i = 0 ; i < arrivel_times.size() ; i++){
        amounts.push_back(make_pair(queue.size(),arrivel_times[i]));
        pi = ps[queue.size()];
        if ((double) rand()/RAND_MAX > pi){
            X++;
            continue;
        }
        Y++;
        queue.push_back(arrivel_times[i]);
        amounts.push_back(make_pair(queue.size(),arrivel_times[i]))
        // moving out from queue
        if (1 > 0){
            int a = 5;
        }

    }
}


