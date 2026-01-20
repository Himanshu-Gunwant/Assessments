#include <stdio.h>

int toSparse(int mat[10][10], int r, int c, int sp[50][3]) {
    int k = 1;
    sp[0][0] = r;
    sp[0][1] = c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (mat[i][j] != 0) {
                sp[k][0] = i;
                sp[k][1] = j;
                sp[k][2] = mat[i][j];
                k++;
            }
        }
    }
    sp[0][2] = k - 1;
    return k;
}

int addSparse(int a[50][3], int b[50][3], int c[50][3]) {
    int i = 1, j = 1, k = 1;
    c[0][0] = a[0][0];
    c[0][1] = a[0][1];

    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] == b[j][0] && a[i][1] == b[j][1]) {
            int sum = a[i][2] + b[j][2];
            if (sum != 0) {
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = sum;
                k++;
            }
            i++;
            j++;
        } else if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++;
            k++;
        } else {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++;
            k++;
        }
    }

    while (i <= a[0][2]) {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        i++;
        k++;
    }

    while (j <= b[0][2]) {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        j++;
        k++;
    }

    c[0][2] = k - 1;
    return k;
}

void displaySparse(int sp[50][3]) {
    int n = sp[0][2];
    for (int i = 0; i <= n; i++)
        printf("%d %d %d\n", sp[i][0], sp[i][1], sp[i][2]);
}

int main() {
    int r = 3, c = 3;

    int m1[10][10] = {
        {1, 0, 0},
        {0, 2, 0},
        {0, 0, 3}
    };

    int m2[10][10] = {
        {0, 4, 0},
        {0, 0, 5},
        {6, 0, 0}
    };

    int s1[50][3], s2[50][3], sum[50][3];

    toSparse(m1, r, c, s1);
    toSparse(m2, r, c, s2);
    addSparse(s1, s2, sum);

    displaySparse(sum);

    return 0;
}
