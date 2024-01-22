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




int main()
{
    int arr[5] = {2, 8, 5, 3, 7};

    int size = sizeof(arr) / sizeof(arr[0]);

    
    printf("Merge Sort Array\n");

    merge_sort(arr,size);

    printArray(arr,size);


    return 0;
}
