// MergeSort.cpp
//  
// Sample Code found at  
// https://www.programming-techniques.com/2011/12/data-structure-how-to-implement-merge.html 
//
//#include "MergeSort.hpp"

#include<iostream>
using namespace std;

//create a class MergeSort
class MergeSort{
    public:
        int no_of_elements;
        int elements[10];
    public:
        void getarray();
        void partition(int [] ,int ,int);
        void sortit(int [], int , int, int);
        void display();
};

// get the array to be sorted from the user
void MergeSort::getarray(){
    cout<<"How many elements?: ";
    cin>>no_of_elements;
    cout<<"Insert elements to sort: ";
    for(int i=0;i<no_of_elements;i++){
        cin>>elements[i];
    }
}

// recursively divide the array into sub arrays until all sub
// arrays contain only one element
void MergeSort::partition(int elements[], int low, int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        // sort the left sub array
        partition(elements,low,mid);

        // sort the right sub array
        partition(elements,mid+1,high);


        sortit(elements,low,mid,high);

    }
}
void MergeSort::sortit(int elements[], int low, int mid, int high){
    int i,j,k,l,b[20];
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
    MergeSort MS;
    MS.getarray();
    MS.partition(MS.elements,0,MS.no_of_elements);
    MS.display();
    return 0;
}
