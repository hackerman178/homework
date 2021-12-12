#include<iostream>
void shiftarray_pos(int* A, int n, int k) {
	for (int i = 0; i < n - k; ++i) A[i] = i + k;
	int l = -1;
	for (int i = n - k; i < n; ++i) A[i] = ++l;
}
void shiftarray_neg(int* A, int n, int k) {
	for (int i = 0; i < k; ++i)
		A[i]=n-k+i;
	int l = -1;
	for (int i = k; i < n;++i) A[i] = ++l;
}
int main() {
	int k, n;
	std::cout << "input positive n = ";
	do {
		std::cin >> n;
	} while (n < 1);
	std::cout << "input k = ";
	std::cin >> k;
	if (abs(k) > n) {
		if (k > 0) k = k - k / n * n;
		else k = -(abs(k) - abs(k) / n * n);
	}
	int* A = new int[n];
	for (int i = 0; i < n; ++i)  A[i] = i;
	if (k > 0) shiftarray_pos(A, n, k);
	if(k<0) shiftarray_neg(A, n, abs(k));
	for (int i = 0; i < n; ++i)  std::cout << A[i] << " ";
	return 0;
}