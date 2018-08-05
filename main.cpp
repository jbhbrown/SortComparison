//  main.cpp
//  QuickSort
//
//  [Jacob Bee Ho] Written after watching the following videos about how to read data from
//  a .csv file on youtube:
//  www.youtube.com/watch?v=wRj9PZ2wyZI
//  www.youtube.com/watch?v=71DnOYeqJuM     -- where to store .csv file
//  and the following webpage about the "stio" function:
//  www.geeksforgeeks.org/converting-strings-numbers-cc/

#include <iostream>
#include <fstream>
#include <vector>
#include "QuickSort.hpp"
#include "MergeSort.hpp"
//#include "customer_data.csv"


void printVector(std::vector<int> vec) {
    for(int i = 0; i < vec.size(); i++){
        std::cout << vec[i] << ", ";
        if(i % 25 == 0)
            std::cout << "\n";
    }
}


int main(int argc, const char * argv[]) {
    /* small dataset -- 2002 ints -- "customer_data.csv" */
    int elCount = 0;
    std::vector <int> vec;
    //std::ifstream ip("customer_data.csv");
    std::ifstream smallData;
    smallData.open("customer_data.csv");
    if(!smallData.is_open()) {
        std::cout << "Error, file is not open.\n";
    }
    std::string Fresh;
    std::string Milk;
    std::string Grocery;
    std::string Frozen;
    std::string Detergents_Paper;
    std::string Delicassen;
    int Fresh_int;
    int Milk_int;
    int Grocery_int;
    int Frozen_int;
    int Detergents_Paper_int;
    int Delicassen_int;
    while(smallData.good()) {
        std::getline(smallData, Fresh, ',');
        std::getline(smallData, Milk, ',');
        std::getline(smallData, Grocery, ',');
        std::getline(smallData, Frozen, ',');
        std::getline(smallData, Detergents_Paper, ',');
        std::getline(smallData, Delicassen, ',');
        Fresh_int = stoi(Fresh);
        Milk_int = stoi(Milk);
        Grocery_int = stoi(Grocery);
        Frozen_int = stoi(Frozen);
        Detergents_Paper_int = stoi(Detergents_Paper);
        Delicassen_int = stoi(Delicassen);
        vec.push_back(Fresh_int); elCount++;
        vec.push_back(Milk_int); elCount++;
        vec.push_back(Grocery_int); elCount++;
        vec.push_back(Frozen_int); elCount++;
        vec.push_back(Detergents_Paper_int); elCount++;
        vec.push_back(Delicassen_int); elCount++;
    }
    std::cout << "Vector is " << elCount << " elements in size.\n";
    //printVector(vec);
    qs<int> *quick_small = new qs<int>;
    //quick_small -> quicksort(vec, vec[vec.size()/2]);
    std::cout << "Quicksorting...\n";
    quick_small -> quicksort(vec, int(vec.size()/2));
    if(quick_small -> successful) {
        std::cout << "Quicksort successful.\n";
        //printVector(vec);
        std::cout << "Time to Quicksort: " << quick_small -> duration << " sec.\n";
    }
    else {
        std::cout << "Sort failed.\n";
    }
    
    
    /* large dataset -- 101766 ints -- "diabetic_data.csv" */
    int elCount2 = 0;
    std::vector <int> vec2;
    std::ifstream largeData;
    largeData.open("DJIA.csv");
    if(!largeData.is_open()) {
        std::cout << "\nError, file is not open.\n";
    }
    std::string line1;
    int line1_int;
    while(largeData.good()) {
        std::getline(largeData, line1);
        line1_int = stoi(line1)/10;
        vec2.push_back(line1_int); elCount2++;
    }
    std::random_shuffle(vec2.begin(), vec2.end());      // shuffle elements in vec2
    std::cout << "\nVector2 is " << elCount2 << " elements in size.\n";
    //printVector(vec2);
    qs<int> *quick_large = new qs<int>;
    //quick_large -> quicksort(vec2, vec2[vec2.size()/2]);
    std::cout << "Quicksorting...\n";
    quick_large -> quicksort(vec2, int(vec2.size()/2));
    if(quick_large -> successful) {
        std::cout << "Quicksort successful.\n";
        std::cout << "Time to Quicksort: " << quick_large -> duration << " sec.\n";
    }
    else {
        std::cout << "Sort failed.\n";
    }
    std::cout << "\n";
    return 0;
}
