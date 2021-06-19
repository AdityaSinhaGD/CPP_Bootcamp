//
//  main.cpp
//  CPP_Bootcamp
//
//  Created by Aditya Sinha on 02/06/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "NQueens.hpp"
#include "GraphColoring.hpp"
#include "FibonacciMemoize.hpp"
#include "Sorting/MergeSort.hpp"
#include "LinkedList/LinkedList.h"

void Hanoi(int noOfDisks, char TowerSource, char TowerDestination, char TowerAux)
{
    //Base case if there is only 1 disk. Then we simply move the disk from A to C.
    if(noOfDisks == 1){
        std::cout<<"Move disk "<<noOfDisks<<" from Tower "<<TowerSource<<" to Tower "<<TowerDestination<<std::endl;
        return;
    }
    Hanoi(noOfDisks-1, TowerSource, TowerAux, TowerDestination);
    std::cout<<"Move disk "<<noOfDisks<<" from Tower "<<TowerSource<<" to Tower "<<TowerDestination<<std::endl;
    Hanoi(noOfDisks-1, TowerAux, TowerDestination, TowerSource);
}

int Factorial(int n){
    if(n==1){
        return 1;
    }
    int m = Factorial(n-1);
    return n*m;
}

bool Palindrome(std::string name)
{
    if(name.size()<=1)
    {
        return true;
    }
    else
    {
        if(name[0]==name[name.size()-1])
        {
            return Palindrome(name.substr(1,name.size()-2));
        }
        else
        {
            return  false;
        }
    }
    
}

int sumOfDigits(int num){
    if(num<10){
        return num;
    }
    int sum = num%10+sumOfDigits(num/10);
    return sum;
}

int binarySearch(int nums[], int value, int low, int high){
    
    if(low>high){
        return -1;
    }
    
    int mid = low+(high-low)/2;
    
    if(value==nums[mid]){
        return mid;
    }
    
    if(value>nums[mid]){
        return binarySearch(nums, value, mid+1, high);
    }else{
        return binarySearch(nums, value, low, mid-1);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    //Hanoi(3, 'A', 'C', 'S');
    //std::cout<<Factorial(5);
    //std::cout<<Palindrome("raddars")<<"\n";
    //std::cout<<sumOfDigits(157)<<"\n";
    
    //int nums[]={1,3,4,6,7,8};
    //std::cout<<binarySearch(nums, 8, 0, 5)<<std::endl;
    
    //QueensProblem queensProblem{4};
    //queensProblem.solve();
    
    /*std::vector<std::vector<int>> adjacencyMatrix={
        {0,1,0,1,0},
        {1,0,1,1,0},
        {0,1,0,1,0},
        {1,1,1,0,1},
        {0,0,0,1,0}
    };
    GraphColoring graphColoring(adjacencyMatrix,3);
    graphColoring.solve();*/
    
    //FibonacciMemoize fibonacci;
    //std::cout<<fibonacci.FibonacciResult(60)<<"\n";
    
    /*std::vector<int> vect ={5,1,2,-9,30,300,-600,14};
    MergeSort mergeSrt;
    mergeSrt.MergeSortImpl(vect);
    
    for (int i=0; i<vect.size(); i++) {
        std::cout<<vect[i]<<"->";
    }*/
    
    std::unique_ptr<List<int>> linkedList = std::make_unique<LinkedList<int>>();
    linkedList->push(5);
    linkedList->push(10);
    linkedList->push(15);
    linkedList->push(25);
    
    linkedList->remove(15);
    linkedList->traverseList();

    
    return 0;
}
