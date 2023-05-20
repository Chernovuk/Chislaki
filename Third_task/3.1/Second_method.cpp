#include "Second_method.h"



double Newton_poly_corr(unsigned int n, double x, std::vector <std::pair<double, double>> table) {
	double res = table[0].second, mult = 1;
	std::vector <std::vector<double>> A(n + 1, std::vector<double>(n + 1));
	/*std::cout << "Newton polynomial:\n";
	std::cout << res << "+";*/
	for (int i = 0; i < n; ++i) {
		A[i][0] = table[i].second;
	}
	for (int j = 1; j < n; ++j) {
		for (int i = 0; i < n - j; ++i) {
			A[i][j] = (A[i + 1][j - 1] - A[i][j - 1]) / (table[j + i].first - table[i].first);
		}
	}
	//std::string smult;
	for (int i = 0; i < n; ++i) {
		mult *= (x - table[i].first);
		//smult += "(x-" + std::to_string(table[i].first) + ")";
		//std::cout << A[0][i + 1] << smult << "+";
		res += A[0][i + 1] * mult;
	}

	//std::cout << "\n\n";
	return res;
}



double secants(double x0, double x1, double epsilon, unsigned int n, const std::vector <std::pair<double, double>> &table_values, double F) {
	double x_approx = x1, x_before_last = x0, x_last = x1 + epsilon * 2;
	while (abs(x_approx - x_last) > epsilon) {
		x_before_last = x_last;
		x_last = x_approx;
		x_approx = x_last - (Newton_poly_corr(n, x_last, table_values) - F)* (x_last - x_before_last) / (Newton_poly_corr(n, x_last, table_values) - Newton_poly_corr(n, x_before_last, table_values));
	}

	//std::cout << "Absolute value of discrepancy : " << abs(Newton_poly_corr(n, x_approx, table_values) - F) << "\n";
	return x_approx;
}
