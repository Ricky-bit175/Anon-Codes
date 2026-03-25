#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp     = arr[j];
                arr[j]   = arr[j + 1];
                arr[j+1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int mid = l + (r - l) / 2;   

        if (arr[mid] == x)           
            return mid;

        if (arr[mid] < x)           
            l = mid + 1;
        else                         
            r = mid - 1;
    }
    return -1;  
}
int main() {
    int n, i, x, result;

    printf("How many elements? ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    /* Sort the array first */
    bubbleSort(arr, n);

    printf("After sorting (ascending order): ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Enter searching element: ");
    scanf("%d", &x);

    result = binarySearch(arr, 0, n - 1, x);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}