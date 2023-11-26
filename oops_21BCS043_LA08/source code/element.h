#include <bits/stdc++.h>
using namespace std;

// double rand_gen(){
//     double lower_bound = 0, upper_bound = 100;
//     uniform_real_distribution<double> unif(lower_bound, upper_bound);
//     default_random_engine re;
//     return unif(re);
// }

int rand_gen(int min=0, int max=50) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

class Element{
    public:
        // double _norm;
        virtual void print() = 0;
        virtual double norm() = 0;
        virtual double getNorm() = 0;
        // virtual double norm() = 0;
};