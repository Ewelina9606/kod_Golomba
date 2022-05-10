#include <iostream>
#include <cmath>
#include <vector>

int main() {
	std::string wybor;
	do {
		int wersja;
		std::string x;
		int m;

		char znak;
		int liczba;
		int prefiks, sufiks;
		int r;
		int k, b, v;
		std::vector <int> bin;

		std::cout << "Podaj wersje: " << std::endl;
		std::cin >> wersja;
		std::cout << "Podaj liczbe: " << std::endl;
		std::cin >> x;
		std::cout << "Podaj m: " << std::endl;
		std::cin >> m;

		if (wersja == 1) {
			for (int i = 0; i < x.length(); i++) {
				bin.erase(bin.begin(), bin.end());
				znak = x[i];
				if (znak == 'A' || znak == 'B' || znak == 'C' || znak == 'D' || znak == 'E' || znak == 'F') {
					liczba = (int)znak - 55;
				}
				else {
					liczba = (int)znak - 48;
				}
				for (int j = 0; j < liczba; j++) {
					std::cout << "1";
				}
				std::cout << "0";
				std::cout << " ";
			}
		}
		else if (wersja == 2) {
			for (int i = 0; i < x.length(); i++) {
				bin.erase(bin.begin(), bin.end());
				znak = x[i];
				if (znak == 'A' || znak == 'B' || znak == 'C' || znak == 'D' || znak == 'E' || znak == 'F') {
					liczba = (int)znak - 55;
				}
				else {
					liczba = (int)znak - 48;
				}
				prefiks = floor(liczba / m);
				for (int j = 0; j < prefiks; j++) {
					std::cout << "1";
				}
				std::cout << "0|";
				k = log2(m);
				r = liczba - (prefiks * m);
				if (k <= r) {
					do {
						v = r % 2;
						r = r / 2;
						bin.push_back(v);
					} while (r != 0);
					for (int i = bin.size() - 1; i >= 0; i--) {
						std::cout << bin[i];
					}
				}
				else {
					do {
						v = r % 2;
						r = r / 2;
						bin.push_back(v);
					} while (r != 0);
					for (int z = 0; z < k - bin.size(); z++) {
						std::cout << "0";
					}
					for (int i = bin.size() - 1; i >= 0; i--) {
						std::cout << bin[i];
					}
				}
				std::cout << " ";
			}
		}
		else if (wersja == 3) {
			for (int i = 0; i < x.length(); i++) {
				bin.erase(bin.begin(), bin.end());
				znak = x[i];
				if (znak == 'A' || znak == 'B' || znak == 'C' || znak == 'D' || znak == 'E' || znak == 'F') {
					liczba = (int)znak - 55;
				}
				else {
					liczba = (int)znak - 48;
				}
				prefiks = floor(liczba / m);
				for (int j = 0; j < prefiks; j++) {
					std::cout << "1";
				}
				std::cout << "0|";
				b = ceil(log2(m));
				r = liczba - (prefiks * m);
				//std::cout << "b: " << b << " r: " << r << std::endl;
				if (r < (pow(2, b) - m)) {
					//std::cout << "opcja 1" << " r: " << r << std::endl;
					if (b <= r) {
						do {
							v = sufiks % 2;
							sufiks = sufiks / 2;
							bin.push_back(v);
							//std::cout << sufiks;
						} while (sufiks != 0);
						for (int i = bin.size() - 1; i >= 0; i--) {
							std::cout << bin[i];
						}
					}
					else {
						do {
							v = r % 2;
							r = r / 2;
							bin.push_back(v);
						} while (r != 0);
						for (int z = 0; z < b - 1 - bin.size(); z++) {
							std::cout << "0";
						}
						for (int i = 0; i < bin.size(); i++) {
							std::cout << bin[i];
						}
						/*for (int z = 0; z < b - 1 - r; z++) {
							std::cout << "0";
						}
						for (int j = 0; j < r; j++) {
							std::cout << "1";
						}*/
					}
				}
				else {
					//std::cout << "opcja 2" << std::endl;
					sufiks = r + pow(2, b) - m;
					//std::cout << "sufiks" << sufiks << std::endl;
					if (b < sufiks) {
						/*for (int j = b-1; j > 1; j--) {
							std::cout << "1";
						}
						std::cout << "0";*/
						do {
							v = sufiks % 2;
							sufiks = sufiks / 2;
							bin.push_back(v);
							//std::cout << v;
						} while (sufiks != 0);
						for (int i = bin.size() - 1; i >= 0; i--) {
							std::cout << bin[i];
						}
					}
					else {
						do {
							v = sufiks % 2;
							sufiks = sufiks / 2;
							bin.push_back(v);
							//std::cout << sufiks;
						} while (sufiks != 0);
						for (int z = 0; z < b - bin.size(); z++) {
							std::cout << "0";
						}
						for (int i = bin.size() - 1; i >= 0; i--) {
							std::cout << bin[i];
						}
					}

				}
				std::cout << " ";
			}
		}
		else {
			std::cout << "niepoprawna wersja" << std::endl;
		}
		std::cout << std::endl << "kolejne kodowanie?";
		std::cin >> wybor;
	} while (wybor == "tak" || wybor == "TAK");

	return 0;
}