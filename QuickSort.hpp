//  QuickSort.hpp
//  QuickSort
//  Jacob Bee Ho Brown
//  August 1, 2018
//  CS 228 Final Project

// NEED TO ADD: timer

#ifndef QuickSort_hpp
#define QuickSort_hpp

#include <stdio.h>

/* Data Structures and Algorithms in c++ 4ed. ch. 9 figure 9.11 */
template<class T>
void quicksort(T data[], int first, int last) {
    int lower = first +1;
    int upper = last;
    swap(data[first], data[(first+last)/2]);
    T bound = data[first];
    while(lower <= upper) {
        while (bound > data[lower]) {
            lower++;
        }
        while(bound < data[upper]) {
            upper--;
        }
        if(lower < upper) {
            swap(data[lower++], data[upper--]);
        }
        else {
            lower++;
        }
    }
    swap(data[upper], data[first]);
    if(first < upper-1) {
        quicksort(data, first, upper-1);
    }
    if(upper+1 < last) {
        quicksort(data, upper+1, last);
    }
    
}


template<class T>
void quicksort(T data[], int n) {
    int i;
    int max;
    if(n < 2) {
        return;
    }
    for(i = 1, max = 0; i < n; i++) {       // find largest element and put it
        if(data[max] < data[i]) {           // at the end of data[]
            max = i;
        }
        swap(data[n-1], data[max]);         // largest el is now in its final position
        quicksort(data, 0, n-2);
    }
}
#endif /* QuickSort_hpp */
