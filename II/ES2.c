#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left[], int right[], int left_size, int right_size) {
    int i = 0, j = 0, k = 0;
    
    while (i < left_size && j < right_size) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int arr_size) {
    if (arr_size > 1) {
        int mid = arr_size / 2;
        int *left = (int *)malloc(mid * sizeof(int));
        int *right = (int *)malloc((arr_size - mid) * sizeof(int));

        for (int i = 0; i < mid; i++) {
            left[i] = arr[i];
        }

        for (int i = mid; i < arr_size; i++) {
            right[i - mid] = arr[i];
        }

        mergeSort(left, mid);
        mergeSort(right, arr_size - mid);
        merge(arr, left, right, mid, arr_size - mid);

        free(left);
        free(right);
    }
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[left];
        int low = left + 1;
        int high = right;

        while (1) {
            while (low <= high && arr[high] >= pivot) {
                high--;
            }
            while (low <= high && arr[low] <= pivot) {
                low++;
            }
            if (low <= high) {
                int temp = arr[low];
                arr[low] = arr[high];
                arr[high] = temp;
            } else {
                break;
            }
        }

        int temp = arr[left];
        arr[left] = arr[high];
        arr[high] = temp;

        quickSort(arr, left, high - 1);
        quickSort(arr, high + 1, right);
    }
}

int main() {
    int size = 5000;
    int *arr = (int *)malloc(size * sizeof(int));

    srand(time(NULL));
    for (int k = 0; k < size; k++) {
        arr[k] = rand() % 10000000;
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    quickSort(arr, 0, size - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do Quicksort em segundos: %lf\n", cpu_time_used);

    start = clock();
    mergeSort(arr, size);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do Mergesort em segundos: %lf\n", cpu_time_used);

    free(arr);
    return 0;
}
