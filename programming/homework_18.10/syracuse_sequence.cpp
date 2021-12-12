#include<iostream>
int main()
{
	int n;
	std::cout << "input n= ";
	std::cin >> n;
	std::cout << n << " ";
	int m = n;
	int k = 1;
	while(n!=1) {
		if (n % 2 == 0)  n /= 2;
		else { n *= 3; n++; }
		std::cout << n << " ";
		k++;
		if (n > m)  m = n; 
	}
	std::cout << std::endl;
	std::cout << "top= " << m << " " << "k=  " << k;
}