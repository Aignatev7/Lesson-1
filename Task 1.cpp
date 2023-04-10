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

	while (!fin.eof()) {
		fin >> s;
		fout << s << "  ";
	}
	delete[] mas;

	fin.close();
	fout.close();
}