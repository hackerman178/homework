#include<iostream>
int _u1(int N)
{
	int S = 0, i;
	for (i = 1;; ++i) {
		S += i * i;
		if (S >= N)  break;
	}
	return i;
}
int _u2(int N)
{
	int S = 0, i;
	for (i = 1;; ++i) {
		S += i * i;
		if (S >= N) break;
	}
	S -= i * i;
	return S;
}
int _u3(int N)
{
	int i, k = 0, S = 0;
	for (i = 1;; ++i) {
		S += i * i; k += i;
		if (S >= N) break;
	}
	k =k- i + 1;;
	return k;
}

int main()
{
	int N, numofblock, firstroom, j = 1, firstflofblock;
	std::cout << "input the number of room = ";
	do {
		std::cin >> N;
	} while (N < 1 || N>2000000);
	numofblock = _u1(N); firstroom = _u2(N) + 1; firstflofblock = _u3(N);

	while (firstroom <= N) {
		if(j<=numofblock) {
			if (firstroom != N) { ++j; ++firstroom; }
			else { std::cout << "the serial number of room on the left = " << j << "; the number of floor = " << firstflofblock << std::endl; break; }
		}
		else { j = 1; ++firstflofblock; }
	}
}