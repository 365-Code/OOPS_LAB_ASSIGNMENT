#include <bits/stdc++.h>
#include <math.h>
#include "element.h"

using namespace std;

#define tolerence 0.001

class Point : public Element {
    static int count;
    double _x;
    double _y;
    public:
    void setCoords( double x, double y);
    void printCoords( );
    double distFrom  (Point &p) const;

    pair<double, double> getXY(){
        pair<double, double> p;
        p.first = _x;
        p.second = _y;
        return p;
    }

    void print();


    Point midPoint(Point &p);
    Point(); // This is the DEFAULT constructor
    Point(double x, double y); // This is the PARAMETERIZED constructor
    Point(Point &p); // This is the COPY constructor
    ~Point(); // This is the destructor

    static int objInstances(); // static memeber function

    double l2Norm() const;

    Point operator + (const Point & p) const; // Ans 1 -> Operator overload declaration, Ans 2 -> Return type 'Point' and Argument Type 'Point'.
    bool operator < (const Point & p) const;
    bool operator > (const Point & p) const;
    bool operator == (const Point & p) const;
    double operator [] (const bool);
    friend istream & operator >> (istream &in, Point&p);
    friend ostream & operator << (ostream &out, const Point&p);

    void iSort (Point p[], int n);

    // Ans 3 -> const function can not change the data memeber of this object and const argument cannot be change
    static int getCount();
};

void Point :: print(){
    cout<<"X = "<<_x<<", Y = "<<_y<<endl;
}

// Definition of memeber functions

Point :: Point (){
    count++;
    _x = _y = 0;
    // cout<<"Point: Default Constructor is called"<<endl;
    // cout<<"constructor is called"<<endl;
} // default constructor

Point :: ~Point (){
    // cout<<"Point: Destructor is called for "<<_x<<","<<_y<<endl;
    count--;
} // destructor

Point :: Point (double x, double y){
    count++;
    _x = x;
    _y = y;
    // cout<<"Point: Parameterized constructor is called for "<<_x<<","<<_y<<endl;
    
} // Parameterized constructor

// memeber functions 
void Point :: setCoords ( double x, double y){
    _x = x;
    _y = y;
} 

void Point :: printCoords (){
    cout<<_x<<","<<_y<<endl;
}

// 5. Memeber function accessing private member of all objects of this class.

double Point :: distFrom(Point &p) const{ 
    // const memeber because it can't change the data memeber of this object
    double d;
    d = sqrt( pow( (_x-p._x), 2 ) + pow( (_y-p._y), 2 ) );
    return d;
}

Point Point :: midPoint (Point &p){
    Point nP;
    nP._x = (_x+p._x)/2;
    nP._y = (_y+p._y)/2;
    return nP;
}

int Point :: count = 0; // definition of static variable. Memory is allocated here;

int Point :: objInstances (){
    return count;
}

// Lab 5

double Point :: l2Norm() const{
    double x = _x*_x;
    double y = _y*_y;
    return sqrt(x+y);
}

void Point :: iSort (Point p[], int n){
    int i,j;
    Point current;
    for(int i=1; i<n; i++){
        current = p[i];
        j = i-1;
        // while(j>=0 && ( p[j].l2Norm() > current.l2Norm()) ){
        while(j>=0 && ( p[j] > current) ){
            p[j+1] = p[j];
            j--;
        }
        p[j+1] = current;
    }

}


// Operator Overloading

Point Point :: operator + (const Point &p) const{
    Point p3;
    p3._x = _x + p._x;
    p3._y = _y + p._y;
    return p3;
}

bool Point :: operator < (const Point &p) const{
    double d1 = _x*_x + _y*_y;
    double d2 = p._x*p._x + p._y*p._y;
    return d1<d2;
}

bool Point :: operator > (const Point &p) const{
    double d1 = _x*_x + _y*_y;
    double d2 = p._x*p._x + p._y*p._y;
    return d1>d2;
}

bool Point :: operator == (const Point &p) const{
    double d1 = _x*_x + _y*_y;
    double d2 = p._x*p._x + p._y*p._y;
    return d1==d2;
}

double Point :: operator [] (const bool a){
    return a ? _y : _x;
}

ostream & operator << (ostream &out, const Point &p){
    out<<"x="<<p._x<<",y="<<p._y;
    return out;
}

istream & operator >> (istream &in, Point &p){
    in >> p._x;
    in >> p._y;
    return in;
}