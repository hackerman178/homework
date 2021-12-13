#include<iostream>
#include<fstream>
std::string to16ch(int b) {
	std::string s;
	int tmp = b % 16;
	b /= 16;
	if (b <=9) s += (b + '0');
	else s += ('F' - 15 + b);
	if (tmp <=9) s += (tmp + '0');
	else s += ('F' -15+tmp);
	return s;
}
std::string num_row(int k) {
	int n=0,l=k;
	std::string num;
	while (l) {  l /= 16; ++n;  }
	int* A = new int[n];
	for (int i = 0; i < n - 1; ++i) { A[i] = k % 16; k /= 16; }
	A[n - 1] = k;
	for (int i = 0; i < n / 2; ++i) std::swap(A[i], A[n - i - 1]);
	for (int i = 0; i < 9 - n; ++i) { num += '0'; }
	for (int i = 0; i < n; ++i) { 
		if (A[i] <=9) num += A[i] + '0';
		else num += 'F' - 15 + A[i];
	}
	num += '0';
	return num;

}
int main(int argc, char* argv[]) {
	char ifname[256];
	char ofname[256];
	if (argc < 2) {
		std::cout << "Source:";
		std::cin.getline(ifname, 256);
	}
	else {
		strcpy_s(ifname, argv[1]);
	}
	if (argc < 3) {
		std::cout << "Destination: ";
		std::cin.getline(ofname, 256);
	}
	else {
		strcpy_s(ofname, argv[2]);
	}
	std::ifstream inFile(ifname,std::ios_base::binary);
	if (!inFile) {
		std::cout << "Can not open file " << ifname << std::endl; return 1;
	}
	std::ofstream outFile(ofname, std::ios_base::binary);
	if (!outFile) {
		std::cout << "Can not open file" << ofname << std::endl;
		inFile.close(); return 2;
	}
	int ch, k = -1,g=0,u=0,f=0;
	while ((ch = inFile.get()) != EOF) {
		if (g % 16==0) {
			k++; outFile << num_row(k); outFile << ": ";
		}
		g++;
		outFile << to16ch(ch); u+=2; outFile << " "; ++u; ++f;
		if (g % 8 == 0 && g % 16 != 0)
		{ 
			outFile << "| "; 
		}
		if (g % 16 == 0) {
			u = 0; f = 0;
		   inFile.seekg(-16,std::ios_base::cur);
		   for (int i = 0; i < 16; ++i) {
			   if ((ch = inFile.get()) <= 32) 
			   { 
				   outFile << ".";  
			   }
			 else { 
				   outFile << (char)ch; 
			   }
		}
		outFile << std::endl;
		}
	}
	if(u!=0){
		if (u < 24) {
			for (int i = 0; i < 24 - u; ++i)
				outFile << " ";
			outFile << "| ";
			for (int i = 0; i < 24; ++i)
				outFile << " ";
		}
		if (u >= 24) {
			for (int i = 0; i < 48-u; ++i)
				outFile << " ";
		}
		
		inFile.clear();
		inFile.seekg(g-f, std::ios_base::beg);
		while ((ch = inFile.get()) != EOF) {
			if (ch <= 32) { outFile << "."; }
			else { outFile << (char)ch; }
		}
	}
		inFile.close();
		outFile.close();
}