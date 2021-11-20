#include<iostream>
void shiftarray(int* A, int n, int k) {
	int h = 0;
	for (int i = n; i < n + k; ++i) {
		A[i] = A[h]; 
		A[h] = 0;
		++h; 
		if (h>k) break;
	}
}
int main() {
	int k, n;
	std::cout << "input positive n = ";
	std::cin >> n;
	std::cout << "input positive k less than n = ";
	std::cin >> k;
	int* A = new int[n+k];
	for (int i = 0; i < n; ++i) 
		A[i] = i;
	for (int i = n; i < n + k; ++i) A[i] = 0;
	shiftarray(A, n, k);
	for (int i = k; i < n + k; ++i)
		std::cout << A[i] << " ";
}