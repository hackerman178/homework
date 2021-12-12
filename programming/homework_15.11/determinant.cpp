#include<iostream>
int checkdiag(double** m, int n, int k) {
	int yea = 0;
	for (int l = k; l < n; ++l) {
		if (m[k][k] == 0) {
			yea++;
			for (int j = k+1; j < n; ++j) {
				if (m[k][j] != 0) {
					yea++;
					for (int h = 0; h < n; ++h) {
						std::swap(m[h][j], m[h][k]);
					}
			   }
			}
		}
	}if (yea == 2)  return 1;
	else return 0;
}
void printmatrix(double** m, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cout << m[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
double** creatematrix(int n) {
	double** m= new double*[n];
	srand(time(NULL));
	for (int i = 0; i < n; ++i) {
		m[i] = new double[n];
		for (int j = 0; j < n; ++j) {
			m[i][j] = rand()%128+0.1;
		}
	}
	printmatrix(m, n);
	return m;
}
double det(double** m, int n) {
	double s = 1.0;
	for (int i = 0; i < n; ++i) {
		s *= m[i][i];
	}
	return s;
}
int main(){
    int n,kef=0,p=-1,k=0,g;
	double h = 0;
	std::cout << "input positive number of rows = ";
	do { std::cin >> n; } while (n < 1);
	std::cout << "input positive number of cols = ";
	do { std::cin >> g; } while (g < 1);
	if (g != n) { std::cout << "Determinant = 0"; return 0; }
	else n = g;
	double** m = creatematrix(n);
	std::cout << std::endl;
	if (n == 1) {  std::cout << "Determinant = " << m[0][0]; return 0; }
	if (n == 2) {  std::cout << "Determinant = " << m[0][0] * m[1][1] - m[0][1] * m[1][0]; return 0; }
	while (k < n) {
		++p;
		for (int i = k + 1; i < n; ++i) {
			h = m[i][p] / m[p][p];
			for (int j = 0; j < n; ++j) {
				m[i][j] -= m[p][j] * h;
				if (fabs(m[i][j]) < 1e-5) m[i][j] = 0;
			}
		}
		++k;
		if(checkdiag(m, n, k)) kef+=1;
	}
	if (kef % 2) kef = 1;
	else kef = -1;
	std::cout << "Detreminant = "<<det(m, n) * kef;
}