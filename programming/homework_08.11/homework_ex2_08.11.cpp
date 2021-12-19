#include<iostream>
int main() {
	int k, n;
	std::cout << "input positive n = ";
	do {
		std::cin >> n;
	} while (n < 1);
	std::cout << "input k = ";
	std::cin >> k;
	if (k > 0) k %= n;
	else k = n + k % n;
	int* A = new int[n];
	for (int i = 0; i < n; ++i)  A[i] = i;
	
	  for (int i = 0, j = k - 1; i < k / 2; --j, ++i) std::swap(A[i], A[j]);

		for (int i = k, j=n-1; i<(n+k)/2; --j, ++i) std::swap(A[i], A[j]);

			for (int i = 0, j=n-1; i < n/2; --j, ++i) std::swap(A[i], A[j]);

	for (int i = 0; i < n; ++i)  std::cout << A[i] << " ";
	return 0;
}