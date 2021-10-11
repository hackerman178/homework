#include<iostream>
int main()
{
	int n, m;
	std::cout << "Input n:";
	std::cin >> n;
	std::cout << "Input m:";
	std::cin >> m;
	std::cout << std::endl;
	int stars = 1;
	int spaces = n - 1;
	//вывод верхней части ромбов и центральной строки
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) 
		{
			for (int k = 0; k < spaces; ++k)
				std::cout << " ";
			for (int k = 0; k < stars; ++k)
				std::cout << "*";
			for (int k = 0; k < spaces; ++k)
				std::cout << " ";
		}
		std::cout << std::endl;

		if (spaces != 0) {
			spaces -= 1;
			stars += 2;
		}
		else {
			spaces += 1;
			stars -= 2;
		}
	}
	//вывод нижней части ромбов 
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m; ++j) 
		{
			for (int k = 0; k < spaces; ++k)
				std::cout << " ";
			for (int k = 0; k < stars; ++k)
				std::cout << "*";
			for (int k = 0; k < spaces; ++k)
				std::cout << " ";
		}
		spaces += 1;
		stars -= 2;
		std::cout << std::endl;
	}
	
}