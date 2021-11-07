#include<iostream>
int um(int k) {
	int res = 1;
	while (k > 0) {
		res *= 10;
		k--;
	}
	return res;
}
int main()
{
	int x, k = 0, g, n;

	std::cout << "input the number<4000 = ";
	do {
		std::cin >> x;
	} while (x < 0 || x >= 4000);

	g = x;

	while (g > 0) {
		k++; g /= 10;
	}
	int* str = new int[k];
	for (int i = 0; i < k; ++i) str[i] = 0;

	if (k == 4) {
		str[0] = x / um(k - 1); str[1] = x % um(k - 1) / um(k - 2); str[2] = x % um(k - 2) / um(k - 3); str[3] = x % um(k - 3);
	}
	if (k == 3) {
		str[0] = x / 100; str[1] = x % 100 / 10; str[2] = x % 10;
	}
	if (k == 2) {
		str[0] = x / 10; str[1] = x % 10;
	}
	if (k == 1) {
		str[0] = x;
	}
	if (k == 4) {
		if (str[1] == 9) {
			n = str[0]; while (n) { std::cout << "M"; --n; }
			std::cout << "CM";
		}
		else {
			n = str[0]; while (n) { std::cout << "M"; --n; }
		}
		if (str[1] <= 3) {
			n = str[1]; while (n) { std::cout << "C"; --n; }
		}
		if (str[1] == 4) std::cout << "CD";
		if (str[1] == 5) std::cout << "D";
		if (str[1] == 6) std::cout << "DC";
		if (str[1] == 7) std::cout << "DCC";
		if (str[1] == 8) std::cout << "DCCC";

		if (str[2] <= 3) {
			n = str[2]; while (n) { std::cout << "X"; --n; }
		}
		if (str[2] == 4) std::cout << "XL";
		if (str[2] == 5) std::cout << "L";
		if (str[2] == 6) std::cout << "LX";
		if (str[2] == 7) std::cout << "LXX";
		if (str[2] == 8) std::cout << "LXXX";
		if (str[2] == 9) std::cout << "XC";

		if (str[3] <= 3) {
			n = str[3]; while (n) { std::cout << "I"; --n; }
		}
		if (str[3] == 4) std::cout << "IV";
		if (str[3] == 5) std::cout << "V";
		if (str[3] == 6) std::cout << "VI";
		if (str[3] == 7) std::cout << "VII";
		if (str[3] == 8) std::cout << "VIII";
		if (str[3] == 9) std::cout << "IX";
	}

	if (k == 3) {
		if (str[0] <= 3) {
			n = str[0]; while (n) { std::cout << "C"; --n; }
		}
		if (str[0] == 4) std::cout << "CD";
		if (str[0] == 5) std::cout << "D";
		if (str[0] == 6) std::cout << "DC";
		if (str[0] == 7) std::cout << "DCC";
		if (str[0] == 8) std::cout << "DCCC";
		
		if (str[1] <= 3) {
			n = str[1]; while (n) { std::cout << "X"; --n; }
		}
		if (str[1] == 4) std::cout << "XL";
		if (str[1] == 5) std::cout << "L";
		if (str[1] == 6) std::cout << "LX";
		if (str[1] == 7) std::cout << "LXX";
		if (str[1] == 8) std::cout << "LXXX";
		if (str[1] == 9) std::cout << "XC";

		if (str[2] <= 3) {
			n = str[2]; while (n) { std::cout << "I"; --n; }
		}
		if (str[2] == 4) std::cout << "IV";
		if (str[2] == 5) std::cout << "V";
		if (str[2] == 6) std::cout << "VI";
		if (str[2] == 7) std::cout << "VII";
		if (str[2] == 8) std::cout << "VIII";
		if (str[2] == 9) std::cout << "IX";
	}
	if (k == 2) {
		if (str[0] <= 3) {
			n = str[0]; while (n) { std::cout << "X"; --n; }
		}
		if (str[0] == 4) std::cout << "XL";
		if (str[0] == 5) std::cout << "L";
		if (str[0] == 6) std::cout << "LX";
		if (str[0] == 7) std::cout << "LXX";
		if (str[0] == 8) std::cout << "LXXX";
		if (str[0] == 9) std::cout << "XC";

		if (str[1] <= 3) {
			n = str[1]; while (n) { std::cout << "I"; --n; }
		}
		if (str[1] == 4) std::cout << "IV";
		if (str[1] == 5) std::cout << "V";
		if (str[1] == 6) std::cout << "VI";
		if (str[1] == 7) std::cout << "VII";
		if (str[1] == 8) std::cout << "VIII";
		if (str[1] == 9) std::cout << "IX";
	}
	if (k == 1) {
		if (str[0] <= 3) {
			n = str[0]; while (n) { std::cout << "I"; --n; }
		}
		if (str[0] == 4) std::cout << "IV";
		if (str[0] == 5) std::cout << "V";
		if (str[0] == 6) std::cout << "VI";
		if (str[0] == 7) std::cout << "VII";
		if (str[0] == 8) std::cout << "VIII";
		if (str[0] == 9) std::cout << "IX";
	}
	delete[]str;
}