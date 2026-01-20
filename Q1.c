#include <stdio.h>

int insert(int arr[], int n, int pos, int val) {
    for (int i = n; i > pos; i--)
        arr[i] = arr[i - 1];
    arr[pos] = val;
    return n + 1;
}

int delete(int arr[], int n, int pos) {
    for (int i = pos; i < n - 1; i++)
        arr[i] = arr[i + 1];
    return n - 1;
}

int search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

int merge(int a[], int n1, int b[], int n2, int c[]) {
    for (int i = 0; i < n1; i++)
        c[i] = a[i];
    for (int i = 0; i < n2; i++)
        c[n1 + i] = b[i];
    return n1 + n2;
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[50] = {10, 20, 30, 40, 50};
    int n = 5;

    n = insert(arr, n, 2, 25);
    display(arr, n);

    n = delete(arr, n, 4);
    display(arr, n);

    int idx = search(arr, n, 30);
    printf("%d\n", idx);

    int arr2[5] = {60, 70, 80};
    int merged[100];
    int m = merge(arr, n, arr2, 3, merged);
    display(merged, m);

    return 0;
}
