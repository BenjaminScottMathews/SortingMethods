//
//  RadixSort.cpp
//  Sorting
//
//  Created by Benjamin Mathews on 12/14/20.
//  ------------------------------------------------------------------------------
//  Radix Sort uses counting sort to sort each int by it's least significant digit, second least significant digit, third least signifcant digit...all the way to the most significant digit. Based on the base of the numbers, we can acheive O(n) time for this algorithm if we set the base of our numbers equal to n. I've sorted in base 10, as I'm simply attempting to get the logic of the sorting methods understood. But this algorithm can be used to sort if numbers are in polynomial range.
//  ------------------------------------------------------------------------------
//  ------------------------------------------------------------------------------
//  Time Complexity: O(d(n+k)) --linear time sort-- ** when base == n **
//  ------------------------------------------------------------------------------

#include "RadixSort.hpp"

#include <iostream>
#include <ctime>

using namespace std;

vector<int> radixSort(vector<int> mainList)
{
    clock_t startTime = clock();
    //If the list is empty, it's sorted
    if (mainList.empty()) {return mainList;}
    
    int maxInt = 1000;  //The max int in our vector of random numbers
    int base = 10;   //The base of our numbers
    
    vector<int> counts (base, 0);
    vector<int> auxVector (mainList.size(), 0);
    
    //Loop for each digit (total of 4 digits with max as 1000)
    int divisor = 1;
    while (divisor <= maxInt)
    {
        //Counting sort segment
        for (int num : mainList) {counts[(num/divisor)%base]++;}
        
        //Decrement counts to fix Aux placements
        counts[0]--;
        for (int i=1; i<counts.size(); i++) {counts[i] += counts[i-1];}

        //Insert numbers in order based on digit sorting
        for (int i=mainList.size()-1; i>=0; i--)
        {
            int numCounter = (mainList[i]/divisor)%base;
            auxVector[counts[numCounter]] = mainList[i];
            counts[numCounter]--;
        }
        
        for (int i=0; i<counts.size(); i++) {counts[i] = 0;}
        mainList = auxVector;
        divisor *= 10;
    }
    
    cout << "Radix Sort took: ";
    cout << (clock()-startTime) / (double)CLOCKS_PER_SEC;
    cout << " seconds" << endl;
    
    return auxVector;
}
