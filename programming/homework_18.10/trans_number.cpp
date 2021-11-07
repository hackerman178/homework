#include<iostream>
int main()
{
	int n, x;
	do {
		std::cout << "input x= ";
		std::cin >> x;
		std::cout << "input n= ";
		std::cin >> n;
	} while (n < 2 or n>16 or x < 0);

    int a = x, m = 0;
    do
    {
        ++m;
        a /= n;
    } while (a > 0);

    int* A = new int[m];

    for (int i = 0; i <m; ++i)
    {
        A[i] = x % n;
        x /= n;
    }

    for (int i = m - 1; i > -1; --i)
    {
        if (A[i] < 10) {
            std::cout << A[i];
        }
        else {
            std::cout << char('A' + A[i] - 10);
        }
    }
    delete[] A;
}