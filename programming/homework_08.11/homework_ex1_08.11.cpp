#include<iostream>
void printarray(int** M,int n,int m){
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			std::cout << M[i][j]<<' ';
		std::cout << std::endl;
	}
}
int ff1(int x) {
	int n = 0;
	if (x < 0) { ++n; x = -x; }
	while (x) {
		x /= 10; ++n;
	}
	return n ? n : 1;
}
void fillArray(int** M, int n, int m) {
	int count = 0;
	int i = 0, j = 0, k = 0;
	do {
		++k;
		for (j = k - 1; j < m - k + 1; ++j) M[k-1][j] = ++count;
		for (i = k; i < n-k+1; ++i) M[i][m-k] = ++count;
		for (j = m - k-1; j > k-2; --j) M[n-k][j] = ++count;
		for (i = n - k-1; i > k-1; --i) M[i][k-1] = ++count;

	} while (count <n * m);
	
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