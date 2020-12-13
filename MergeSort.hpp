//
//  MergeSort.hpp
//  Sorting
//
//  Created by Benjamin Mathews on 12/6/20.
//

#ifndef MergeSort_hpp
#define MergeSort_hpp

#include <stdio.h>
#include <vector>

std::vector<int> mergeSort(std::vector<int> mainList);
void sort(std::vector<int> &mainList);
void merge(std::vector<int> &mainList, std::vector<int> &left, std::vector<int> &right);

#endif /* MergeSort_hpp */
