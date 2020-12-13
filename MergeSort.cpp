//
//  MergeSort.cpp
//  Sorting
//
//  Created by Benjamin Mathews on 12/6/20.
//  ------------------------------------------------------------------------------
//  Merge Sort is a "Divide & Conquer" algorithm. We begin by recursively breaking down our original vector into halves until we get to separate sorted vector. This step takes logn time has we are splitting in half every iteration. Then, we merge our sorted vectors back together in increasing order. This step take n time as we are using every element.
//  ------------------------------------------------------------------------------
//  ------------------------------------------------------------------------------
//  Time Complexity: O(nlogn)
//  ------------------------------------------------------------------------------
#include <iostream>
#include <ctime>

#include "MergeSort.hpp"

using namespace std;

//This method does the dividing of our original vector
vector<int> mergeSort(vector<int> mainList)
{
    clock_t startTime = clock();
    sort(mainList);
    cout << "Merge Sort took: ";
    cout << (clock()-startTime) / (double)CLOCKS_PER_SEC;
    cout << " seconds" << endl;
    return mainList;
}

void sort(vector<int> &mainList)
{
    if (mainList.size() > 1)
    {
        int mid = mainList.size()/2;
        
        //Copy our subvectors into separate vectors
        vector<int> left(mainList.begin(), mainList.begin()+mid);
        vector<int> right(mainList.begin()+mid, mainList.end());
        
        //Call sort with our subvectors, and merge them
        sort (left);
        sort (right);
        merge(mainList, left, right);
    }
}

/*
 * Merge our vectors back together in increasing order
 * @param left: the first half of our list
 * @param right: the second half of our list
 */
void merge(vector<int> &mainList, vector<int> &left, vector<int> &right)
{

    //Length of "sub arrays"
    int lLength, rLength;
    lLength = left.size();
    rLength = right.size();
    
    //Pointers for current smallest value
    int p1, p2, index;
    p1 = p2 = index = 0;
    
    //While we aren't finished with either subvector
    while (p1 < lLength && p2 < rLength)
    {
        if (left[p1] <= right[p2])
        {
            mainList[index] = left[p1];
            p1++;
        }
        else
        {
            mainList[index] = right[p2];
            p2++;
        }
        index++;
    }
    
    //If left subvector has remaining values
    while (p1 < lLength)
    {
        mainList[index] = left[p1];
        p1++;
        index++;
    }
    
    //If right subvector has remaining values
    while (p2 < rLength)
    {
        mainList[index] = right[p2];
        p2++;
        index++;
    }
}





/*
 //Counters for each vector
 int p1, p2;
 p1 = p2 = 0;
 //Index to swap numbers in main vector
 int index = start;
 //Size for each vector
 vector<int> left, right;
 int sizeL, sizeR;
 sizeL = (mid-start)+1;
 sizeR = end-mid;
 
 //Fill two sub arrays with the values were going to compare
 /*
 for (int i=0; i<sizeL; i++) {cout << "Left: " << mainList[start+i] << " ";}//left.push_back(mainList[start+i]);}
 for (int i=0; i<sizeR; i++) {cout << "Right: " << mainList[mid+i] << " ";}//right.push_back(mainList[mid+1+i]);}
 */
 /*
 //Piece back the vectors into a single sorted vector
 while (p1 < sizeL && p2 < sizeR)
 {
     if (mainList[start+p1] <= mainList[mid+p2])
     {
         sortedList[index] = mainList[start+p1];
         p1++;
     }
     else
     {
         sortedList[index] = mainList[mid+p2];
         p2++;
     }
     index++;
 }
 
 //Handle any remaining numbers on the ends of the lists
 while (p2 < sizeR)
 {
     sortedList[index] = mainList[mid+p2];
     p2++;
     index++;
 }
 while (p1 < sizeL)
 {
     sortedList[index] = mainList[start+p1];
     p1++;
     index++;
 }
 
 for (int i=0; i<sortedList.size(); i++)
 {
     cout << sortedList[i] << " ";
 }
 cout << endl;
}
 */




/*
 //Splits our vector into two halves
 if (start < end)
 {
     int mid = (start+end)/2;
     sort(mainList, sortedList, start, mid);
     sort(mainList, sortedList, mid+1, end);
     merge(mainList, sortedList, start, mid, end);
 }
 */
