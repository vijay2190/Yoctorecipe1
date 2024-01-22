#include <stdio.h>
#include <stdlib.h>


int swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}



int partition(int *arr, int low, int high)
{
    int pivot = low, p = low+1, q = high;

    while(p <= q)
    {
        while(arr[p] < arr[pivot])
        {
            p++;
        }

        while(arr[q] > arr[pivot])
        {
            q--;
        }

        if(p < q)
            swap(&arr[p],&arr[q]);
    }

    int temp = arr[q];
    arr[q] = arr[pivot];
    arr[pivot] = temp;


return q;
}
int quickSort(int *arr, int low, int high)
{
    if(low < high)
    {
        int index = partition(arr, low, high);
        quickSort(arr, low, index-1);
        quickSort(arr, index+1,high);
    }

return 0;
}



int main()
{
    int arr[5] = {2, 8, 5, 3, 7};

    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr,0,size-1);
    printArray(arr,size);



    return 0;
}
