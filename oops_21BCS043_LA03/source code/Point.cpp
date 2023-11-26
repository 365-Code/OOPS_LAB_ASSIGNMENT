#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Point {
    // Private Access Modifiers - By default

    /* 
    Can be accessed within the scope of the class, 
    not outside
    */
    double _x, _y; 
    
    const int origin_x = 0;
    const int origin_y = 0;
    
    /*
    memeory is allocated for static data members once they are 
    defined even though no objects of that class have been instantiated. 
    Verified using variable 'test'
    */
    static int test;
    
    // declaration of static variable, no memory is allocated here.
    static int  count, 
                countTL, 
                countTR, 
                countBR, 
                countBL;
    
    // Private Access Modifier
    private:
        // Private Memeber functions
        void decQuads();
        void incQuads(double x, double y);

    // Public Access Modifier
    public:
        // Member function can be accessed by the object of that class.
        // Declaration of memeber functions
        void setCoords ( double x, double y);
        void printCoords ();

        /* 
        Declaring a member function with the const keyword 
        specifies that the function is a "read-only" function that 
        doesn't modify the object for which it's called. 
        A constant member function can't modify any non-static data 
        members or call any member functions that aren't constant. 
        */

        // Const Memeber Function
        double distFrom(Point &p) const;
        
        // Default Constructor;
        Point();

        // Parameterized Constructor - 
        Point(double x, double y);

        // Copy Constructor
        Point(Point &p);
        ~Point(); // Destructor

        
        void setQuads(double x, double y);
        static void printTest();
        Point midPoint (Point &p); 


        // Static Memeber Function

        // This function return the count of the object created.
        static int objInstances();

        // 
        static void pointsIn2DQuadrants();
        
        // Couldn't complete and understand graphics.h
        void setGraph();
        void visualizeGraph();
        
};

// Definition of Static Variable. Memory is allocated here;
int Point :: test = 54;
int Point :: count = 0;

// 2D quadrant
int Point :: countTR = 0; 
int Point :: countTL = 0;
int Point :: countBR = 0;
int Point :: countBL = 0;

// Definition of memeber functions

// Default Constructor
Point :: Point (){
    count++;
    _x = _y = 0;
    cout<<"Constructor is called";
}

// Destructor
Point :: ~Point (){
    count--;
    decQuads();
    // cout<<"Destructor is called for "<<_x<<","<<_y<<endl;
}

// Parameterized Constructor
Point :: Point (double x, double y){
    count++;
    setQuads(x, y);
    _x = x;
    _y = y;
}

// Memeber Functions 
void Point :: setCoords ( double x, double y){
    setQuads(x, y);
    _x = x;
    _y = y;
} 

void Point :: printCoords (){
    cout<<_x<<","<<_y<<endl;
}

    /*
    Memeber function can access private member of all objects of 
    this class
    */

//  const memeber because it can't change the data memeber of this object
double Point :: distFrom(Point &p) const{
    
    double d;
    d = sqrt( pow( (_x-p._x), 2 ) + pow( (_y-p._y), 2 ) );
    
    return d;
    
}

Point Point :: midPoint (Point &p){
    
    Point nP;
    
    nP._x = (_x+p._x)/2;
    nP._y = (_y+p._y)/2;
    
    setQuads(nP._x , nP._y);
    
    return nP;
    
}

void Point :: printTest (){
    cout<<test<<endl;
}

int Point :: objInstances (){
    return count;
}

void Point :: decQuads (){
    if( _x < 0 and _y > 0  ){
        countTL--;
    } else if( _x > 0 and _y > 0  ){
        countTR--;
    } else if( _x > 0 and _y < 0  ){
        countBR--;
    } else if( _x < 0 and _y < 0  ){
        countBL--;
    }
}

void Point :: incQuads (double x, double y){
    if( x < 0 and y > 0 ){
        countTL++;
    } else if( x > 0 and y > 0 ){
        countTR++;
    } else if( x > 0 and y < 0 ){
        countBR++;
    } else if( x > 0 and y > 0 ){
        countBL++;
    }
}

void Point :: setQuads (double x, double y){
    decQuads();
    incQuads(x, y);
}

void Point :: pointsIn2DQuadrants (){
    cout<<"countTL = "<<countTL<<endl;
    cout<<"countTR = "<<countTR<<endl;
    cout<<"countBR = "<<countBR<<endl;
    cout<<"countBL = "<<countBL<<endl;
}

// void Point :: setGraph(){
    
//     for(int i=0; i<10; i++){
//         for(int j=0; j<10; j++){
//             graph[i][j] = setCoords(i,j);
//         }
//     }
    
// }


// void Point :: visualizeGraph(){
    
//     for(int i=0; i<10; i++){
//         for(int j=0; j<10; j++){
//             cout<<"x= "<<graph[i][j]._x<<", y= "<<graph[i][j]._y<<endl;
//         }
//     }
    
// }


int main(){
    
    
    // Point :: printTest();

    Point p1(1,2);
    
    Point p2(-3,4);
    
    Point p3(-3,4);
    
    Point p;


    cout << "No of objects of Point class = "<< Point :: objInstances() << endl;
    Point :: pointsIn2DQuadrants();
}
