#include <fstream>
#include <iostream>
#include <string>

int main() {

	std::ifstream fin("in.txt");
	std::string s;
	std::ofstream fout("out.txt");

	fin >> s;
	int n = std::stoi(s);
	fout << n << std::endl;

	int* mas = new int[n];

	for (int i = 0; i < n; i++) {
		fin >> mas[i];
	}

	int temp;
	temp = mas[0];
	for (int i = 0; i < n - 1; i++) {
		mas[i] = mas[i + 1];
	}
	mas[n - 1] = temp;

	for (int i = 0; i < n; i++) {
		fout << mas[i] << "  ";
	}

	fout << std::endl;

	int n2 = std::stoi(s);
	fout << n2 << std::endl;
	int* mas2 = new int[n2];

	for (int i = 0; i < n2; i++) {
		fin >> mas2[i];
	}

	int temp2;
	temp2 = mas2[n - 1];
	for (int i = n - 1; i > 0; i--) {
		mas2[i] = mas2[i - 1];
	}
	mas2[0] = temp2;

	for (int i = 0; i < n; i++) {
		fout << mas2[i] << "  ";
	}

	fout << std::endl;

	delete[] mas;
	delete[] mas2;

	fin.close();
	fout.close();
}