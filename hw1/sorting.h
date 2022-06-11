/*
 * Title: Sorting and Algorithm Efficiency
 * Author: Abdullah Riaz
 * ID: 22001296
 * Section: 3
 * Assignment: 1
 * Description: Prototypes for sorting methods
 */

using namespace std;

void insertionSort(int *arr, const int size, int &compCount, int &moveCount);
void bubbleSort(int *arr, const int size, int &compCount, int &moveCount);
void mergeSort(int *arr, const int size, int &compCount, int &moveCount);
void quickSort(int *arr, const int size, int &compCount, int &moveCount);
void swap(int &a, int &b);
void mergeSortHelper(int *arr, int *temp, int left, int right, int &compCount, int &moveCount);
void merge(int *arr, int *temp, int left, int mid, int right, int &compCount, int &moveCount);
void quickSortHelper(int *arr, int left, int right, int &compCount, int &moveCount);
int partition(int *arr, int left, int right, int &compCount, int &moveCount);

void displayArray(const int *arr, const int size);
void createRandomArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createAlmostSortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void createAlmostUnsortedArrays(int *&arr1, int *&arr2, int *&arr3, int *&arr4, const int size);
void performanceAnalysis();
