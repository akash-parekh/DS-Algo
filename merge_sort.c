#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INSERTION_THRESHOLD 16

void merge(int arr[], int left[], int left_size, int right[], int right_size, int temp[]) {
    int i = 0, j = 0, k = 0;
    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            temp[k++] = left[i++];
        } else {
            temp[k++] = right[j++];
        }
    }
    while (i < left_size) {
        temp[k++] = left[i++];
    }
    while (j < right_size) {
        temp[k++] = right[j++];
    }
    memcpy(arr, temp, (left_size + right_size) * sizeof(int));
}

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge_sort(int arr[], int start, int end, int temp[]) {
    if (end - start < INSERTION_THRESHOLD) {
        insertion_sort(arr + start, end - start + 1);
        return;
    }

    int mid = start + (end - start) / 2;
    merge_sort(arr, start, mid, temp);
    merge_sort(arr, mid + 1, end, temp);
    merge(arr + start, arr + start, mid - start + 1, arr + mid + 1, end - mid, temp);
}

void sort(int arr[], int n) {
    int temp[n];
    merge_sort(arr, 0, n - 1, temp);
}

int main() {
    int arr[] = {5, 1, 3, 6, 8, 2, 4, 7};
    int n = sizeof(arr) / sizeof(int);

    sort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
