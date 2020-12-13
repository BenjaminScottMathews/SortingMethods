//
//  QuickSort.cpp
//  Sorting
//
//  Created by Benjamin Mathews on 12/11/20.
//  ------------------------------------------------------------------------------
//  Quick Sort works by first finding a pivot (in our case, its the last value in the vector). We then compare each value to that pivto value in O(n) time, rearranging the vector to have all the smaller values at the beggining, and the larger values at the end. We then correctly move our pivot value. Next, we send each parititoned (lesser and greater values) vectors to be partitioned and sorted. We end up with a sorted vector through divided and conquer.
//  ------------------------------------------------------------------------------
//  ------------------------------------------------------------------------------
//  Time Complexity: O(nlogn)
//  ------------------------------------------------------------------------------

#include "QuickSort.hpp"

#include <ctime>

using namespace std;

void quickSort(vector<int> &mainList, int low, int high)
{
    //Base Case - We've paritioned the entire vector
    if (low < high)
    {
        //Make the pivot the last value in the vector (aka: high)
        int splitIndex = partition(mainList, low, high);
        
        quickSort(mainList, low, splitIndex-1);
        quickSort(mainList, splitIndex+1, high);
    }
}

int partition(vector<int> &subList, int start, int pivot)
{
    int pivotVal = subList[pivot];
    int smallest = start-1;
    
    //Loop through vector to partition around pivot
    for (int i=start; i<pivot; i++)
    {
        //If the value < our partition, swap it to the "smaller numbers" portion of the vector
        if (subList[i] < pivotVal)
        {
            smallest++;
            int temp = subList[smallest];
            subList[smallest] = subList[i];
            subList[i] = temp;
        }
    }
    
    //Swap partition to it's correct placement
    smallest++;
    subList[pivot] = subList[smallest];
    subList[smallest] = pivotVal;
    
    return smallest;
    
}
