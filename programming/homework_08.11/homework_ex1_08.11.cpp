#include<iostream>
void printarray(int** M, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            std::cout << M[i][j] << ' ';
        std::cout << std::endl;
    }
}
void fillArray(int** M, int rows, int columns) {
    int j = -1, i = 0, side = 0, count = 1, updown = rows - 1, rightleft = columns;

    while (updown != -1 && rightleft != -1) {

        if (side == 0) {
            for (int k = 0; k < rightleft; ++k) {
                ++j;
                M[i][j] = count++;
            }
            --rightleft;
        }
        if (side == 1) {
            for (int k = 0; k < updown; ++k) {
                ++i;
                M[i][j] = count++;
            }
            --updown;
        }
        if (side == 2) {
            for (int k = rightleft - 1; k > -1; --k) {
                --j;
                M[i][j] = count++;
            }
            --rightleft;
        }
        if (side == 3) {
            for (int k = updown - 1; k > -1; --k) {
                --i;
                M[i][j] = count++;
            }
            --updown;
        }
        ++side;
        if (side == 4) side = 0;
    }
}
int** createarray(int n, int m) {
    int** M = new int* [n];
    for (int i = 0; i < n; ++i) {
        M[i] = new int[m];
    }
    return M;
}

int main()
{
    int n, m, k = 0;
    std::cout << "input number of rows = ";
    do {
        std::cin >> n;
    } while (n < 1);
    std::cout << "input number of columns = ";
    do {
        std::cin >> m;
    } while (m < 1);

    int** M = createarray(n, m);
    fillArray(M, n, m);
    printarray(M, n, m);

    for (int i = 0; i < n; ++i) {
        delete[] M[i];
    }
    delete[]M;
}