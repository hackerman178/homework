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
void dlt(double** m, int n) {
	for (int i = 0; i < n; ++i)
		delete[] m[i];
	delete[] m;

}
void printmatrix(double** m, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cout << m[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
double** creatematrix(int n) {
	double** m= new double*[n];
	srand(time(NULL));
	for (int i = 0; i < n; ++i) {
		m[i] = new double[n];
		for (int j = 0; j < n; ++j) {
			m[i][j] = rand()%12+0.1;
		}
	}
	printmatrix(m, n);
	return m;
}
bool check0(double** m, int n) {
	for (int i = 0; i < n; ++i)
		if (!m[i][i]) return false;
	return true;
}
void det_(double** m, int n,int kef) {
	double s = 1.0;
	if (check0(m, n)) {
		for (int i = 0; i < n; ++i) {
			s *= m[i][i];
		}
	}
	else s = 0;
	if(kef%2)
	std::cout << "determinant"<<-s;
	else std::cout << "determinant = " << s;
}
 void det(double** m, int n) {
	int kef = 0, p = -1, k = 0;
	double h;
	while (k < n) {
		++p;
		if(m[0][0]==0) if(checkdiag(m, n, k)) kef += 1;
		for (int i = k + 1; i < n; ++i) {
			h = m[i][p] / m[p][p];
			for (int j = 0; j < n; ++j) {
				m[i][j] -= m[p][j] * h;
				if (fabs(m[i][j]) < 1e-5) m[i][j] = 0;
			}
		}
		++k;
		if (checkdiag(m, n, k)) kef += 1;
	}
	printmatrix(m, n);
	det_(m, n, kef);
}
int main(){
    int n,var;
	std::cout << "input positive size of matrix = ";
	do { std::cin >> n; } while (n < 1);
	std::cout << "keyboard input or random matrix, choose 0 or 1: ";
	do { std::cin >> var; } while (var != 0 && var != 1);
	if (var) {
		double** m = creatematrix(n);
		std::cout << std::endl;
		if (n == 1) { std::cout << "Determinant = " << m[0][0]; dlt(m, n); return 0; }
		if (n == 2) { std::cout << "Determinant = " << m[0][0] * m[1][1] - m[0][1] * m[1][0]; dlt(m, n); return 0; }
		det(m, n);
		dlt(m, n);
	}
	else {
		double** m = new double* [n];
		for (int i = 0; i < n; ++i)
			m[i] = new double[n];
		for (int i = 0; i < n; ++i) {
			std::cout << i + 1 << " row " << std::endl;
			for (int j = 0; j < n; ++j) {
				std::cin >> m[i][j];
			}
		}
		std::cout << std::endl;
		printmatrix(m, n);
		if (n == 1) { std::cout << "Determinant = " << m[0][0]; dlt(m, n); return 0; }
		if (n == 2) { std::cout << "Determinant = " << m[0][0] * m[1][1] - m[0][1] * m[1][0]; dlt(m, n); return 0; }
		det(m, n);
		dlt(m, n);
	}
}