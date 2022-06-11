/*
 * Title: Sorting and Algorithm Efficiency
 * Author: Abdullah Riaz
 * ID: 22001296
 * Section: 3
 * Assignment: 1
 * Description: Definition File for sorting methods
 */

using namespace std;
#include "sorting.h"
#include <iostream>
#include <stdlib.h>
#include <iomanip>

void insertionSort(int *arr, const int size, int &compCount, int &moveCount)
{
    compCount = 0;
    moveCount = 0;
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i;
        while (j > 0 && temp < arr[j - 1])
        {
            compCount++;
            arr[j] = arr[j - 1];
            j--;
            moveCount++;
        }
        arr[j] = temp;
        moveCount++;
    }
}

void bubbleSort(int *arr, const int size, int &compCount, int &moveCount)
{
    compCount = 0;
    moveCount = 0;

    bool sorted = false; // False when swaps occur
    int pass = 1;
    while (!sorted && (pass < size))
    {
        sorted = true; // Assume sorted
        for (int index = 0; index < (size - pass); index++)
        {
            int nextIndex = index + 1;
            compCount++;
            if (arr[index] > arr[nextIndex])
            {
                swap(arr[index], arr[nextIndex]);
                sorted = false;
                moveCount += 3;
            }
        }
        pass++;
    }
}

void mergeSort(int *arr, const int size, int &compCount, int &moveCount)
{
    compCount = 0;
    moveCount = 0;
    int *temp = new int[size];
    mergeSortHelper(arr, temp, 0, size - 1, compCount, moveCount);
    delete[] temp;
}

void mergeSortHelper(int *arr, int *temp, const int left, const int right, int &compCount, int &moveCount)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSortHelper(arr, temp, left, mid, compCount, moveCount);
        mergeSortHelper(arr, temp, mid + 1, right, compCount, moveCount);
        merge(arr, temp, left, mid, right, compCount, moveCount);
    }
}

void quickSort(int *arr, const int size, int &compCount, int &moveCount)
{
    compCount = 0;
    moveCount = 0;
    quickSortHelper(arr, 0, size - 1, compCount, moveCount);
}

void quickSortHelper(int *arr, const int left, const int right, int &compCount, int &moveCount)
{
    if (left < right)
    {
        int pivot = partition(arr, left, right, compCount, moveCount);
        quickSortHelper(arr, left, pivot - 1, compCount, moveCount);
        quickSortHelper(arr, pivot + 1, right, compCount, moveCount);
    }
}

int partition(int *arr, const int left, const int right, int &compCount, int &moveCount)
{
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        compCount++;
        if (arr[j] <= pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            moveCount += 3;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;
    moveCount += 3;
    return i + 1;
}

void merge(int *arr, int *temp, const int left, const int mid, const int right, int &compCount, int &moveCount)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right)
    {
        compCount++;
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
            moveCount += 3;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
            moveCount += 3;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
        moveCount += 2;
    }
    while (j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
        moveCount += 2;
    }
    for (int i = left; i <= right; i++)
    {
        arr[i] = temp[i];
        moveCount++;
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void displayArray(const int *arr, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size)
{
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];

    for (int i = 0; i < size; i++)
    {
        arr1[i] = rand() % size;
        arr2[i] = rand() % size;
        arr3[i] = rand() % size;
        arr4[i] = rand() % size;
    }
}
void createAlmostSortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size)
{
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];

    for (int i = 0; i < size; i++)
    {
        arr1[i] = i;
        arr2[i] = i;
        arr3[i] = i;
        arr4[i] = i;
    }
    for (int i = 0; i < (size / 20); i++)
    {
        int j = rand() % size;
        int temp = arr1[i];
        arr1[i] = arr1[j];
        arr1[j] = temp;
    }
    for (int i = 0; i < (size / 20); i++)
    {
        int j = rand() % size;
        int temp = arr2[i];
        arr2[i] = arr2[j];
        arr2[j] = temp;
    }
    for (int i = 0; i < (size / 20); i++)
    {
        int j = rand() % size;
        int temp = arr3[i];
        arr3[i] = arr3[j];
        arr3[j] = temp;
    }
    for (int i = 0; i < (size / 20); i++)
    {
        int j = rand() % size;
        int temp = arr4[i];
        arr4[i] = arr4[j];
        arr4[j] = temp;
    }
}

void createAlmostUnsortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size)
{
    arr1 = new int[size];
    arr2 = new int[size];
    arr3 = new int[size];
    arr4 = new int[size];

    for (int i = 0; i < size; i++)
    {
        arr1[i] = (size - i - 1);
        arr2[i] = (size - i - 1);
        arr3[i] = (size - i - 1);
        arr4[i] = (size - i - 1);
    }
    for (int i = 0; i < (size / 20); i++)
    {
        int j = rand() % size;
        int temp = arr1[i];
        arr1[i] = arr1[j];
        arr1[j] = temp;
    }
    for (int i = 0; i < (size / 20); i++)
    {
        int j = rand() % size;
        int temp = arr2[i];
        arr2[i] = arr2[j];
        arr2[j] = temp;
    }
    for (int i = 0; i < (size / 20); i++)
    {
        int j = rand() % size;
        int temp = arr3[i];
        arr3[i] = arr3[j];
        arr3[j] = temp;
    }
    for (int i = 0; i < (size / 20); i++)
    {
        int j = rand() % size;
        int temp = arr4[i];
        arr4[i] = arr4[j];
        arr4[j] = temp;
    }
}

void performanceAnalysisRandom()
{
    clock_t timer;
    int compCount = 0;
    int moveCount = 0;

    double timeElapsed;

    int *arrInert5k, *arrInert10k, *arrInert15k, *arrInert20k, *arrInert25k, *arrInert30k, *arrInert35k, *arrInert40k;
    int *arrBubble5k, *arrBubble10k, *arrBubble15k, *arrBubble20k, *arrBubble25k, *arrBubble30k, *arrBubble35k, *arrBubble40k;
    int *arrInsertion5k, *arrInsertion10k, *arrInsertion15k, *arrInsertion20k, *arrInsertion25k, *arrInsertion30k, *arrInsertion35k, *arrInsertion40k;
    int *arrMerge5k, *arrMerge10k, *arrMerge15k, *arrMerge20k, *arrMerge25k, *arrMerge30k, *arrMerge35k, *arrMerge40k;
    int *arrQuick5k, *arrQuick10k, *arrQuick15k, *arrQuick20k, *arrQuick25k, *arrQuick30k, *arrQuick35k, *arrQuick40k;

    createRandomArrays(arrInsertion5k, arrMerge5k, arrQuick5k, arrBubble5k, 5000);
    createRandomArrays(arrInsertion10k, arrMerge10k, arrQuick10k, arrBubble10k, 10000);
    createRandomArrays(arrInsertion15k, arrMerge15k, arrQuick15k, arrBubble15k, 15000);
    createRandomArrays(arrInsertion20k, arrMerge20k, arrQuick20k, arrBubble20k, 20000);
    createRandomArrays(arrInsertion25k, arrMerge25k, arrQuick25k, arrBubble25k, 25000);
    createRandomArrays(arrInsertion30k, arrMerge30k, arrQuick30k, arrBubble30k, 30000);
    createRandomArrays(arrInsertion35k, arrMerge35k, arrQuick35k, arrBubble35k, 35000);
    createRandomArrays(arrInsertion40k, arrMerge40k, arrQuick40k, arrBubble40k, 40000);

    cout << "-----------------------------------------------------" << endl;
    cout << "Random arrays" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Insertion Sort" << endl;
    cout << "Array Size" << setw(25) << "Elapsed time" << setw(25) << "Comp Count" << setw(25) << "Move Count" << endl;

    timer = clock();
    insertionSort(arrInsertion5k, 5000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "5000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    insertionSort(arrInsertion10k, 10000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "10000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    insertionSort(arrInsertion15k, 15000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "15000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    insertionSort(arrInsertion20k, 20000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "20000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    insertionSort(arrInsertion25k, 25000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "25000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    insertionSort(arrInsertion30k, 30000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "30000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    insertionSort(arrInsertion35k, 35000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "35000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    insertionSort(arrInsertion40k, 40000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "40000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Merge Sort" << endl;
    cout << "Array Size" << setw(25) << "Elapsed time" << setw(25) << "Comp Count" << setw(25) << "Move Count" << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge5k, 5000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "5000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge10k, 10000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "10000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge15k, 15000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "15000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge20k, 20000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "20000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge25k, 25000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "25000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge30k, 30000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "30000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge35k, 35000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "35000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge40k, 40000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "40000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Quick Sort" << endl;
    cout << "Array Size" << setw(25) << "Elapsed time" << setw(25) << "Comp Count" << setw(25) << "Move Count" << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick5k, 5000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "5000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick10k, 10000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "10000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick15k, 15000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "15000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick20k, 20000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "20000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick25k, 25000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "25000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick30k, 30000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "30000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick35k, 35000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "35000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick40k, 40000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "40000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Bubble Sort" << endl;
    cout << "Array Size" << setw(25) << "Elapsed time" << setw(25) << "Comp Count" << setw(25) << "Move Count" << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble5k, 5000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "5000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble10k, 10000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "10000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble15k, 15000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "15000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble20k, 20000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "20000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble25k, 25000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "25000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble30k, 30000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "30000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble35k, 35000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "35000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble40k, 40000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "40000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    delete[] arrBubble5k;
    delete[] arrBubble10k;
    delete[] arrBubble15k;
    delete[] arrBubble20k;
    delete[] arrBubble25k;
    delete[] arrBubble30k;
    delete[] arrBubble35k;
    delete[] arrBubble40k;

    delete[] arrQuick5k;
    delete[] arrQuick10k;
    delete[] arrQuick15k;
    delete[] arrQuick20k;
    delete[] arrQuick25k;
    delete[] arrQuick30k;
    delete[] arrQuick35k;
    delete[] arrQuick40k;

    delete[] arrInsertion5k;
    delete[] arrInsertion10k;
    delete[] arrInsertion15k;
    delete[] arrInsertion20k;
    delete[] arrInsertion25k;
    delete[] arrInsertion30k;
    delete[] arrInsertion35k;
    delete[] arrInsertion40k;

    delete[] arrMerge5k;
    delete[] arrMerge10k;
    delete[] arrMerge15k;
    delete[] arrMerge20k;
    delete[] arrMerge25k;
    delete[] arrMerge30k;
    delete[] arrMerge35k;
    delete[] arrMerge40k;
}

void performanceAnalysisAlmostSorted()
{
    clock_t timer;
    int compCount = 0;
    int moveCount = 0;

    double timeElapsed;

    int *arrInert5k, *arrInert10k, *arrInert15k, *arrInert20k, *arrInert25k, *arrInert30k, *arrInert35k, *arrInert40k;
    int *arrBubble5k, *arrBubble10k, *arrBubble15k, *arrBubble20k, *arrBubble25k, *arrBubble30k, *arrBubble35k, *arrBubble40k;
    int *arrInsertion5k, *arrInsertion10k, *arrInsertion15k, *arrInsertion20k, *arrInsertion25k, *arrInsertion30k, *arrInsertion35k, *arrInsertion40k;
    int *arrMerge5k, *arrMerge10k, *arrMerge15k, *arrMerge20k, *arrMerge25k, *arrMerge30k, *arrMerge35k, *arrMerge40k;
    int *arrQuick5k, *arrQuick10k, *arrQuick15k, *arrQuick20k, *arrQuick25k, *arrQuick30k, *arrQuick35k, *arrQuick40k;

    createAlmostSortedArrays(arrInsertion5k, arrMerge5k, arrQuick5k, arrBubble5k, 5000);
    createAlmostSortedArrays(arrInsertion10k, arrMerge10k, arrQuick10k, arrBubble10k, 10000);
    createAlmostSortedArrays(arrInsertion15k, arrMerge15k, arrQuick15k, arrBubble15k, 15000);
    createAlmostSortedArrays(arrInsertion20k, arrMerge20k, arrQuick20k, arrBubble20k, 20000);
    createAlmostSortedArrays(arrInsertion25k, arrMerge25k, arrQuick25k, arrBubble25k, 25000);
    createAlmostSortedArrays(arrInsertion30k, arrMerge30k, arrQuick30k, arrBubble30k, 30000);
    createAlmostSortedArrays(arrInsertion35k, arrMerge35k, arrQuick35k, arrBubble35k, 35000);
    createAlmostSortedArrays(arrInsertion40k, arrMerge40k, arrQuick40k, arrBubble40k, 40000);

    cout << "-----------------------------------------------------" << endl;
    cout << "Almost Sorted Arrays" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Insertion Sort" << endl;
    cout << "Array Size" << setw(25) << "Elapsed time" << setw(25) << "Comp Count" << setw(25) << "Move Count" << endl;

    timer = clock();
    insertionSort(arrInsertion5k, 5000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "5000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    insertionSort(arrInsertion10k, 10000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "10000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    insertionSort(arrInsertion15k, 15000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "15000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    insertionSort(arrInsertion20k, 20000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "20000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    insertionSort(arrInsertion25k, 25000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "25000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    insertionSort(arrInsertion30k, 30000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "30000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    insertionSort(arrInsertion35k, 35000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "35000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    insertionSort(arrInsertion40k, 40000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "40000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Merge Sort" << endl;
    cout << "Array Size" << setw(25) << "Elapsed time" << setw(25) << "Comp Count" << setw(25) << "Move Count" << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge5k, 5000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "5000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge10k, 10000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "10000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge15k, 15000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "15000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge20k, 20000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "20000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge25k, 25000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "25000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge30k, 30000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "30000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge35k, 35000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "35000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge40k, 40000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "40000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Quick Sort" << endl;
    cout << "Array Size" << setw(25) << "Elapsed time" << setw(25) << "Comp Count" << setw(25) << "Move Count" << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick5k, 5000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "5000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick10k, 10000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "10000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick15k, 15000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "15000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick20k, 20000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "20000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick25k, 25000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "25000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick30k, 30000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "30000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick35k, 35000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "35000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick40k, 40000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "40000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Bubble Sort" << endl;
    cout << "Array Size" << setw(25) << "Elapsed time" << setw(25) << "Comp Count" << setw(25) << "Move Count" << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble5k, 5000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "5000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble10k, 10000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "10000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble15k, 15000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "15000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble20k, 20000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "20000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble25k, 25000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "25000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble30k, 30000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "30000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble35k, 35000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "35000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble40k, 40000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "40000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    delete[] arrBubble5k;
    delete[] arrBubble10k;
    delete[] arrBubble15k;
    delete[] arrBubble20k;
    delete[] arrBubble25k;
    delete[] arrBubble30k;
    delete[] arrBubble35k;
    delete[] arrBubble40k;

    delete[] arrQuick5k;
    delete[] arrQuick10k;
    delete[] arrQuick15k;
    delete[] arrQuick20k;
    delete[] arrQuick25k;
    delete[] arrQuick30k;
    delete[] arrQuick35k;
    delete[] arrQuick40k;

    delete[] arrInsertion5k;
    delete[] arrInsertion10k;
    delete[] arrInsertion15k;
    delete[] arrInsertion20k;
    delete[] arrInsertion25k;
    delete[] arrInsertion30k;
    delete[] arrInsertion35k;
    delete[] arrInsertion40k;

    delete[] arrMerge5k;
    delete[] arrMerge10k;
    delete[] arrMerge15k;
    delete[] arrMerge20k;
    delete[] arrMerge25k;
    delete[] arrMerge30k;
    delete[] arrMerge35k;
    delete[] arrMerge40k;
}

void performanceAnalysisAlmostUnsorted()
{
    clock_t timer;
    int compCount = 0;
    int moveCount = 0;

    double timeElapsed;

    int *arrInert5k, *arrInert10k, *arrInert15k, *arrInert20k, *arrInert25k, *arrInert30k, *arrInert35k, *arrInert40k;
    int *arrBubble5k, *arrBubble10k, *arrBubble15k, *arrBubble20k, *arrBubble25k, *arrBubble30k, *arrBubble35k, *arrBubble40k;
    int *arrInsertion5k, *arrInsertion10k, *arrInsertion15k, *arrInsertion20k, *arrInsertion25k, *arrInsertion30k, *arrInsertion35k, *arrInsertion40k;
    int *arrMerge5k, *arrMerge10k, *arrMerge15k, *arrMerge20k, *arrMerge25k, *arrMerge30k, *arrMerge35k, *arrMerge40k;
    int *arrQuick5k, *arrQuick10k, *arrQuick15k, *arrQuick20k, *arrQuick25k, *arrQuick30k, *arrQuick35k, *arrQuick40k;

    createAlmostUnsortedArrays(arrInsertion5k, arrMerge5k, arrQuick5k, arrBubble5k, 5000);
    createAlmostUnsortedArrays(arrInsertion10k, arrMerge10k, arrQuick10k, arrBubble10k, 10000);
    createAlmostUnsortedArrays(arrInsertion15k, arrMerge15k, arrQuick15k, arrBubble15k, 15000);
    createAlmostUnsortedArrays(arrInsertion20k, arrMerge20k, arrQuick20k, arrBubble20k, 20000);
    createAlmostUnsortedArrays(arrInsertion25k, arrMerge25k, arrQuick25k, arrBubble25k, 25000);
    createAlmostUnsortedArrays(arrInsertion30k, arrMerge30k, arrQuick30k, arrBubble30k, 30000);
    createAlmostUnsortedArrays(arrInsertion35k, arrMerge35k, arrQuick35k, arrBubble35k, 35000);
    createAlmostUnsortedArrays(arrInsertion40k, arrMerge40k, arrQuick40k, arrBubble40k, 40000);

    cout << "-----------------------------------------------------" << endl;
    cout << "Almost Unsorted Arrays" << endl;
    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Insertion Sort" << endl;
    cout << "Array Size" << setw(25) << "Elapsed time" << setw(25) << "Comp Count" << setw(25) << "Move Count" << endl;

    timer = clock();
    insertionSort(arrInsertion5k, 5000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "5000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    insertionSort(arrInsertion10k, 10000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "10000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    insertionSort(arrInsertion15k, 15000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "15000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    insertionSort(arrInsertion20k, 20000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "20000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    insertionSort(arrInsertion25k, 25000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "25000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    insertionSort(arrInsertion30k, 30000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "30000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    insertionSort(arrInsertion35k, 35000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "35000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    insertionSort(arrInsertion40k, 40000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "40000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Merge Sort" << endl;
    cout << "Array Size" << setw(25) << "Elapsed time" << setw(25) << "Comp Count" << setw(25) << "Move Count" << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge5k, 5000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "5000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge10k, 10000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "10000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge15k, 15000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "15000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge20k, 20000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "20000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge25k, 25000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "25000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge30k, 30000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "30000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge35k, 35000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "35000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    mergeSort(arrMerge40k, 40000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "40000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Quick Sort" << endl;
    cout << "Array Size" << setw(25) << "Elapsed time" << setw(25) << "Comp Count" << setw(25) << "Move Count" << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick5k, 5000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "5000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick10k, 10000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "10000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick15k, 15000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "15000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick20k, 20000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "20000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick25k, 25000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "25000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick30k, 30000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "30000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick35k, 35000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "35000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    quickSort(arrQuick40k, 40000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "40000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    cout << "-----------------------------------------------------" << endl;
    cout << "Analysis of Bubble Sort" << endl;
    cout << "Array Size" << setw(25) << "Elapsed time" << setw(25) << "Comp Count" << setw(25) << "Move Count" << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble5k, 5000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "5000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble10k, 10000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "10000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble15k, 15000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "15000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble20k, 20000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "20000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble25k, 25000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "25000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble30k, 30000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "30000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble35k, 35000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "35000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    moveCount = 0;
    compCount = 0;
    timer = clock();
    bubbleSort(arrBubble40k, 40000, moveCount, compCount);
    timeElapsed = 1000 * ((clock() - timer) / (double)CLOCKS_PER_SEC);
    cout << "40000" << setw(25) << timeElapsed << " ms" << setw(25) << compCount << setw(25) << moveCount << endl;

    delete[] arrBubble5k;
    delete[] arrBubble10k;
    delete[] arrBubble15k;
    delete[] arrBubble20k;
    delete[] arrBubble25k;
    delete[] arrBubble30k;
    delete[] arrBubble35k;
    delete[] arrBubble40k;

    delete[] arrQuick5k;
    delete[] arrQuick10k;
    delete[] arrQuick15k;
    delete[] arrQuick20k;
    delete[] arrQuick25k;
    delete[] arrQuick30k;
    delete[] arrQuick35k;
    delete[] arrQuick40k;

    delete[] arrInsertion5k;
    delete[] arrInsertion10k;
    delete[] arrInsertion15k;
    delete[] arrInsertion20k;
    delete[] arrInsertion25k;
    delete[] arrInsertion30k;
    delete[] arrInsertion35k;
    delete[] arrInsertion40k;

    delete[] arrMerge5k;
    delete[] arrMerge10k;
    delete[] arrMerge15k;
    delete[] arrMerge20k;
    delete[] arrMerge25k;
    delete[] arrMerge30k;
    delete[] arrMerge35k;
    delete[] arrMerge40k;
}

void performanceAnalysis()
{
    performanceAnalysisRandom();
    performanceAnalysisAlmostUnsorted();
    performanceAnalysisAlmostSorted();
}
