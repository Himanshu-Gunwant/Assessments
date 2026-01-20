#include <stdio.h>

int main() {
    char arr[50] = "programming";
    int i;

    printf("Initial array:\n");
    for (i = 0; arr[i] != '\0'; i++)
        printf("%c ", arr[i]);
    printf("\n");

    char old = 'm', newc = 'n';
    for (i = 0; arr[i] != '\0'; i++)
        if (arr[i] == old)
            arr[i] = newc;

    printf("After replacement:\n");
    for (i = 0; arr[i] != '\0'; i++)
        printf("%c ", arr[i]);
    printf("\n");

    printf("Consecutive characters:\n");
    for (i = 0; arr[i + 1] != '\0'; i++)
        if (arr[i] == arr[i + 1])
            printf("%c%c at index %d\n", arr[i], arr[i + 1], i);

    char rem = 'n';
    int last = -1;
    for (i = 0; arr[i] != '\0'; i++)
        if (arr[i] == rem)
            last = i;

    if (last != -1) {
        for (i = last; arr[i] != '\0'; i++)
            arr[i] = arr[i + 1];
    }

    printf("After removing last occurrence:\n");
    for (i = 0; arr[i] != '\0'; i++)
        printf("%c ", arr[i]);
    printf("\n");

    printf("Array values with index:\n");
    for (i = 0; arr[i] != '\0'; i++)
        printf("Index %d : %c\n", i, arr[i]);

    int index = 3;
    printf("Address of index %d : %p\n", index, (void*)&arr[index]);

    return 0;
}
