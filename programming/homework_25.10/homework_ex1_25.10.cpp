#include<iostream>
int main()
{
	int year, day, month;
	do {
		std::cout << "input year: ";  std::cin >> year;
		std::cout << "input month: ";  std::cin >> month;
		std::cout << "input day: "; std::cin >> day;
	} while (month <= 0 or month > 12 or day > 31 or day < 1);
	int a = (14 - month) / 12;
	int y = year - a;
	int m = month + 12 * a - 2;
	int d = (day + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7;
	int k = d;
	for (int i = year+1;; ++i) {
		y = i - a;
		m = month + 12 * a - 2;
		d = (day + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7;
		if (k == d) {
			std::cout << i;
			break;
		}
	}
}
