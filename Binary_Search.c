#include <stdio.h>

// Binary Search
int binarysearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (arr[mid] == x)
            return mid;

        else if (x > arr[mid])
            l = mid + 1;

        else
            r = mid - 1;
    }
    return -1;
}

// Bubble Sort
void sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[100], original[100];
    int n, i, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter input: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        original[i] = arr[i];  
    }

    sort(arr, n);

    printf("After sorting (ascending order): ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nEnter searching element: ");
    scanf("%d", &x);

    int result = binarysearch(arr, 0, n - 1, x);

    if (result != -1)
    {
        for (i = 0; i < n; i++)
        {
            if (original[i] == x)
            {
                printf("Element found at index %d\n", i + 1);
                break;
            }
        }
    }
    else
    {
        printf("Element not found\n");
    }

    return 0;
}