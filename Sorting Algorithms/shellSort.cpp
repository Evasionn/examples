#include <iostream>
using namespace std;

void shellSort(int arr[], int size)
{
	int flag = 1, i;
	int d = size;
	while (flag || d > 1)
	{
		flag = 0;
		d = (d + 1) / 2;
		for (i = 0; i < size - d; i++)
		{
			if (arr[i + d] < arr[i])
			{
				swap(arr[i + d], arr[i]);
				flag = 1;
			}
		}
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



	shellSort(arr, size);
	display(arr, size);
	cout << endl;

	return 0;
}