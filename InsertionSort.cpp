//
//  InsertionSort.cpp
//  Sorting
//
//  Created by Benjamin Mathews on 12/6/20.
//  ------------------------------------------------------------------------------
//  Insertion Sort starts with a key (element at specific location). Each key is compared with the sorted section to its left, making pairwise swaps until the key is in its correct position.
//  ------------------------------------------------------------------------------
//  ------------------------------------------------------------------------------
//  Time Complexity: O(n^2)
//  ------------------------------------------------------------------------------

#include <iostream>
#include <ctime>

#include "InsertionSort.hpp"

using namespace std;

vector<int> insertionSort(vector<int> mainList)
{
    clock_t startTime = clock();
    
    //If size is 0 or 1, the list is sorted
    if (mainList.size() == 0 || mainList.size() == 1) {return mainList;}
    
    //Begin pairwise comparisons
    for (int i=0; i<mainList.size(); i++)
    {
        int key = i;
        int keyVal = mainList[i];
        while (key > 0 && keyVal < mainList[key-1])
        {
            mainList[key] = mainList[key-1];
            mainList[key-1] = keyVal;
            key--;
        }
    }
    
    cout << "Insertion Sort took: ";
    cout << (clock()-startTime) / (double)CLOCKS_PER_SEC;
    cout << " seconds" << endl;
    
    return mainList;
}
