#include <iostream>
#include <math.h>


using namespace std;

#define tolerence 0.001


class Point {
    private:
        static int count;
        double _x, _y;
    public:
        // Default constructor
        Point();
        // Parameterized constructor
        Point(double x, double y);
        // Copy constructor
        Point(Point const &p);
        // Destructor
        ~Point();

        /*
        Ans 1 -> Operator overload declaration, 
        Ans 2 -> Return type 'Point' and Argument Type 'Point'
        */
        Point operator + (const Point & p) const;
        bool operator < (const Point & p) const;
        bool operator > (const Point & p) const;
        bool operator == (const Point & p) const;

        // Member functions
        void setCoords( double x, double y);
        void printCoords( );
        double distFrom  (Point &p) const;
        Point midPoint(Point &p);

        /*
        Ans 3 -> const function can not change the data memeber of this object and 
        const argument cannot be change
        */
        // Static Memeber Function
        static int objInstances(); //getCount()
};


// Definition of memeber functions

Point :: Point (){
    count++;
    _x = _y = 0;
    // cout<<"Constructor is called"<<endl;
} // default constructor

Point :: Point (Point const &p){
    _x = p._x;
    _y = p._y;
}

Point :: ~Point (){
    count--;
    // cout<<"Destructor is called for "<<_x<<","<<_y<<endl;
} // destructor

Point :: Point (double x, double y){
    count++;
    _x = x;
    _y = y;
    // cout<<"Parameterized constructor is called"<<endl;
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


// Ans 4
Point Point :: operator + (const Point &p) const{
    Point p3;
    p3._x = _x + p._x;
    p3._y = _y + p._y;
    return p3;
}


// Problem 2
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



int main(){

    Point p1(1,1), p2(2,2), p3(3,3), p4;

    p4 = p1 + p2 + p3; // Chain Addition

    p4.printCoords();

    if(p1 < p2 ){
        cout<<"P1 is less than p2"<<endl;
    } else {
        cout<<"P1 is greater than p2"<<endl;
    }

    cout << "Instance of Point Class = " << Point :: objInstances();

    

    return 0;
}
