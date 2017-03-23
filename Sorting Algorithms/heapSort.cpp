#include <iostream>
using namespace std;

void heapify(int arr[], int i, int heapSize)
{
    int lft = i * 2;
    int rgt = lft + 1;
    int grt = i;

    if (lft <= heapSize && arr[lft] > arr[grt]) grt = lft;
    if (rgt <= heapSize && arr[rgt] > arr[grt]) grt = rgt;
    if (grt != i) {
        swap(arr[i],arr[grt]);
        heapify(arr, grt, heapSize);
    }
}

void heapSort(int arr[], int size)
{
    int heapSize = size - 1;

    for (int i = heapSize / 2; i >= 0; i--)
        heapify(arr, i,heapSize);

    for (int i = heapSize; i > 0; i--) {
        swap(arr[0],arr[i]);
        heapSize--;
        heapify(arr, 0, heapSize);
    }
}

void display(int arr[], int size)
{
	for (int i = 0; i < size; i++) cout << arr[i] << " ";
}

int main()
{
	int arr[] = { 0,90,32,66,22,11,754,12,23,5 };
	int size = sizeof(arr) / sizeof(int);
	heapSort(arr,size);
	display(arr, size);
	cout << endl;
	
	return 0;
}
