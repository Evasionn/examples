#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size)
{
	int flag;
	do
	{
		flag = 0;
		for (int i = 0; i < size-1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				flag = 1;
			}
		}
	} while (flag);
}

void display(int arr[], int size)
{
	for (int i = 0; i < size; i++) cout << arr[i] << " ";
}
int main()
{
	int arr[] = { 0,90,32,66,22,11,754,12,23,5 };
	int size = sizeof(arr) / sizeof(int);
	bubbleSort(arr, size);
	display(arr, size);
	cout << endl;
	
	return 0;
}