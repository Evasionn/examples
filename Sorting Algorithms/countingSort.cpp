#include <iostream>
using namespace std;
void countingSort(int arr[],int size)
{
    int range=0;
    for(int i=0; i < size; i++) if(range < arr[i]) range=arr[i];
    range++;
    int * counts = new int [range];
    for(int i=0; i < range; i++) counts[i]=0; // initializing the counts arr
    for(int i=0; i < size; i++) counts[arr[i]]++;
    int position=0;
    for(int i=0; i < range; i++)
    {
        for(int j=0; j < counts[i]; j++)
        {
            arr[position]=i;
            position++;
        }
    }
    
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++) cout << arr[i] << " ";
}

int main()
{
    int arr[] = {0,99,32,66,22,11,754,12,23,5 };
    int size = sizeof(arr)/sizeof(int);
    
    countingSort(arr,size);
    
    display(arr,size);
    cout << endl;
 
    return 0;
}
