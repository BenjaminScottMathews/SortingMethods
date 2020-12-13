//
//  SelectionSort.cpp
//  Sorting
//
//  Created by Benjamin Mathews on 12/5/20.
//  ------------------------------------------------------------------------------
//  Selection Sort works by looping through the entire vector to find the smallest element. Then, that element is swapped to the first position. This process is completed for each position in the vector until we have a sorted list.
//  ------------------------------------------------------------------------------
//  ------------------------------------------------------------------------------
//  Time Complexity: O(n^2)
//  ------------------------------------------------------------------------------

#include "SelectionSort.hpp"

#include <iostream>
#include <ctime>

using namespace std;

vector<int> selectionSort(vector<int> mainList)
{
    clock_t startTime = clock();
    
    //If the list length is 0 or 1, the list is sorted
    if (mainList.size() == 0 || mainList.size() == 1) {return mainList;}
    
    //Outer for loop to scan the entire vector for each sort pass
    for (int i=0; i<mainList.size(); i++)
    {
        int tempMin = mainList[i];
        int tempIndex = i;
        
        //Inner loop to find smallest number
        for (int j=i+1; j<mainList.size(); j++)
        {
            if(mainList[j] < tempMin)
            {
                tempMin = mainList[j];
                tempIndex = j;
            }
        }
        mainList[tempIndex] = mainList[i];
        mainList[i] = tempMin;
    }
    
    cout << "Selection Sort took: ";
    cout << (clock()-startTime) / (double)CLOCKS_PER_SEC;
    cout << " seconds" << endl;
    
    return mainList;
}
