// MergeSort.cpp
//
// Sample Code found at
// https://www.programming-techniques.com/2011/12/data-structure-how-to-implement-merge.html
//
//#include "MergeSort.hpp"

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//create a class MergeSort
class MergeSort{
public:
    int no_of_elements;
    //int elements[];
    std::vector <int> elements;
public:
    void getarray(std::vector<int>);
    void partition(std::vector<int> ,int ,int);
    void sortit(std::vector<int>, int , int, int);
    void display();
};

// get the array to be sorted from the user
void MergeSort::getarray(std::vector<int> vec){
    no_of_elements = int(vec.size())-1;
    for(int i=0; i<no_of_elements; i++){
        elements.push_back(vec[i]);
    }
}

// recursively divide the array into sub arrays until all sub
// arrays contain only one element
void MergeSort::partition(std::vector<int> elements, int low, int high){
    int mid;
    if(low<high){
        mid=int(low+high)/2;
        // sort the left sub array
        partition(elements,low,mid);
        
        // sort the right sub array
        partition(elements,mid+1,high);
        
        
        sortit(elements,low,mid,high);
        
    }
}
void MergeSort::sortit(std::vector<int> elements, int low, int mid, int high){
    int i,j,k,l/*,b[20]*/;
    vector<int> b ;
    b.reserve(elements.size()*2);
    l=low;
    i=low;
    j=mid+1;
    while((l<=mid)&&(j<=high)){
        if(elements[l]<=elements[j]){
            b[i]=elements[l];
            l++;
        }else{
            b[i]=elements[j];
            j++;
        }
        i++;
    }
    if(l>mid){
        for(k=j;k<=high;k++){
            b[i]=elements[k];
            i++;
        }
    }else{
        for(k=l;k<=mid;k++){
            b[i]=elements[k];
            i++;
        }
    }
    for(k=low;k<=high;k++){
        elements[k]=b[k];
    }
}
void MergeSort::display(){
    cout<<"The sorted element is\n";
    for(int i = 0 ; i < no_of_elements; i++){
        cout<<elements[i]<<" ";
    }
}

int main(){
    /* small dataset -- 504 ints */
    int elCount = 0;
    std::vector <int> vec;
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
    
    
    
    /* large dataset -- 3000 ints -- "diabetic_data.csv" */
    /*
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
     */
    
    
    /* array1 */
    MergeSort MS;
    MS.getarray(vec);
    MS.partition(MS.elements,0,MS.no_of_elements);
    MS.display();
    
    /* array2 */
    return 0;
}

