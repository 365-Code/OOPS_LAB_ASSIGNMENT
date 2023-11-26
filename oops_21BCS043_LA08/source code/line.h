#include <iostream>



class Line : public Element{
    private:
        int length;
        string name;
    
    public:
        double _norm = 0;
        Line (int l, string n){length = l; name = n; norm();}
        Line (string n){name = n; length = 0;}
        Line (int l){length = l; name = ""; norm();}
        Line (){length = 0; name = "";}
        double norm();
        void print();
        double getNorm(){return _norm;}


};


double Line :: norm (){

    double distance = 0;
    double L1 = length * length;
    // distance = sqrt (L1);
    distance = L1;
    this->_norm = distance;
    return distance;
}

void Line :: print (){
    cout<<"Name = "<<name<<endl
        <<"Length = "<<length<<endl
        <<"Norm = "<<norm()<<endl;
}