//  QuickSort.hpp
//  QuickSort
//  Jacob Bee Ho Brown
//  August 1, 2018
//  CS 228 Final Project
//  clocka: stackoverflow.com/questions/3220477/how-to-use-clock-in-c

#ifndef QuickSort_hpp
#define QuickSort_hpp

#include <stdio.h>
#include <vector>
#include <ctime>


template <class T>
class qs
{
public:
    void quicksort(std::vector<int>,int, int);
    void quicksort(std::vector<int>,int);
    int time = 0;
    bool successful = false;
    double duration;
};


/* Data Structures and Algorithms in c++ 4ed. ch. 9 figure 9.11 */
template<class T>
void qs<T>::quicksort(std::vector<int> data, int first, int last) {
    int lower = first +1;
    int upper = last;
    std::swap(data[first], data[(first+last)/2]);
    T bound = data[first];
    while(lower <= upper) {
        while (bound > data[lower]) {
            lower++;
        }
        while(bound < data[upper]) {
            upper--;
        }
        if(lower < upper) {
            std::swap(data[lower++], data[upper--]);
        }
        else {
            lower++;
        }
    }
    std::swap(data[upper], data[first]);
    if(first < upper-1) {
        quicksort(data, first, upper-1);
    }
    if(upper+1 < last) {
        quicksort(data, upper+1, last);
    }
    
}


template<class T>
void qs<T>::quicksort(std::vector<int> data, int n) {
    std::clock_t start;
    start = std::clock();
    duration = 0;
    int i;
    int max;
    if(n < 2) {
        return;
    }
    for(i = 1, max = 0; i < n; i++) {       // find largest element and put it
        if(data[max] < data[i]) {           // at the end of data[]
            max = i;
        }
        std::swap(data[n-1], data[max]);         // largest el is now in its final position
        qs<T>::quicksort(data, 0, n-2);
    }
    successful = true;
    duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
}
#endif /* QuickSort_hpp */
