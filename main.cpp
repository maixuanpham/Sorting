//
//  main.cpp
//  Project_2
//
//  Created by Mai Pham on 4/14/18.
//  Copyright © 2018 Mai Pham. All rights reserved.
//

#include "Entry.h"
#include "Sorting.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

template <typename E>
void print1st20(vector<E> S) {
    for (int i = 0; i < 20; i++)
        cout << S[i].key() << "  " ;
}

template <typename E>
void printLast20(vector<E> S) {
    int b = S.size();
    int a = b - 21;
    for (int i = a; i < b; i++)
        cout << S[i].key() << "  " ;
}
template <typename E>
void printInfor(ofstream &outputFile, string methor, string fileName, int num, string data, vector <E>S, Sorting <E>sort)   {
    outputFile << "Sorting Method = " << methor << endl;
    outputFile << "Input File Name = " << fileName << endl;
    outputFile << "Number of Values Sorted = " << num << endl;
    outputFile << "Sorted Key Data Type = " << data << endl;
    outputFile << "Number of Key Compares = " << sort.getCompares()<< endl;
    outputFile << "Number of Data Moves = " << sort.getDataMoves() << endl;
    outputFile << "Times in Milliseconds = " << sort.getMilliSeconds() << endl;
    outputFile << "First 5 pairs:" << endl;
    for (int i = 0; i < 5; i++)
        outputFile << "\t(" << S[i].key() << ", " << S[i].value() << ")   ";
        
    outputFile << "\nLast 5 pairs:" << endl;
    for (int i = S.size()-5; i < S.size(); i++)
        outputFile << "\t(" << S[i].key() << ", " << S[i].value() << ")   ";
    outputFile << endl << endl;
}

int main() {
    vector<Entry<int, string>> vect1kInt;
    vector<Entry<string, int>> vect1kString;
    vector<Entry<int, string>> vect100kInt;
    vector<Entry<string, int>> vect100kString;
    Sorting <Entry<int, string>> sortInt;
    Sorting <Entry<string, int>> sortString;
    
    int key;
    string value;
    
    ifstream mySmallList;
    mySmallList.open("small1k.txt");
    if(!mySmallList.is_open())
        cout << "No text file found. " << endl;
    
    while (mySmallList >> key)   {
        value = to_string(key);
        
        Entry<int, string> entryNum;
        entryNum.setKey(key);
        entryNum.setValue(value);
        vect1kInt.push_back(entryNum);
        
        Entry<string, int> entryWord;
        entryWord.setKey(value);
        entryWord.setValue(key);
        vect1kString.push_back(entryWord);
    }
    
    ifstream myLargeList;
    myLargeList.open("large100k.txt");
    if(!myLargeList.is_open())
        cout << "No text file found. " << endl;
    
    while (myLargeList >> key)   {
        value = to_string(key);
        
        Entry<int, string> entryNum;
        entryNum.setKey(key);
        entryNum.setValue(value);
        vect100kInt.push_back(entryNum);
        
        Entry<string, int> entryWord;
        entryWord.setKey(value);
        entryWord.setValue(key);
        vect100kString.push_back(entryWord);
    }
    
    ofstream outputFile;
    outputFile.open("p2Results.txt");
    
    
    // Small 1k Integer Sort
    vector<Entry<int, string>> selectionSort1kInt;
    selectionSort1kInt = vect1kInt;
    sortInt.selectionSort(selectionSort1kInt);
    printInfor(outputFile, "Selection Sort", "small1k.txt", 1000, "Integer", selectionSort1kInt, sortInt);
    
    vector<Entry<int, string>> insertionSort1kInt;
    insertionSort1kInt = vect1kInt;
    sortInt.insertionSort(insertionSort1kInt);
    printInfor(outputFile, "Insertion Sort", "small1k.txt", 1000, "Integer", insertionSort1kInt, sortInt);
    
    vector<Entry<int, string>> mergeSort1kInt;
    mergeSort1kInt = vect1kInt;
    sortInt.mergeSort(mergeSort1kInt);
    printInfor(outputFile, "Merge Sort", "small1k.txt", 1000, "Integer", mergeSort1kInt, sortInt);
    
    vector<Entry<int, string>> quickSort1kInt;
    quickSort1kInt = vect1kInt;
    sortInt.quickSort(quickSort1kInt);
    printInfor(outputFile, "Quick Sort", "small1k.txt", 1000, "Integer", quickSort1kInt, sortInt);
    
    vector<Entry<int, string>> shellSort1kInt;
    shellSort1kInt = vect1kInt;
    sortInt.shellSort(shellSort1kInt);
    printInfor(outputFile, "Shell Sort", "small1k.txt", 1000, "Integer", shellSort1kInt, sortInt);

    vector<Entry<int, string>> radixSort1kInt;
    radixSort1kInt = vect1kInt;
    sortInt.radixSort(radixSort1kInt);
    printInfor(outputFile, "Radix Sort", "small1k.txt", 1000, "Integer", radixSort1kInt, sortInt);
    
    
    // Small 1k String Sort
    vector<Entry<string, int>> selectionSort1kString;
    selectionSort1kString = vect1kString;
    sortString.selectionSort(selectionSort1kString);
    printInfor(outputFile, "Selection Sort", "small1k.txt", 1000, "String", selectionSort1kString, sortString);
    
    vector<Entry<string, int>> insertionSort1kString;
    insertionSort1kString = vect1kString;
    sortString.insertionSort(insertionSort1kString);
    printInfor(outputFile, "Insertion Sort", "small1k.txt", 1000, "String", insertionSort1kString, sortString);
    
    vector<Entry<string, int>> mergeSort1kString;
    mergeSort1kString = vect1kString;
    sortString.mergeSort(mergeSort1kString);
    printInfor(outputFile, "Merge Sort", "small1k.txt", 1000, "String", mergeSort1kString, sortString);
    
    vector<Entry<string, int>> quickSort1kString;
    quickSort1kString = vect1kString;
    sortString.quickSort(quickSort1kString);
    printInfor(outputFile, "Quick Sort", "small1k.txt", 1000, "String", quickSort1kString, sortString);
    
    vector<Entry<string, int>> shellSort1kString;
    shellSort1kString = vect1kString;
    sortString.shellSort(shellSort1kString);
    printInfor(outputFile, "Shell Sort", "small1k.txt", 1000, "String", shellSort1kString, sortString);
    /*
    vector<Entry<string, int>> radixSort1kString;
    radixSort1kString = vect1kString;
    sortString.radixSort(radixSort1kString);
    printInfor(outputFile, "Radix Sort", "small1k.txt", 1000, "String", radixSort1kString, sortString);
    */
    
    
    // Large 1k Integer Sort
    vector<Entry<int, string>> mergeSort100kInt;
    mergeSort100kInt = vect100kInt;
    sortInt.mergeSort(mergeSort100kInt);
    printInfor(outputFile, "Merge Sort", "large100k.txt", 1000000, "Integer", mergeSort100kInt, sortInt);
    
    vector<Entry<int, string>> quickSort100kInt;
    quickSort100kInt = vect100kInt;
    sortInt.quickSort(quickSort100kInt);
    printInfor(outputFile, "Quick Sort", "large100k.txt", 1000000, "Integer", quickSort100kInt, sortInt);
    
    vector<Entry<int, string>> sellSort100kInt;
    sellSort100kInt = vect100kInt;
    sortInt.shellSort(sellSort100kInt);
    printInfor(outputFile, "Shell Sort", "large100k.txt", 1000000, "Integer", sellSort100kInt, sortInt);
    
    vector<Entry<int, string>> radixSort100kInt;
    radixSort100kInt = vect100kInt;
    sortInt.radixSort(radixSort100kInt);
    printInfor(outputFile, "Radix Sort", "large100k.txt", 1000000, "Integer", radixSort100kInt, sortInt);
    
    
    // Large 1k String Sort
    vector<Entry<string, int>> mergeSort100kString;
    mergeSort100kString = vect100kString;
    sortString.mergeSort(mergeSort100kString);
    printInfor(outputFile, "Merge Sort", "large100k.txt", 1000000, "String", mergeSort100kString, sortString);
    
    vector<Entry<string, int>> quickSort100kString;
    quickSort100kString = vect100kString;
    sortString.quickSort(quickSort100kString);
    printInfor(outputFile, "Quick Sort", "small1k.txt", 1000000, "String", quickSort100kString, sortString);
    
    vector<Entry<string, int>> shellSort100kString;
    shellSort100kString = vect100kString;
    sortString.shellSort(shellSort100kString);
    printInfor(outputFile, "Shell Sort", "small1k.txt", 1000000, "String", shellSort100kString, sortString);
    /*
    vector<Entry<string, int>> raidxSort100kString;
    raidxSort100kString = vect100kString;
    sortString.radixSort(raidxSort100kString);
    printInfor(outputFile, "Radix Sort", "small1k.txt", 1000000, "String", raidxSort100kString, sortString);
    */
    
    outputFile.close();
    return 0;
}

