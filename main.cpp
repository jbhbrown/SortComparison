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

int main(int argc, const char * argv[]) {
    std::cout << "starting\n";
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
    
    return 0;
}
