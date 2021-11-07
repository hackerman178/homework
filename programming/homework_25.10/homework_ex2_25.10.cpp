#include<iostream>
int main()
{
	int a, y, m, k = 0, h = 0, n, j = 0;
	double M;
	for (int year = 1900; year < 2000; ++year) {
		for (int month = 1; month <= 12; ++month) {
			a = (14 - month) / 12;
			y = year - a;
			m = month + 12 * a - 2;
			if ((13 + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7 == 5) ++k;
		}
	}
	std::cout << "input number of month = ";
	std::cin >> n;
	for (int year = 1900; year < 2000; ++year) {
		a = (14 - n) / 12;
		y = year - a;
		m = n + 12 * a - 2;
		if ((13 + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7 == 5) ++j;
		else h++;
	}
	M = (double)j / (double)(j + h);
	std::cout << "probability of Friday 13 in the specified month: " << M << std::endl;
	std::cout << "the number of Fridays 13 in the 20th century: " << k;
}