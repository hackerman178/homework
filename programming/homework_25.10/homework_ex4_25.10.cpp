#include<iostream>
#include<string>
int pow(int k) {
	int res = 1;
	for (int i = 0; i < k; ++i) { res *= 10; }
	return res;
}
std::string third(int k) {
	std::string str;
	switch (k){
	case 1: str = " сто"; break;
	case 2: str = " двести"; break;
	case 3: str = " триста"; break;
	case 4: str = " четыреста"; break;
	case 5: str = " п€тьсот"; break;
	case 6: str = " шестьсот"; break;
	case 7: str = " семьсот";break;
	case 8: str = " восемьсот"; break;
	case 9: str = " дев€тьсот";break;
		}
		return str;
}
std::string second(int k) {
	std::string str;
	switch (k) {
	case 1: str = " дес€ть"; break;
	case 2: str = " двадцать"; break;
	case 3: str = " тридцать"; break;
	case 4: str = " сорок"; break;
	case 5: str = " п€тьдес€т"; break;
	case 6: str = " шестьдес€т"; break;
	case 7: str = " семьдес€т"; break;
	case 8: str = " восемьдес€т"; break;
	case 9: str = " дев€носто"; break;
	}
	return str;
}
std::string first(int k)
{
	std::string str;
	switch (k)
	{
	case 1: str = " один"; break;
    case 2: str = " два"; break;
	case 3: str = " три"; break;
	case 4: str = " четыре"; break;
	case 5: str = " п€ть"; break;
	case 6: str = " шесть"; break;
	case 7: str = " семь"; break;
	case 8: str = " восемь"; break;
	case 9: str = " дев€ть"; break;
	}
	return str;
}
std::string secondfirst(int k)
{
	std::string str;
	switch (k)
	{
	case 0: str = " дес€ть"; break;
	case 1: str = " одиннадцать";
	case 2: str = " двенадцать"; break;
	case 3: str = " тринадцать"; break;
	case 4: str = " четырнадцать"; break;
	case 5: str = " п€тнадцать"; break;
	case 6: str = " шестнадцать"; break;
	case 7: str = " семнадцать"; break;
	case 8: str = " восемнадцать"; break;
	case 9: str = " дев€тнадцать"; break;
	}
	return str;
}
std::string first2(int k)
{
	std::string str;
	switch (k)
	{
	case 1: str = " одна"; break;
	case 2: str = " две"; break;
	case 3: str = " три"; break;
	case 4: str = " четыре"; break;
	case 5: str = " п€ть"; break;
	case 6: str = " шесть"; break;
	case 7: str = " семь"; break;
	case 8: str = " восемь"; break;
	case 9: str = " дев€ть"; break;
	}
	return str;
}
 int _g(int l,long long n) {
	int k=0;
	std::string g;
	for (int i = 0; i < 3; ++i) {
		g = second((n / pow(l-i)) % 10);
		if (g == "") ++k;
	}
	return k;
}

int main()
{
	setlocale(LC_ALL, "rus");
	std::string num,g;
	long long n=0;
		std::cout << "input number <1 000.000.000 = ";
		do {
			std::cin >> n;
		} while (n < 0 || n>1000000000);
		long long x = n;
		int k=0;
		while (x > 0) {
			++k; x /= 10;
		}
		if (n == 1000000000) std::cout << "один миллиард";
		int l = k - 1, h;
		long long tmp = n;

		if (l == 8) {
			 tmp = (n / pow(l)) % 10;;
			num += third(tmp);
			--l;
		}

		if (l == 7) {
			 tmp = (n / pow(l)) % 10;
			if (tmp == 1) { 
				if (_g(l - 2, n) == 3) {
					tmp = (n / pow(l - 1)) % 10;
					num += secondfirst(tmp) + " миллионов";
					l = l - 5;}
				else {
					tmp = (n / pow(l - 1)) % 10;
					num += secondfirst(tmp) + " миллионов";
					l = l - 2;}
				}
			else { 
				 tmp = (n / pow(l)) % 10;
				num += second(tmp); --l; }
		}

		if (l == 6) {
			 tmp = (n / pow(l)) % 10;
			if (tmp == 1)  num += first(tmp) + " миллион";
			else if (tmp == 0 || tmp>4) num += first(tmp) + " миллионов";
			else if (tmp <= 4)  num += first(tmp) + " миллионa";
			--l;
			if (_g(l, n) == 3) l = l - 3;
		}

		if (l == 5) { tmp = (n / pow(l)) % 10; num += third(tmp); --l; }

		if (l == 4) {
			int tmp = (n / pow(l)) % 10;
			if (tmp == 1) {
				int tmp = (n / pow(l-1)) % 10; 
				num += secondfirst(tmp) + " тыс€ч"; l = l - 2; }
			else { 
				int tmp = (n / pow(l)) % 10; 
				num += second(tmp); --l; }
		}

		g = second((n / pow(l + 1)) % 10);
		if (g != "" || g!="0") h = 1; else h = 0;

		if (l == 3) {
			int tmp = (n / pow(l)) % 10;
			if (h == 1) {
				if (tmp == 0)  num += first2(tmp) + " тыс€ч";
				else if (tmp == 1)  num += first2(tmp) + " тыс€ча";
				else if (tmp < 5)  num += first2(tmp) + " тыс€чи";
				else if (tmp >= 5)  num += first2(tmp) + " тыс€ч";
			}
			else {
				if (tmp == 0)  num += first(tmp) + " тыс€ч";
				else if (tmp == 1)  num += first(tmp) + " тыс€ча";
				else if (tmp < 5)  num += first(tmp) + " тыс€чи";
				else if (tmp >= 5)  num += first(tmp) + " тыс€ч";
			}
			--l;
		}

		if (l == 2) {
			int tmp = (n / pow(l)) % 10;
			num += third(tmp); --l;
		}

		if (l == 1) {
			int tmp = (n / pow(l)) % 10;
			if (tmp == 1) { 
				int tmp = (n / pow(l - 1)) % 10;
				num += secondfirst(tmp); l = l - 2; }
			else { 
				num += second(tmp); --l; }
		}
		
		if (l == 0) { int tmp = (n/pow(l)) %10; num += first(tmp); }
		std::cout << num << std::endl;
}