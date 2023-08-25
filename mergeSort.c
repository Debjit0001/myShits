#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *arr, int s, int e)
{
    // base case: when the size of array is 1
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    // recursive call to sort the left part:
    mergeSort(arr, s, mid);

    // copying the left part into a separate array:
    int len1 = mid - s + 1;
    int *leftArr = (int *)calloc(len1, sizeof(int));
    for (int i = 0; i < len1; i++)
        leftArr[i] = arr[s + i];

    // recursive call to sort the right part:
    mergeSort(arr, mid + 1, e);

    // copying the right part into a separate array:
    int len2 = e - mid;
    int *rightArr = (int *)calloc(len2, sizeof(int));
    for (int i = 0; i < len2; i++)
        rightArr[i] = arr[mid + 1 + i];

    // now merging both sorted parts:
    int i = 0, j = 0, k = s;
    while (i < len1 && j < len2)
    {
        // compare the elements at the current indexes of the two arrays and put the smaller element in the merged array:
        if (leftArr[i] <= rightArr[j])
            arr[k] = leftArr[i++];
        else
            arr[k] = rightArr[j++];
        k++;
    }

    // copy the remaining elements from the left array, if any
    while (i < len1)
        arr[k++] = leftArr[i++];

    // copy the remaining elements from the right array, if any
    while (j < len2)
        arr[k++] = rightArr[j++];

    // deallocating memory
    free(leftArr);
    free(rightArr);
}

int main()
{
    int n;
    printf("Enter number of elements in the list: ");
    scanf("%d", &n);

    int *arr = (int *)calloc(n, sizeof(int));
    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);

    mergeSort(arr, 0, n - 1);

    printf("After sorting: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", *(arr + i));

    free(arr);

    return 0;
}
