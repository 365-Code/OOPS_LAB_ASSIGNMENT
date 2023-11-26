#include <bits/stdc++.h>
#include <math.h>
#include "location.h"

#include <chrono>

using namespace std::chrono;
using namespace std;

int main(){

    //Problem - 1
    Location L1(1, 3, "india");
    Location L3 (3.2, 4.4);
    double dis = L1.distFrom(L3);
    cout<<"distance = "<<dis<<endl;

    L1.printAddr();
    L3.printAddr();

    // Problem- 2
    Location LP1(1.2, 2.3, "addr");
    Location LP2(2.4, 3.2);

    double d = LP1.distFrom(LP2);

    Location Loc[10] =
    {
        Location(28.66992, 77.29162, "Shahadra mandi, eastern"),
        Location(28.68991, 77.30672, "GTB Brossing, eastern"),
        Location(28.68991, 77.25796, "kalash nagar pusta, eastern"),
        Location(28.64789, 77.29509, "jagatpuri red light, eastern"),
        Location(28.65005, 77.31381, "ISBT Ananad Vihar, eastern"),
        Location(28.67069, 77.26678, "Seelampur T-oint, eastern"),
        Location(28.7111, 77.26034, "khajori chowk, eastern"),
        Location(28.70129, 77.29146, "loni gol chakkar, eastern"),
        Location(28.61812, 77.32086, "kondii Bridge, eastern"),
        Location(28.63583, 77.28713, "nirman vihar, eastern")
    };

    // Location Loc[10];
    // Loc[0] = Location(28.66992, 77.29162, "Shahadra mandi, eastern");
    // Loc[1] = Location(28.68991, 77.30672, "GTB Brossing, eastern");
    // Loc[2] = Location(28.68991, 77.25796, "kalash nagar pusta, eastern");
    // Loc[3] = Location(28.64789, 77.29509, "jagatpuri red light, eastern");
    // Loc[4] = Location(28.65005, 77.31381, "ISBT Ananad Vihar, eastern");
    // Loc[5] = Location(28.67069, 77.26678, "Seelampur T-point, eastern");
    // Loc[6] = Location(28.7111, 77.26034, "khajori chowk, eastern");
    // Loc[7] = Location(28.70129, 77.29146, "loni gol chakkar, eastern");
    // Loc[8] = Location(28.61812, 77.32086, "kondii Bridge, eastern");
    // Loc[9] = Location(28.63583, 77.28713, "nirman vihar, eastern");

    double dKm = 0;
    for(int i=1; i<10; i++){
        double disKm = Loc[i-1].distFrom(Loc[i]);
        dKm += disKm;
    }

    cout<<"Driver Distance Covered in Km = "<<dKm<<"km"<<endl;

    // Problem - 3
    LP1.print(); // Virtual function from Point Class is called
    

    return 0;
}
