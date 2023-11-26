#include <bits/stdc++.h>
#include <math.h>
// Point Header Defined in the parent folder to use in all files
#include "point.h"
#include <chrono>

using namespace std;
using namespace std::chrono;


void insertionSort (Point p[], int n){
    int i,j;
    Point current;
    for(int i=1; i<n; i++){
        current = p[i];
        j = i-1;
        // before '>' overloading
            // while(j>=0 && ( p[j].l2Norm() > current.l2Norm()) ){
        // after overloading '>' operator
        while(j>=0 && ( p[j] > current) ){
            p[j+1] = p[j];
            j--;
        }
        p[j+1] = current;
    }
}


int main(){

    Point p1(1,2);

    vector <int> arrSizes = {10, 100, 1000, 5000, 10000, 50000, 100000};
    int n;
    for(int i=0; i<arrSizes.size(); i++){
        n = arrSizes[i];
        Point p[n];
        for(int i=0; i<n; i++){
            p[i].setCoords(rand()%n, rand()%n);
        }
        cout<<"Array Size = "<< n << endl;
        auto start = high_resolution_clock::now(); // from chrono header
        insertionSort(p, n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        // \xE6s - symbol for microseconds in windows
        cout << "Time Taken= "<< duration.count() <<" \xE6s"<< endl;
        
    }

    return 0;
}
