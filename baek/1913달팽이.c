#include <stdio.h>

int main(void) {
    int MAX_NUM = 9;
    int ARR_SIZE = 5;
    int x = 2;
    int y = 2;
    int value = 2;
    int num = 1;
    int arr[5][5];
    arr[2][2] = 1;

    for (int k = 0; k < MAX_NUM; ++k) {
        printf("%d th\n", k);
        if (k % 4 == 0) {
            printf("\tn\n");
            for (int i = 0; i < num; ++i) {
                y--;
                arr[y][x] = value++;
                printf("\t\t(%d, %d)\n", y, x);
            }
        } else if (k % 4 == 1) {
            printf("\te\n");
            for (int i = 0; i < num; ++i) {
                x++;
                arr[y][x] = value++;
                printf("\t\t(%d, %d)\n", y, x);
            }
        } else if (k % 4 == 2) {
            printf("\ts\n");
            for (int i = 0; i < num; ++i) {
                y++;
                arr[y][x] = value++;
                printf("\t\t(%d, %d)\n", y, x);
            }
        } else if (k % 4 == 3) {
            printf("\tw\n");
            for (int i = 0; i < num; ++i) {
                x--;
                arr[y][x] = value++;
                printf("\t\t(%d, %d)\n", y, x);
            }
        }

        if (k % 2 == 1 && k != 7) {
            num++;
        }
    }

    for (int i = 0; i < ARR_SIZE; ++i) {
        for (int j = 0; j < ARR_SIZE; ++j) {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
