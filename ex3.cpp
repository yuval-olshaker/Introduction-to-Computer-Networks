//
// Created by yuvalol on 26/05/2021.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


vector<double> get_times(double T, double lambda){
    vector <double> as;
    double a0 = 0.0; /* a convention */
    as.emplace_back(a0);
    while(as[as.size()-1] < T) {
        as.emplace_back(as[as.size()-1] + exp(1 / lambda));
    }
    return as;
}

int main (int argc, char *argv[]) {
    double T = stod(argv[1], nullptr);
    double lambda = stod(argv[2], nullptr);
    double miu = stod(argv[3], nullptr);
    vector<double> ps;
    for (int i = 4 ; i < argc; i++){
        ps.emplace_back(stod(argv[i], nullptr));
    }

    vector<double> arrivel_times = get_times(T, lambda);
    vector<double> queue;
    vector<double> finish_times;
    vector<pair<int,double>> amounts;
    int X = 0;
    int Y = 0;
    cout << " arrivel_times.size() " << arrivel_times.size() << endl;
    for (int i = 0 ; i < arrivel_times.size() ; i++){
        cout << " i " << i << endl;
        amounts.emplace_back(make_pair(queue.size(), arrivel_times[i]));
        double pi = ps[queue.size()];
        if ((double) rand()/RAND_MAX > pi){
            X++;
        } else {
            Y++;
            queue.emplace_back(arrivel_times[i]);
            if (finish_times.empty()){
                finish_times.emplace_back(arrivel_times[i] + exp(1 / miu));
            } else {
                finish_times.emplace_back(finish_times[finish_times.size() - 1] + exp(1 / miu));
            }

            amounts.emplace_back(make_pair(queue.size(),arrivel_times[i]));
        }
        // deal with finish packets
        if (i+1 == arrivel_times.size()){ // if last packet we finish with all
            int len = finish_times.size();
            for (int k = 0; k < len; k++) {
                double time = finish_times[0];
                queue.erase(queue.begin());
                finish_times.erase(finish_times.begin());
                amounts.emplace_back(make_pair(queue.size(), time));
            }
        }
        else { // if has move packets then we will find the last one that will finish
                // process before the next packet arrives and process all the packets to it
            int max = -1;
            for (int j =0; j < finish_times.size(); j++){
                if (finish_times[j] > arrivel_times[i+1]) {
                    break;
                }
                max = j;
            }
            cout << "max" << endl;
            cout << max << endl;
            for (int j =0; j <= max; j++){
                double time = finish_times[0];
                queue.erase(queue.begin());
                finish_times.erase(finish_times.begin());
                amounts.emplace_back(make_pair(queue.size(), time));
            }
        }
    }
    cout << X << endl;
    cout << Y << endl;
}


