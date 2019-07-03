//
//  Sorting.h
//  Project_2
//
//  Created by Mai Pham on 4/14/18.
//  Copyright © 2018 Mai Pham. All rights reserved.
//

#ifndef Sorting_h
#define Sorting_h

#include "Comparator.h"
#include "Entry.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

template <typename E>
class Sorting   {
private:
    unsigned int compares;
    unsigned int dataMoves;
    double milliSeconds;
    LeftRight <E>less;
public:
    Sorting()   {
        compares = 0;
        dataMoves = 0;
        milliSeconds = 0;
    }
    int getCompares()
    {   return compares;    }
    int getDataMoves ()
    {   return dataMoves;    }
    double getMilliSeconds ()
    {   return milliSeconds;    }
    
    void selectionSort(vector<E> &S);
    void insertionSort(vector<E> &S);
    void mergeSort(vector<E> &S);
    void merge(vector<E> &in, vector<E> &out, int b, int m);
    void quickSort(vector<E> &S);
    void quickSortStep(vector<E> &S, int a, int b);
    void findMedian(vector<E> &S);
    void shellSort(vector<E> &S);
    void radixSort(vector<E> &S);
};

template <typename E>
void Sorting<E>::selectionSort(vector<E> &S)   {
    int t1 = clock();
    compares = dataMoves = 0;
    int min;
    for(int i = 0; i < S.size(); i++)   {
        min = i;
        for(int j = i+1; j < S.size(); j++) {
            if( S[j].key() < S[min].key() )
                min = j;
            compares++;
        }
        swap(S[i], S[min]);
        dataMoves += 3;
    }
    int t2 = clock();
    milliSeconds = (t2-t1)/ (double)CLOCKS_PER_SEC*1000;
}

template <typename E>
void Sorting<E>::insertionSort(vector<E> &S) {
    int t1 = clock();
    compares = dataMoves = 0;
    int i,j;
    for (i = 1; i < S.size(); i++) {
        j = i;
        while (j > 0 && S[j - 1].key() > S[j].key()) {
            compares++;
            swap(S[j-1], S[j]);
            dataMoves += 3;
            j--;
        }
        compares++;
    }
    int t2 = clock();
    milliSeconds = (t2-t1)/ (double)CLOCKS_PER_SEC*1000;
}

template <typename E>                                       // merge-sort S
void Sorting<E>::mergeSort(vector<E> &S) {
    int t1 = clock();
    compares = dataMoves = 0;
    typedef vector<E> vect;
    int n = S.size();
    vect v1(S);  vect* in = &v1;                            // initial input vector
    vect v2(n);  vect* out = &v2;                           // initial output vector
    for (int m = 1; m < n; m *= 2) {                        // list sizes doubling
        for (int b = 0; b < n; b += 2*m) {                  // beginning of list
            merge(*in, *out, b, m);                         // merge sublists
        }
        swap(in, out);                                      // swap input with output
        dataMoves+=3;
    }
    S = *in;                                                // copy sorted array to S
    int t2 = clock();
    milliSeconds = (t2-t1)/ (double)CLOCKS_PER_SEC*1000;
}

template <typename E>
void Sorting<E>::merge(vector<E> &in, vector<E> &out, int b, int m) {
    int i = b;                                              // index into run #1
    int j = b + m;                                          // index into run #2
    int n = in.size();
    int e1 = min(b + m, n);                                 // end of run #1
    int e2 = min(b + 2*m, n);                               // end of run #2
    int k = b;
    //compares++;
    while ((i < e1) && (j < e2)) {
        //compares++;
        if(!less(in[j].key(), in[i].key()))                 // append smaller to S
            out[k++] = in[i++];
        else
            out[k++] = in[j++];
   
        dataMoves++;
        compares++;
    }
    //compares++;
    while (i < e1)  {                                          // copy rest of run 1 to S
        out[k++] = in[i++];
        dataMoves++;
        //compares++;
    }
    //compares++;
    while (j < e2){                                          // copy rest of run 2 to S
        out[k++] = in[j++];
        dataMoves++;
        //compares++;
    }
    //compares++;
}

template <typename E>                                       // quick-sort S
void Sorting<E>::quickSort(vector<E> &S) {
    int t1 = clock();
    compares = dataMoves = 0;
    if (S.size() <= 1) return;                              // already sorted
    quickSortStep(S, 0, S.size()-1);                        // call sort utility
    int t2 = clock();
    milliSeconds = (t2-t1)/ (double)CLOCKS_PER_SEC*1000;
}

template <typename E>
void Sorting<E>::quickSortStep(vector<E> &S, int a, int b) {
    if (a >= b) return;                                     // 0 or 1 left? done
    findMedian(S);
    E pivot = S[b];                                         // select last as pivot
    int l = a;                                              // left edge
    int r = b - 1;                                          // right edge
    //compares++;
    while (l <= r) {
        while (l <= r && !less(pivot.key(), S[l].key()))    {
            l++;                // scan right till larger
            compares++;
        }
        compares++;
        while (r >= l && !less(S[r].key(), pivot.key()))    {
            r--;               // scan left till smaller
            compares++;
        }
        compares++;
        if (l < r)  {                                       // both elements found
            swap(S[l], S[r]);
            dataMoves += 3;
        }
        //compares++;
    }                                                       // until indices cross
    swap(S[l], S[b]);                                       // store pivot at l
    dataMoves+=3;
    quickSortStep(S, a, l-1);                               // recur on both sides
    quickSortStep(S, l+1, b);
}

template <typename E>
void Sorting<E>::findMedian(vector<E> &S) {
    int a = 0;
    int c = S.size()-1;
    int b = S.size()/2;
    compares++;
    if (S[a].key() > S[b].key())    {
        if (S[b].key() > S[c].key())    {
            swap(S[b], S[c]);
            dataMoves += 3;
        }
        else if (S[c].key() > S[a].key())   {
            swap(S[a], S[c]);
            dataMoves += 3;
        }
        compares+=2;
    }
    else    {
        if (S[b].key() < S[c].key())    {
            swap(S[b], S[c]);
            dataMoves += 3;
        }
        else if (S[c].key() < S[a].key())   {
            swap(S[a], S[c]);
            dataMoves += 3;
        }
        compares+=2;
    }
}

template <typename E>
void Sorting<E>::shellSort(vector<E> &S)    {
    int t1 = clock();
    compares = dataMoves = 0;
    for (int i = S.size()/2; i > 0; i /=2)  {
        for (int j = i; j < S.size(); j++)  {
            for (int k = j - i; k >= 0; k -= i)  {
                if (S[k].key() > S[k+i].key())    {
                    swap(S[k+i],S[k]);
                    dataMoves+=3;
                }
                compares++;
            }
        }
    }
    int t2 = clock();
    milliSeconds = (t2-t1)/ (double)CLOCKS_PER_SEC*1000;
}

template <typename E>
void Sorting<E>::radixSort(vector<E> &S)    {
    int t1 = clock();
    compares = dataMoves = 0;
    E arr[S.size()];
    
    // get max to compute amount of loop
    E max = S[0];
    for (int i = 1; i < S.size(); i++)
        if (S[i].key() > max.key())
            max = S[i];
    /*
    int num;
    if (isdigit(max.key()))
        num = max.key();
    else
        num = std::atoi(max.key());
    //int num = max.key().length();
     */
    
    for (int position = 1; max.key()/position > 0; position *= 10)  {
        int count[10] = {0};
        for (int i = 0; i < S.size(); i++)
            count[(S[i].key()/position)%10]++;
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];
        for (int i = S.size() - 1; i >= 0; i--) {
            arr [count[(S[i].key()/position) % 10]-1] = S[i];
            count[(S[i].key()/position) % 10]--;
        }
        
        vector<E> temp;
        for (int i = 0; i < S.size(); i++)
            temp.push_back(arr[i]);
        S = temp;
    }
    int t2 = clock();
    milliSeconds = (t2-t1)/ (double)CLOCKS_PER_SEC*1000;
}

#endif /* Sorting_h */
