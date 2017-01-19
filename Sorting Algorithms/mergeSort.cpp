#include <iostream>


using namespace std;
void merge(int arr[], int size, int left, int right)
{
	int * temp = new int[size];
	for (int i = left; i <= right; i++)
	{
		temp[i] = arr[i];
	}
	int i = left;
	int mid = (left + right) / 2;
	int j = mid + 1;
	int k = left;

	while (i <= mid && j <= right)
	{
		if (temp[i] <= temp[j])
		{
			arr[k] = temp[i];
			++i;
		}
		else
		{
			arr[k] = temp[j];
			++j;
		}
		++k;
	}

	while (i <= mid)
	{
		arr[k] = temp[i];
		++k;
		++i;
	}
	delete temp;
}

void mergeSort(int arr[], int size, int left, int right)
{
	if (left < right)
	{
		mergeSort(arr, size, left, (left + right) / 2);
		mergeSort(arr, size, (left + right) / 2 + 1, right);
		merge(arr, size, left, right);
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
	mergeSort(arr, size, 0, size - 1);

	display(arr, size);
	cout << endl;
	
	return 0;
}