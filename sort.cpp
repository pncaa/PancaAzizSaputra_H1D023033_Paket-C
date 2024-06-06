#include <stdio.h>

void sort(int a[], int size) {
    int switched = 1;
    int hold = 0;
    int j = 0;
    int i = 0;

    size -= 1;

    for (i = 0; i < size && switched; i++) {
        switched = 0;
        for (j = 0; j < size - i; j++) {
            if (a[j] > a[j + 1]) {
                switched = 1;
                hold = a[j];
                a[j] = a[j + 1];
                a[j + 1] = hold;
            }
        }
    }
}

int main(void) {
    int arr[6];  // Added missing semicolon
    int i = 0;

    for (i = 0; i < 6; i++) {
        printf("masukan nilainya: ");  // Corrected missing semicolon
        scanf("%d", &arr[i]);  // Removed extraneous space in format specifier
    }

    sort(arr, 6);

printf(" nilai setelah diurutkan \n");
    for (i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
