#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        int leftLen = mid - low + 1;
        int rightLen = high - mid;

        int left[leftLen];
        int right[rightLen];

        for (int i = 0; i < leftLen; i++) {
            left[i] = arr[low + i];
        }
        for (int i = 0; i < rightLen; i++) {
            right[i] = arr[mid + 1 + i];
        }

        int i = 0, j = 0, k = low;

        while (i < leftLen && j < rightLen) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
            }
        }

        while (i < leftLen) {
            arr[k++] = left[i++];
        }

        while (j < rightLen) {
            arr[k++] = right[j++];
        }
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[low];
        int i = low;
        int j = high;

        while (i < j) {
            while (i < j && arr[j] > pivot) {
                j--;
            }
            if (i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }

            while (i < j && arr[i] <= pivot) {
                i++;
            }
            if (i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }

        quickSort(arr, low, i - 1);
        quickSort(arr, i + 1, high);
    }
}

int main() {
    int n = 5000;
    int arr[n];
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000001;
    }

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    quickSort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do Quicksort em segundos: %lf\n", cpu_time_used);

    int arr2[n];
    for (int i = 0; i < n; i++) {
        arr2[i] = arr[i];  // Copia o vetor ordenado pelo Quicksort para o Mergesort
    }

    start = clock();
    mergeSort(arr2, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execução do Mergesort em segundos: %lf\n", cpu_time_used);

    return 0;
}
