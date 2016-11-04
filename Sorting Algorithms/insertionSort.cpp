#include <iostream>
using namespace std;

void insertionSort(int arr[], int size)
{
	int j;

	for (int i = 0; i < size; i++)
	{
		j = i;
		while (j > 0 && arr[j] < arr[j - 1])
		{
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}
int main()
{
	int arr[] = { 0,90,32,66,22,11,754,12,23,5 };
	int size = sizeof(arr) / sizeof(int);
	


	insertionSort(arr, size);
	display(arr, size);

	system("pause");
}