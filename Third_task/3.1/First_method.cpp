#include "First_method.h"


void sort(std::vector<std::pair<double, double>>& table, double x) {	//—ортировка таблицы значений относительно рассто€ни€ до точки интерпол€ции
	for (int i = 0; i < table.size(); ++i) {
		for (int j = i + 1; j < table.size(); ++j) {
			if (abs(table[j].second - x) < abs(table[i].second - x)) {
				std::pair<double, double> tmp = table[j];
				table[j] = table[i];
				table[i] = tmp;
			}
		}
	}
}



double Newton_poly_correct(unsigned int n, double x, const std::vector <std::pair<double, double>> table) {
	double res = table[0].first, mult = 1;
	std::vector <std::vector<double>> A(n + 1, std::vector<double>(n + 1));
	for (int i = 0; i < n; ++i) {
		A[i][0] = table[i].first;
	}
	for (int j = 1; j < n; ++j) {
		for (int i = 0; i < n - j; ++i) {
			A[i][j] = (A[i + 1][j - 1] - A[i][j - 1]) / (table[j + i].second - table[i].second);
		}
	}
	std::string smult;
	for (int i = 0; i < n; ++i) {
		mult *= (x - table[i].second);
		res += A[0][i + 1] * mult;
	}
	return res;
}