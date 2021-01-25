#include <stdio.h>

#define MAX 9

void bubble_sort(int input[], int size) {
    int i, j, temp;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size - (i + 1); j++) {
            if (input[j] > input[j + 1]) {
                temp = input[j];
                input[j] = input[j + 1];
                input[j + 1] = temp;
            }
        }
    }
}

int main () {
    int i, j, total = 0;
    int hobit[MAX];
    int found[MAX];

    for (i = 0; i < MAX; i++) {
        scanf("%d\n", &hobit[i]);
        found[i] = 0;
        total += hobit[i];
    }
    total -= 100;

    bubble_sort(hobit, MAX);

    for (i = 0; i < MAX; i++) {
        for (j = i + 1; j < MAX; j++) {
            if (hobit[i] + hobit[j] == total) {
                found[i] = found[j] = 1;
                goto result;
            }
        }
    }

result:
    for (i = 0; i < MAX; i++) {
        if (!found[i]) {
            printf("%d\n", hobit[i]);
        }
    }
    return 0;
}
