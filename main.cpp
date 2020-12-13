//
//  main.cpp
//  Sorting
//
//  Created by Benjamin Mathews on 12/5/20.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>

#include "SelectionSort.hpp"
#include "InsertionSort.hpp"
#include "MergeSort.hpp"
#include "HeapSort.hpp"
#include "QuickSort.hpp"

using namespace std;

void printList(vector<int> mainList);
void getInputMethod(vector<int> &mainList);
void manualInput(vector<int> &mainList);
void readFromFile(vector<int> &mainList);

void callSort(vector<int> &mainList);

int main()
{
    vector<int> mainList; //This will be our unsorted array
    
    getInputMethod(mainList);
    callSort(mainList);
    
    return 0;
}

/*
 * Ask for and process user input to form unsorted vector
 * @param mainList: the vector that holds our unsorted numbers
 */
void getInputMethod(vector<int> &mainList)
{
    //Check whether we are using a file or manual entry
    cout << "Read from File ('f') or Manual Input ('m'): ";
    
    string inputCommand;
    cin >> inputCommand;
    
    if (inputCommand == "m")
    {
        manualInput(mainList);
    }
    else if (inputCommand == "f")
    {
        readFromFile(mainList);
    }
}

/*
 * This function manually reads in numbers from user input to sort
 */
void manualInput(vector<int> &mainList)
{
    //User Input to read numbers into array
    cout << endl;
    cout << "Please list numbers for your list." << endl;
    cout << "Type 'f' when finished: ";
    
    int num;
    while (cin >> num)
    {
        mainList.push_back(num);
    }
    
    cin.clear();
    cin.ignore();
}

/*
 * This function reads in inputs from a file and inserts them into our vector
 */
void readFromFile(vector<int> &mainList)
{
    //Ask for the file name
    string inputFile;
    cout << "Filename: ";
    cin >> inputFile;
    
    //Take each number and add it to the vector
    int num;
    ifstream myFile (inputFile);
    while (myFile >> num)
    {
        mainList.push_back(num);
    }
}

/*
 * Process sorting method to use and call that sort
 */
void callSort(vector<int> &mainList)
{
    //Choose a sorting method
    cout << endl;
    cout << "---Choose Your Sort---" << endl;
    cout << "Selection: 'selection'" << endl;
    cout << "Insertion: 'insertion'" << endl;
    cout << "Merge: 'merge'" << endl;
    cout << "Heap: 'heap'" << endl;
    cout << "Quick: 'quick'" << endl;
    
    cout << endl;
    cout << "--------Print---------" << endl;
    cout << "Print Unsorted: 'print'" << endl;
    cout << "Print Selection Sorted: 'printS'" << endl;
    cout << "Print Insertion Sorted: 'printI'" << endl;
    cout << "Print Merge Sorted: 'printM'" << endl;
    cout << "Print Heap Sorted: 'printH'" << endl;
    cout << "Print Quick Sorted: 'printQ'" << endl;
    
    cout << endl;
    cout << "---------Quit---------" << endl;
    cout << "Quit: 'quit" << endl;
    
    string inputSort;
    vector<int> selectionVector;
    vector<int> insertionVector;
    vector<int> mergeVector;
    vector<int> heapVector;
    vector<int> quickVector;
    
    cout << "Command: ";
    while (cin >> inputSort)
    {
        if (inputSort == "selection") {selectionVector = selectionSort(mainList);}
        else if (inputSort == "insertion"){insertionVector = insertionSort(mainList);}
        else if (inputSort == "merge") {mergeVector = mergeSort(mainList);}
        else if (inputSort == "heap")
        {
            clock_t startTime = clock();
            heapVector = mainList;
            //Build our maxHeap using maxHeapify
            for (int i=heapVector.size()/2; i>0; i--)
            {
                maxHeapify(heapVector, i, heapVector.size());
            }
            heapSort(heapVector, heapVector.size());
            cout << "Heap Sort took: ";
            cout << (clock()-startTime) / (double)CLOCKS_PER_SEC;
            cout << " seconds" << endl;
        }
        else if (inputSort == "quick")
        {
            clock_t startTime = clock();
            quickVector = mainList;
            quickSort(quickVector, 0, quickVector.size()-1);
            cout << "Quick Sort took: ";
            cout << (clock()-startTime) / (double)CLOCKS_PER_SEC;
            cout << " seconds" << endl;
        }
        else if (inputSort == "print") {printList(mainList);}
        else if (inputSort == "printS")
        {
            if (selectionVector.empty()) {cout << "Please sort first" << endl;}
            else {printList(selectionVector);}
        }
        else if (inputSort == "printI")
        {
            if (insertionVector.empty()) {cout << "Please sort first" << endl;}
            else {printList(insertionVector);}
        }
        else if (inputSort == "printM")
        {
            if (mergeVector.empty()) {cout << "Please sort first" << endl;}
            else {printList(mergeVector);}
        }
        else if (inputSort == "printH")
        {
            if (heapVector.empty()) {cout << "Please sort first" << endl;}
            else {printList(heapVector);}
        }
        else if (inputSort == "printQ")
        {
            if (quickVector.empty()) {cout << "Please sort first" << endl;}
            else {printList(quickVector);}
        }
        else if (inputSort == "quit") {break;}
        else {cout << "Command not recognized. Try again." << endl;}
        cout << "Command: ";
    }
   
}

/*
 * Method to print the elements of our vector from (0->n)
 */
void printList(vector<int> mainList)
{
    for (int i: mainList)
    {
        cout << i << " ";
    }
    cout << endl;
}
