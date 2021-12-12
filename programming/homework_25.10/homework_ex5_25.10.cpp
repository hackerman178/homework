#include <iostream>
int main()
{
	const int n = 11;
	int a[n] = { 1,11,7,9,8,6,0,2,10,3,5 };//массив от 0 до 11 с пропущенным символом
	int  s2 = 0, s1 = (n * (n + 1)) / 2;
	for (int i = 0; i < 11; ++i) s2 += a[i];
	std::cout << s1 - s2;
}