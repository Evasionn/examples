#include <iostream>
#include <string>
using namespace std;

void quickSort(int arr[], int left, int right)
{
	int i = left;
	int j = right;
	int pivot = arr[(left + right) / 2];

	while (i <= j)
	{
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;
		if (i <= j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}
	if (left < j) quickSort(arr, left, j);
	if (i < right) quickSort(arr, i, right);
}


void display(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "  ";
	}
}
int main()
{
	int arr[] = { 0,90,32,66,22,11,754,12,23,5 };
	int size = sizeof(arr) / sizeof(int);
	

	quickSort(arr, 0,size-1);


	display(arr, size);

	system("pause");
}