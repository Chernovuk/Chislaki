#include <iostream>
#include <Windows.h>
#include <vector>
#include <iomanip>

double f(double x) {
	return exp(6 * x);
}

double df(const std::vector<std::pair<double, double>> &table, int i, double h) {
	if (!i) {
		return (-3 * table[i].second + 4 * table[i + 1].second - table[i + 2].second) / (2 * h);
	}
	else if (i == table.size() - 1) {
		return (3 * table[i].second - 4 * table[i - 1].second + table[i - 2].second) / (2 * h);
	}
	else {
		return (table[i + 1].second - table[i - 1].second) / (2 * h);
	}
}

double actual_df(const std::vector<std::pair<double, double>>& table, int i) {
	return 6 * table[i].second;
}

double actual_d2f(const std::vector<std::pair<double, double>>& table, int i) {
	return 36 * table[i].second;
}

int main() {

	SetConsoleTitleA("Algebraic reverse interpolation problem");

	std::cout << std::fixed << std::setprecision(16);

	bool flag;
	
	do {
		unsigned int m;	//Кол-во точек в таблице (m = 10)
		std::cout << "Input number of table values: ";
		std::cin >> m;


		std::cout << "Input starting point: ";
		double a;
		std::cin >> a;


		std::cout << "Input length of step: ";
		double h;
		std::cin >> h;


		std::vector <std::pair<double, double>> table_values(m);
		std::cout << "Table of values: \n" << std::setw(15) << "X_i" << std::setw(17) << "f(X_i)\n";
		for (int i = 0; i < m; ++i) {
			table_values[i].first = a + i * h;
			table_values[i].second = f(table_values[i].first);
			std::cout << table_values[i].first << "|" << table_values[i].second << "\n";
		}
		std::cout << "\n";

		/*std::cout << "\n\n*************\n";*/

		
		std::vector <std::pair<double, double>> df_table(m);
		for (int i = 0; i < m; ++i) {
			df_table[i].first = table_values[i].first;
			df_table[i].second = df(table_values, i, h);
			/*std::cout << df_table[i].first << "|" << df_table[i].second << "\n";*/
		}
		/*std::cout << "\n\n";*/

		std::vector <double> d2f_table(m);
		for (int i = 0; i < m; ++i) {
			d2f_table[i] = df(df_table, i, h);
			/*std::cout << df_table[i].first << "|" << d2f_table[i] << "\n";*/
		}

		/*std::cout << "***********************\n\n";*/

		std::cout << std::setw(15) << "X_i" << std::setw(19) << "f(X_i)" << std::setw(24) << "df(X_i)" <<
			std::setw(42) << "|df(X_i) - act_df(X_i)|" << std::setw(16) << "d2f(X_i)" << std::setw(30) << "|d2f(X_i) - act_d2f(X_i)|" << "\n";
		for (int i = 0; i < m; ++i) {
			double actual_dif_f = actual_df(table_values, i), actual_dif2_f = actual_d2f(table_values, i);
			std::cout << table_values[i].first << "|" << std::setw(26) << table_values[i].second << "|" << std::setw(26) << df_table[i].second << "|" << std::setw(23) <<
				abs(df_table[i].second - actual_dif_f) << "|" << std::setw(20) << d2f_table[i] << "|" << std::setw(20) << abs(d2f_table[i] - actual_dif2_f) << "\n";
		}

		std::cout << "If you want to try another input data, enter 1, otherwise 0: ";
		std::cin >> flag;
	} while (flag);

	
	


	return 0;
}