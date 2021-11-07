#include<iostream>
#include<time.h>
int main()
{
	unsigned long long N = 0, hits = 0, x, y,r;
	double a = 1.0, pi = 4.0, eps;
	std::cout << "input epsilon " << std::endl;
	std::cin >> eps;
	std::cout << "input radius" << std::endl;
	std::cin >> r;
	time_t tic = time(NULL);
	do {
		++N;
		if (N % 2 == 0) {
			a = 4.0 / (2.0 * double(N) + 1.0);
		}
		else {
			a =- 4.0 / (2.0 * double(N) + 1.0);
		}
		pi += a;
	} while (fabs(a)>=eps);
	++N;
	std::cout << "Pi = " << pi << std::endl;
	time_t toc = time(NULL);
	std::cout << "time1: " << toc - tic << std::endl;
	std::cout << "N = " << N << std::endl;
	time_t tac = time(NULL);
	for (unsigned long long i = 0; i < N; ++i) {
		x = rand() % (r + 1);
		y = rand() % (r + 1);
		if (x * x + y * y <= r * r) {
			++hits;
		}
	}

	std::cout << "Pi = " << 4.0 * double(hits) / double(N) << std::endl;
	time_t tuc = time(NULL);
	std::cout << "time2: "<< tuc - tac << std::endl;
	return 0;

}