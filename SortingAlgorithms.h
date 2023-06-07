#include<iostream>
#include<string>
#include "University.h"
#include "Users.h"
using namespace std;

/*
    -> Helper function for merge sort
*/
void merge(University arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    University L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0;    // Initial index of first subarray
    int j = 0;    // Initial index of second subarray
    int k = left; // Initial index of merged subarray

    while (i < n1 && j < n2)
    {
        if (L[i].institute <= R[j].institute)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


/*
    -> Merge Sort
    -> Divide and Conquer
    -> Driver function
*/
void mergeSort(University arr[], int left, int right)
{
    if (left < right)
    {
        // Same as (left + right) / 2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

/*
    -> Insertion Sort
    -> Sort universities according to ASCII Characters
*/
void insertionSort(University arr[], int n)
{
    University key;
    int i, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j].institute > key.institute)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}




/*
    -> Insertion sort function
    -> Sort in decreasing order
    -> Sort according to given factor
    -> factors are (arScore, erScore, and fsrScore)

*/
void sortDescending(University arr[], std::string factor, int length) {
    if (factor == "ar_score") {
        for (int i = 1; i < length; i++) {
            University key = arr[i];
           
            int j = i - 1;
            while (j >= 0 && stof(arr[j].arScore) < stof(key.arScore)) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    else if (factor == "er_score") {
        for (int i = 1; i < length; i++) {
            University key = arr[i];
            int j = i - 1;
            while (j >= 0 && stof(arr[j].erScore) < stof(key.erScore)) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        
    }
    else if (factor == "fsr_score") {
        for (int i = 1; i < length; i++) {
            University key = arr[i];
            int j = i - 1;
            while (j >= 0 && stof(arr[j].fsrScore) < stof(key.fsrScore)) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
        
    }
}