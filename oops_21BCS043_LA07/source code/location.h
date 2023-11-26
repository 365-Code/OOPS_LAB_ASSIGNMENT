#include <bits/stdc++.h>
#include "point.h"

using namespace std;

class Location : public Point{

    string address;

    static double R;
    static double pi;

    public:
        Location(){
            // cout<<"Location: Default Constructor called"<<endl;
            }
        Location (double x, double y, string addr);
        Location (double x, double y);
        void setLoc(double x, double y, string addr);
        ~Location(){
            // cout<<"Location: Default Destructor called"<<endl;
            }
        void printAddr();
        void setAddr(string);
        double distFrom(Location &);
        double distKm();
};

double Location :: pi = 2 * asin(1);
double Location :: R = 6371; //(in km)

Location :: Location(double x, double y, string addr){
    // cout<<"Location: Parameterized Constructor called for "<<x<<","<<y<<","<<addr<<endl;
    setCoords(x, y);
    address = addr;
}

// Location :: Location(double x, double y){
//     setCoords(x, y);
// }

Location :: Location(double x, double y): Point(x,y){ // For calling the constructor of super/base class Point
    // cout<<"Location: Parameterized costructor for only coordinates"<<endl;
}

void Location :: printAddr (){
    printCoords();
    cout<<"Address = "<<address<<endl;
}

void Location :: setAddr(string addr){
    address = addr;
}

void Location ::  setLoc(double x, double y, string addr){
    setCoords(x, y);
    address = addr;
}

// Error: when a const object is passed as an argument
double Location :: distFrom(Location &loc){
    pair<double , double> p1 = loc.getXY();
    pair<double , double> p2 = this->getXY();
    double m1 = p1.second/p1.first;
    double m2 = p2.second/p2.first;

    // cout<<m1<<" "<<m2<<endl;
    double angle = abs( (m1-m2)/(1+ m1*m2) );
    angle = atan(angle);
    // angle = cos(angle);
    // angle = acos(angle);
    // angle = acos(angle);
    // printf("R = %f, pi = %f, angle = %f", R, pi, angle);
    double dist = R * pi * angle;
    return dist;
}