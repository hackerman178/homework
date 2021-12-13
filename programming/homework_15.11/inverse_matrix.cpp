#include <iostream>
void checkdiag(double** m, int n, int k) {
	int yea = 0;
	for (int l = k; l < n; ++l) {
		if (!m[k][k]) {
			yea++;
			for (int j = k + 1; j < n; ++j) {
				if (m[k][j] != 0) {
					yea++;
					for (int h = 0; h < n; ++h) {
						std::swap(m[h][j], m[h][k]);
					}
				}
			}
		}
	}
}
void swaprow(double** m,double **m1, int k,int n) {
	int yea = 0;
	for (int v = k+1; v < n; ++v) {
		if (m[v][k]) {
			for (int i = 0; i < n; ++i) {

				for (int j = 0; j < n; ++j) {
					std::swap(m[i][j], m[k][j]);
					std::swap(m1[i][j], m1[k][j]);
				}
			}
		}
		if(yea) break;
	}
}
bool det_(double** m, int n) {
	for (int i = 0; i < n; ++i) {
		if (!m[i][i]) return false;
	}
	return true;
}
bool det(double** m, int n) {
	int kef = 0, p = -1, k = 0;
	double h;
	while (k < n) {
		++p;
		if(!k && m[0][0] == 0) checkdiag(m, n, k);
		for (int i = k + 1; i < n; ++i) {
			h = m[i][p] / m[p][p];
			for (int j = 0; j < n; ++j) {
				m[i][j] -= m[p][j] * h;
				if (fabs(m[i][j]) < 1e-5) m[i][j] = 0;
			}
		}
		++k;
		checkdiag(m, n, k);
	}
	if (det_(m,n)) return true;
	return false;
}

void div_str(double** m, double** m1,int n,int i) {
		double h = m[i][i];
		for (int j = 0; j < n; ++j) {
			m[i][j] /= h;
			m1[i][j] /= h;
	}
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
	double** m = new double* [n];
	srand(time(NULL));
	for (int i = 0; i < n; ++i) {
		m[i] = new double[n];
		for (int j = 0; j < n; ++j) {
			m[i][j] = rand() % 10+0.1 ;
		}
	}
	printmatrix(m, n);

	return m;
}
double** creatematrix1( int n) {
	double** m1=new double*[n];
	for (int i = 0; i < n; ++i) {
		m1[i] = new double[n];
		for (int j = 0; j < n; ++j) {
			if (i != j) m1[i][j] = 0;
			else m1[i][j] = 1;
		}
	}
	return m1;
}
void inv(double** m, double** m1, int n) {
	double h;
	for (int k = 0; k < n; ++k) {
		if (!m[k][k]) { swaprow(m, m1, k, n); }
		div_str(m, m1, n, k);
		for (int i = 0; i < n; ++i) {
			if (i != k) {
				h = m[i][k];
				for (int j = 0; j < n; ++j) {
					m[i][j] -= m[k][j] * h;
					m1[i][j] -= m1[k][j] * h;
					if (fabs(m[i][j]) < 1e-5) m[i][j] = 0;
					if (fabs(m1[i][j]) < 1e-5) m1[i][j] = 0;
				}
			}
		}
	}
	printmatrix(m1, n);
}
void dlt(double** m,double** m1, double** g,int n) {
	for (int i = 0; i < n; ++i){
		delete[] m[i];
		delete[] g[i];
		delete[] m1[i];
	   }
	delete[] m1; delete[] m; delete[] g;
}
double** copy(double** m, int n) {
	double** g = new double* [n];
	for (int i = 0; i < n; ++i)
		g[i] = new double[n];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			g[i][j] = m[i][j];
	}
	return g;
}
int main()
{
	int n, var;
	std::cout << "input size of matrix = ";
	do { std::cin >> n; } while (n < 1);
	std::cout << "keyboard input or random matrix, choose 0 or 1: ";
	do { std::cin >> var; } while (var != 0 && var != 1);
	if (var) {
		double** m = creatematrix(n);
		double** m1 = creatematrix1(n);
		double** g = copy(m, n);
		std::cout << std::endl;
		if (det(g, n)) inv(m, m1, n);
		else std::cout << "Inverse matrix does not exist";
		dlt(m, m1,g, n);
	}
	else {
		double** m = new double* [n];
		for (int i = 0; i < n; ++i)
			m[i] = new double[n];
		for (int i = 0; i < n; ++i) {
			std::cout << i + 1 << "row " << std::endl;
			for (int j = 0; j < n; ++j) {
				std::cin >> m[i][j];
			}
		}
			std::cout << std::endl;
			printmatrix(m, n);
			double** m1 = creatematrix1(n);
			double** g = copy(m, n);
			if (det(g, n)) inv(m, m1, n);
			else std::cout << "Inverse matrix does not exist";
			dlt(m, m1,g, n);
		}
}


