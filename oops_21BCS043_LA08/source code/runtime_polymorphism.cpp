#include <iostream>
#include <bits/stdc++.h>

#include "./point.h"
#include "./pointN.h"
#include "./line.h"
#include "./vector.h"
#include <random>

#include <chrono>

using namespace std::chrono;
using namespace std;

void slowSort(Element * e[], int n){
    int i,j;
    Element *current;
    for(int i=1; i<n; i++){
        j = i-1;
        current = e[i];
        while( j>=0 && ( e[j]->norm() > current->norm() ) ){
            e[j+1] = e[j];
            j--;
        }
        e[j+1] = current;
    }
}
/* 
    Defined a variable name _norm publically in all the classes, so that it can store the
    norm. With this the invoke of norm() everytime for conversion is stopped that gave a boost in sorting
*/
void fastSort(Element * e[], int n){
    int i,j;
    Element *current;
    for(i=1; i<n; i++){
        j = i-1;
        current = e[i];
        // while(j>=0 && ( v[j].l2Norm() > current.l2Norm()) ){
        while( j>=0 && ( e[j]->getNorm() > current->getNorm() ) ){
            e[j+1] = e[j];
            j--;
        }
        e[j+1] = current;
    }
}
/*
    Calculating the time taken by the sorting method to sort the given array 
    and returning the count in microseconds 
*/
int perFormance(Element *e[], int n, bool s){
        auto start = high_resolution_clock::now();
        if(s){
            fastSort(e, n);
        } else{
            slowSort(e, n);
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "Time = "<< duration.count() <<" \xE6s(microseconds)"<< endl;
        return duration.count();
}

void generateElementArray(Element *all[], int s){
    for(int j=0; j<s; j++){
            if( j%3 == 0 ){
                double _x = rand_gen();
                double _y = rand_gen();
                // Runtime Polymorphism - element type to Point type
                all[j] = new Point( _x, _y );
            } else if( j%3 == 1 ){
                double _x = rand_gen();
                double _y = rand_gen();
                // Runtime Polymorphism - element type to Vector type
                all[j] = new Vector ( _x, _y );
            } else if( j%3 == 2 ){
                int _n = ((rand_gen()));
                PointN * temp = new PointN(_n);
                temp->setRandom();
                // Runtime Polymorphism - element type to PointN type
                all[j] = temp;
            }
        }
}

void printElementArray(Element *e[], int n){
    cout<<"Printing Array"<<endl;
    for(int i=0; i<n; i++){
        cout<<e[i]->norm()<<" ";
    }
    cout<<endl;
}

int main (){
    const int n = 3;
    int sizes[n];
    int tPower = 10;
    for(int i=0; i<n; i++){
        sizes[i] = (tPower);
        tPower *= 10;
    }
    /* Achieving Runtime Polymorphism in the generateElementArray Function using 
    Element class as abstract and line, point and pointN class as derived from it*/
    for(int i=0; i<n; i++){
        const int s = sizes[i];
        Element * sArray [s];
        Element * fArray [s];
        // Slow Sort
        generateElementArray(sArray, s);
        double eff1 = 0;
        cout<<"Data Size = "<<s<<endl;
        cout<<"Slow Sort: ";
        eff1 = perFormance(sArray, s, 0);
        // Fast Sort
        generateElementArray(fArray, s);
        double eff2 = 1;
        cout<<"Fast Sort: ";
        eff2 = perFormance(fArray, s, 1);
        cout<<"Efficiency Ratio (Slow/Fast) = "<< (eff2 && eff1 ? (eff1/eff2) : eff1)<<endl;
        // printElementArray(sArray, s);
        // printElementArray(fArray, s);
    }
    return 0;
}