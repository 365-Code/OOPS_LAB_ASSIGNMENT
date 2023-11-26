#include <iostream>


class Vector : public Element{
    protected:
        double _i, _j, _k;
    public:
        double _norm;
        Vector(){_i = 0; _j=0; _norm = 0;}
        Vector(int i, int j){_i=i; _j = j; norm();}
        void print();
        double norm();
        double getNorm(){return _norm;}
};


void Vector :: print (){
    cout<<"i = "<<_i<<", j = "<<_j<<endl
        <<"Norm = "<<norm()<<endl;
}

double Vector :: norm (){
    double dist;
    dist =( _i*_i) + (_j *_j);
    _norm = dist;
    return dist;
}