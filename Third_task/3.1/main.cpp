#pragma once
#include <Windows.h>
#include <string>

#include "First_method.h"
#include "Second_method.h"



int main() {

	SetConsoleTitleA("Algebraic reverse interpolation problem");

	std::cout << std::fixed << std::setprecision(16);

	unsigned int m;	//Кол-во точек в таблице (m = 10)
	std::cout << "Input number of table values: ";
	std::cin >> m;


	double a, b;	//Концы отрезка интерполирования (a = 0, b = 1)
	std::cout << "Input segment boundaries: ";
	std::cin >> a >> b;

	std::cout << "Table of values: \n" << std::setw(15) << "X_i" << std::setw(17) << "f(X_i)\n";
	std::vector <std::pair<double, double>> table_values(m);
	for (int i = 0; i < m; ++i) {
		table_values[i].first = a + (b - a) * i / m;
		table_values[i].second = f(table_values[i].first);
		std::cout << table_values[i].first << "|" << table_values[i].second << "\n";
	}


	int flag;
	do {
		double x;	//Точка интерполирования
		std::cout << "Input interpolation point: ";
		std::cin >> x;
		while (x > -1) {
			std::cout << "Have you ever seen the initial function? You are inputting values out of its range, stupid. Fine, I'm giving you one another try: ";
			std::cin >> x;
		}


		unsigned int n;	//Степень интерполяционного М.Ч. (n = 10)
		std::cout << "Input degree of interpolation polinom (Warning, degree must be less than number of table values, i.e. n < m): ";
		std::cin >> n;
		while (n >= m) {
			std::cout << "Incorrect input, consider condition n < m, try again: ";
			std::cin >> n;
		}

		if (n < m - 1) {
			sort(table_values, x);
			std::cout << "Sorted table of values: \n" << std::setw(15) << "f(X_i)" << std::setw(17) << "X_i\n";
			for (int i = 0; i < m; ++i) {
				std::cout << table_values[i].second << "|" << table_values[i].first << "\n";
			}
		}
		double first_res = f(Newton_poly_correct(n, x, table_values)), f_res = x;
		std::cout << "Value obtained by the first method: " << first_res << "\n" <<
			"Value of absolute error rate: " << abs(first_res - f_res) << "\n\n";
		
		std::cout << "Input value of error rate for the second method: ";
		double epsilon;
		std::cin >> epsilon;
		std::cout << "Value obtained by the second method: ";
		double second_res = f(secants(a, b, epsilon, n, table_values, x));
		std::cout << second_res << "\n" <<
			"Value of absolute error rate: " << abs(second_res - f_res) <<"\n\n";

		std::cout << "If you want to try another interpolation point, enter 1, otherwise 0: ";
		std::cin >> flag;
	} while (flag);
	

	return 0;
}