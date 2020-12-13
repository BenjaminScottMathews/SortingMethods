//
//  QuickSort.hpp
//  Sorting
//
//  Created by Benjamin Mathews on 12/11/20.
//

#ifndef QuickSort_hpp
#define QuickSort_hpp

#include <stdio.h>
#include <vector>

void quickSort(std::vector<int> &mainList, int low, int high);
int partition(std::vector<int> &subList, int start, int pivot);

#endif /* QuickSort_hpp */
