//
//  CountingSort.cpp
//  Sorting
//
//  Created by Benjamin Mathews on 12/14/20.
//  ------------------------------------------------------------------------------
//  Counting Sort counts total occurrances of each integer, and increments that index in a separate vector which is the size of the largest int in our numList (which I chose to be 1000). We then cycle through that vector to form a new vector based on the sorted occurrances. Time complexity is really O(n+k), and since k is 1000, in sorts over 1000, we get linear time.
//  ------------------------------------------------------------------------------
//  ------------------------------------------------------------------------------
//  Time Complexity: O(n+k) --linear time sort--
//  ------------------------------------------------------------------------------

#include "CountingSort.hpp"

#include <ctime>
#include <iostream>

using namespace std;

//Counts occurrances of each int in our list and returns the sorted list
vector<int> countingSort(const vector<int> &mainList)
{
    clock_t startTime = clock();
    
    int maxInt = 1000; //The max integer in our list of integers
    vector<int> sortedOccurances (maxInt, 0);
    
    //Increment the vector value by one in our occurrance vector
    for (int i=0; i<mainList.size(); i++)
    {
        sortedOccurances[mainList[i]]++;
    }
    
    //Fill a new vector with our sorted numbers
    vector<int> sortedList;
    for (int i=0; i<sortedOccurances.size(); i++)
    {
        while (sortedOccurances[i] > 0)
        {
            sortedList.push_back(i);
            sortedOccurances[i]--;
        }
    }
    cout << "Counting Sort took: ";
    cout << (clock()-startTime) / (double)CLOCKS_PER_SEC;
    cout << " seconds" << endl;
    
    return sortedList;
}


