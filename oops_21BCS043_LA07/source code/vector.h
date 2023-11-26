#include <iostream>
#include "element.h"
class Vector : public Element{
    public:
        void print();
};

void Vector :: print (){
    cout<<"Vector Virtual function"<<endl;
}