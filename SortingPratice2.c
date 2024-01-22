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



int mergeSort(int *arr, int size, int *lsa, int lsasize, int *rsa, int rsasize)
{
	int i=0,j=0,k=0;

	while(i<lsasize && j<rsasize)
	{
		if(lsa[i] < rsa[j])
		{
			arr[k] = lsa[i];
			k++,i++;
		}else
		{
			arr[k] = rsa[j];
			k++,j++;
		}
	}

	while(i < lsasize)
	{
	    arr[k] = lsa[i];
	    i++,k++;
	}

	while(j < rsasize)
	{
	    arr[k] = rsa[j];
	    j++,k++;
	}

}


int merge_sort(int *arr, int size)
{
    if(size == 1)
	    return 1;


    int mid = size / 2;

    int *lsa = malloc(sizeof(int) * mid);
    if(lsa == NULL)
    {
	return -1;
    }

    for(int i=0;i<mid;i++)
    {
	lsa[i] = arr[i];
    }

    int *rsa = malloc(sizeof(int) * (size - mid));
    if(rsa == NULL)
    {
	return -1;
    }

    for(int i=mid;i<size;i++)
    {
	    rsa[i-mid] = arr[i];
    }


    merge_sort(lsa,mid);
    merge_sort(rsa,(size-mid));

    mergeSort(arr,size,lsa,mid,rsa,(size-mid));
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

    
    printf("Merge Sort Array\n");

    merge_sort(arr,size);

    printArray(arr,size);

    quickSort(arr,0,size-1);
    printArray(arr,size);



    return 0;
}
