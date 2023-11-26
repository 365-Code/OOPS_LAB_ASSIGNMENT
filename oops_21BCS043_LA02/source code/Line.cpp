
// Additional Assignment;

#include <iostream>
using namespace std;

class Line {

    private:
        double length;

    public:
        Line();
        Line(double len);
        ~Line();
        void setLength (double len);
        double getLength( void );

};

Line::Line(void){
    length = 0;
    cout << "Object is being created" << endl;
}

Line::Line(double len){
    length = len;
    cout << "Object is being created" << endl;
}

void Line :: setLength (double len){
    length = len;
}


double Line :: getLength ( void ){
    return length;
}

int main(){

    cout << __FILE__ << endl;
    Line line;
    line.setLength(6.0);
    cout << "Length of line: " << line.getLength() << endl;
    Line cLine = Line(line);  // This also calls copy constructor
    cout << "Length of copied line: " << cLine.getLength() << endl;
    cout << endl;
    return 0;
    
}








// Test Class - Declared to test program and some confusion.
// class Test{
    
//     private:
//         string s;
    
    
//     public:
//         void setData(string str){
//             s = str;
//         }
//         void getData(){
//             cout<<"String = "<<s<<endl;
//         }
        
//         ~Test();
// };

// Test :: ~Test(){
//     cout<<"Destructor is callled"<<endl;
//     s = " ";
// }



// void tesTing (){
    
//     Test t;
    
//     t.setData("This is my Str1");
//     t.getData();
    
//     // t.~Test();
    
//     cout<<"For function"<<endl;
    
// }



// int main(){
    
    
//     Test t;
    
//     tesTing();
    
//     t.setData("This is my Str");
//     t.getData();
    
//     // t.~Test();
    
    
    
//     return 0;
// }