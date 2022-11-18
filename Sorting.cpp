//

// Created by Lenovo on 10/31/2022.
//
#include "bits/stdc++.h"

using namespace std;
using namespace std::chrono;

void print(const vector<int>& a) {
    for(auto i : a)
        cout << i << " ";
    cout << endl;
}
void bubbleSort(vector<int> a) {
///     It compares each array items next to it and swaps accordingly
///     Hence the highest/ lowest element is pushed to last index. This process is repeated till every element of the array item is checked
    for(auto i : a) {
        for(int j = 0; j < a.size() - i; i++) {
            if(i < a[j])
                swap(i,a[j]);// "<" descending order / ">" ascending order
        }
    }
    print(a);
}
void selectionSort(vector<int> a) {
    /// Selection sort chose the min element in the array and replaces it with first index by swapping it with the  compared value/
    /// Loop runs from 0 to n-2 as last element will be largest at the end of the code
    /// By now the least element is in first position
    /// This is repeated till the largest item is in last position
    for(int i = 0; i < a.size() - 1; i++) {
        int minindex = i;

        for(int j = i+1; j < a.size(); j++) {
            if(a[j] < a[minindex])
                minindex = j;
        }
        swap(a[i],a[minindex]);
    }
    print(a);
}
void insertionSort(vector<int> a) {
    /// The first index is considered to bi min, then checked with the next ele. Swap accordingly
    /// Next ele is checked and inserted in required location (ex: 2 4 5 // 3 will be inserted in between 2 & 4)
    int key;
    for(int i = 1 ; i < a.size(); i++) {
        int j = i-1;
        key = a[i];
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }

    print(a);
}
void merge(vector<int> a, int p, int q, int r) {
    int n1 = q - p+ 1;
    int n2 = r - q;
    vector<int> L(n1);
    vector<int> M(n2);

    for(int i = 0; i < n1; i++)
        L[i] = a[p+i];
    for(int i = 0; i < n2; i++)
        M[i] = a[q+1+i];


    int i,j,k;
    i = 0;
    j = q;
    k = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = M[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        a[k] = L[i];
        i++;k++;
    }

    while(j < n2) {
        a[k] = M[j];
        j++;k++;
    }

    print(a);
}
void mergesort(vector<int>a, int l, int r) {
/// Divide and conquer rule, recursion it divide the array into two parts repeatedly until
/// one of them is left
    if(l >= r)
        return;
    int m = l + (r - l)/ 2;
    mergesort(a,l,m);
    mergesort(a,m+1,r);
    merge(a,l,m,r);
}
int partition(vector<int> a, int start, int end) {
    int pivot = a[end];
    int pIndex = start;

    for (int i = start; i < end ; ++i) {
        if(a[i] < pivot) {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    swap(a[pIndex], a[end]);
    return pIndex;
}
void quickSort(vector<int>a,int start, int end) {
    if(start < end) {
        int  partitionIndex = partition(a,start,end);
        quickSort(a,start,partitionIndex-1);
        quickSort(a,partitionIndex+1,end);
    }
}
int main () {
//    int ch;
//    cin >> ch;
//    cout <<"1.Bubble Sort\n2.Insertion Sort\n3.Merge Sort\n4.QuickSort\n5.Heap Sort\n6.Selection Sort\n7.Counting Sort\n";
//    switch (ch) {
//
//    }
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        a.push_back(k);
    }
    auto start = high_resolution_clock::now();
    // Chose your own sorting algorithm
    mergesort(a,0,n-1);
    // Chose your own sorting algorithm
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    // You can check the time taken by the algorithm
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    return 0;
}
