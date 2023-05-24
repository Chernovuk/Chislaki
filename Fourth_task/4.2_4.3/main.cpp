#include <iostream>
#include <iomanip>

#include "header.h"
#include "functions.h"


int main() {
	std::cout << std::fixed << std::setprecision(16);

	std::cout << "*********INCLUDED PART OF TASK 4.3*********\n";

	int flag;
	do {
		std::cout << "Input integration confines a and b: ";
		double a, b;
		std::cin >> a >> b;

		std::cout << "Input m - number of sections of [a;b]: ";
		size_t m;
		std::cin >> m;

		double h = (b - a) / m;
		std::cout << "Length of step = " << h << "\n";


		size_t l;
		std::cout << "Input how many times you would like to increase m: ";
		std::cin >> l;


		int switching_fs;
		do {
			std::cout << "Choose function which you want to integrate:\n" <<
				"1. f = ln(x)*x^3\n" << "2. f = 7\n" << "3. f = 4*x - 3\n" << "4. f = -x^2 - 8*x + 1\n" << "5. f = 2*x^3 - 5*x - 2\n";
			int chosen;
			std::cin >> chosen;

			std::cout << "Result by all methods = \n";
			print_all(chosen, a, b, m, l);
			std::cout << "If you would like to choose another function, press 1, otherwise 0\n";
			std::cin >> switching_fs;
		} while (switching_fs);

		std::cout << "If you would like to change integration confines and number of sections, press 1. Otherwise press 0\n";
		std::cin >> flag;
	} while (flag);





	return 0;
}