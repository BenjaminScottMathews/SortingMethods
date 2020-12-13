//
//  HeapSort.hpp
//  Sorting
//
//  Created by Benjamin Mathews on 12/10/20.
//

#ifndef HeapSort_hpp
#define HeapSort_hpp

#include <stdio.h>
#include <vector>

void maxHeapify(std::vector<int> &list, int parent, int length);
void heapSort(std::vector<int> &maxHeap, int heapSize);

#endif /* HeapSort_hpp */
