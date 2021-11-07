#include<iostream>
int main()
{
	int n;
	std::cout << "input n= ";
	std::cin >> n;
	std::cout << n << " ";
	int m = n;
	int k = 1;
	for (int i = 0; ; ++i) {
		if (n % 2 == 0) {
			n /= 2;
		}
		else {
			n *= 3; n++;
		}
		std::cout << n << " ";
		k++;
		if (n > m) { m = n; }
		if (n == 1) break;
	}
	std::cout << std::endl;
	std::cout << "top= " << m << " " << "k=  " << k;
}