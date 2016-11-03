#include <iostream>
using namepsace std;
void selectionSort(int arr[], int size)
{
	int smallest = arr[0];
	int j = 0;
	int indx = j;
	while (j < size)
	{
		for (int i = j+1; i < size; i++) {
			if (smallest > arr[i])
			{
				smallest = arr[i];
				indx = i;
			}
		}
	if(smallest!=arr[j])
		swap(arr[indx], arr[j]);
		j++;
		smallest = arr[j];
	}
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
	

	selectionSort(arr, size);


	display(arr, size);

	system("pause");
}