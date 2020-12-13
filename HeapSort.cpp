//
//  HeapSort.cpp
//  Sorting
//
//  Created by Benjamin Mathews on 12/10/20.
//  ------------------------------------------------------------------------------
//  Heap Sort works by representing our vector as a heap, where, starting at index 0, each parent is at index i+1, the parent's left child is at (i+1)*2-1 and the right child is at (i+1)*2. With this information, we can form our vector into a max heap, taking O(n) time as we only do a maximum of logn work for our top layer, and do less and less work as we move further from the root, ending with constant time work at our leaves/smallest subtrees. Then, with our max heap, we swap first and last nodes, then heapify the root node again, only considering the heap up to but not including the last node (which is our current largest element). This will end with the array being sorted.
//  ------------------------------------------------------------------------------
//  ------------------------------------------------------------------------------
//  Time Complexity: O(nlogn)
//  ------------------------------------------------------------------------------


#include "HeapSort.hpp"

using namespace std;

/*
 * Turns a heap vector into a max heap by starting at the bottom and making each sub tree a max heap, recursively moving up through the heap.
 * This method also rearranges our vector that holds our list of numbers that the heap is created from
 */
void maxHeapify(vector<int> &list, int parent, int length)
{
    //Base Case - We are at the root
    if (parent > length/2) {return;}
    
    int maxIndex;
    int rootVal = list[parent-1];
    
    //Find the large child
    if (list[(parent*2)-1] > list[parent*2]) {maxIndex = (parent*2)-1;}
    else {maxIndex = parent*2;}
    
    //Swap nodes if larger than root
    if (rootVal < list[maxIndex])
    {
        list[parent-1] = list[maxIndex];
        list[maxIndex] = rootVal;
        
        //Recursively heapify the lower nodes (lower == farther from root)
        maxHeapify(list, maxIndex+1, length);
    }
}

/*
 * Sorts our maxHeap by swapping first and last items, then heapifying the root.
 */
void heapSort(vector<int> &maxHeap, int heapSize)
{
    //Base Case: We considered all values and sub trees
    if (heapSize <= 1) {return;}
    
    //Swap first and last values
    int lastVal = maxHeap[heapSize-1];
    maxHeap[heapSize-1] = maxHeap[0];
    maxHeap[0] = lastVal;
        
    //Heapify the root of the tree
    maxHeapify(maxHeap, 1, heapSize-2);
    heapSort(maxHeap, heapSize-1);
}
