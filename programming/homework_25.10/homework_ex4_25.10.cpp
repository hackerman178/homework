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
	case 1: str = " ���"; break;
	case 2: str = " ������"; break;
	case 3: str = " ������"; break;
	case 4: str = " ���������"; break;
	case 5: str = " �������"; break;
	case 6: str = " ��������"; break;
	case 7: str = " �������";break;
	case 8: str = " ���������"; break;
	case 9: str = " ���������";break;
		}
		return str;
}
std::string second(int k) {
	std::string str;
	switch (k) {
	case 1: str = " ������"; break;
	case 2: str = " ��������"; break;
	case 3: str = " ��������"; break;
	case 4: str = " �����"; break;
	case 5: str = " ���������"; break;
	case 6: str = " ����������"; break;
	case 7: str = " ���������"; break;
	case 8: str = " �����������"; break;
	case 9: str = " ���������"; break;
	}
	return str;
}
std::string first(int k)
{
	std::string str;
	switch (k)
	{
	case 1: str = " ����"; break;
    case 2: str = " ���"; break;
	case 3: str = " ���"; break;
	case 4: str = " ������"; break;
	case 5: str = " ����"; break;
	case 6: str = " �����"; break;
	case 7: str = " ����"; break;
	case 8: str = " ������"; break;
	case 9: str = " ������"; break;
	}
	return str;
}
std::string secondfirst(int k)
{
	std::string str;
	switch (k)
	{
	case 0: str = " ������"; break;
	case 1: str = " �����������";
	case 2: str = " ����������"; break;
	case 3: str = " ����������"; break;
	case 4: str = " ������������"; break;
	case 5: str = " ����������"; break;
	case 6: str = " �����������"; break;
	case 7: str = " ����������"; break;
	case 8: str = " ������������"; break;
	case 9: str = " ������������"; break;
	}
	return str;
}
std::string first2(int k)
{
	std::string str;
	switch (k)
	{
	case 1: str = " ����"; break;
	case 2: str = " ���"; break;
	case 3: str = " ���"; break;
	case 4: str = " ������"; break;
	case 5: str = " ����"; break;
	case 6: str = " �����"; break;
	case 7: str = " ����"; break;
	case 8: str = " ������"; break;
	case 9: str = " ������"; break;
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
		if (n == 1000000000) std::cout << "���� ��������";
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
					num += secondfirst(tmp) + " ���������";
					l = l - 5;}
				else {
					tmp = (n / pow(l - 1)) % 10;
					num += secondfirst(tmp) + " ���������";
					l = l - 2;}
				}
			else { 
				 tmp = (n / pow(l)) % 10;
				num += second(tmp); --l; }
		}

		if (l == 6) {
			 tmp = (n / pow(l)) % 10;
			if (tmp == 1)  num += first(tmp) + " �������";
			else if (tmp == 0 || tmp>4) num += first(tmp) + " ���������";
			else if (tmp <= 4)  num += first(tmp) + " �������a";
			--l;
			if (_g(l, n) == 3) l = l - 3;
		}

		if (l == 5) { tmp = (n / pow(l)) % 10; num += third(tmp); --l; }

		if (l == 4) {
			int tmp = (n / pow(l)) % 10;
			if (tmp == 1) {
				int tmp = (n / pow(l-1)) % 10; 
				num += secondfirst(tmp) + " �����"; l = l - 2; }
			else { 
				int tmp = (n / pow(l)) % 10; 
				num += second(tmp); --l; }
		}

		g = second((n / pow(l + 1)) % 10);
		if (g != "" || g!="0") h = 1; else h = 0;

		if (l == 3) {
			int tmp = (n / pow(l)) % 10;
			if (h == 1) {
				if (tmp == 0)  num += first2(tmp) + " �����";
				else if (tmp == 1)  num += first2(tmp) + " ������";
				else if (tmp < 5)  num += first2(tmp) + " ������";
				else if (tmp >= 5)  num += first2(tmp) + " �����";
			}
			else {
				if (tmp == 0)  num += first(tmp) + " �����";
				else if (tmp == 1)  num += first(tmp) + " ������";
				else if (tmp < 5)  num += first(tmp) + " ������";
				else if (tmp >= 5)  num += first(tmp) + " �����";
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