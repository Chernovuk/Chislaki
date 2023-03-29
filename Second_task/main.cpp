#include <windows.h>
#include <vector>
#include <iomanip>
#include <iostream>
#include <string>

double f(double x) {	//Интерполируемая функция
	return log(1 + x) - exp(x);	//вариант 13
}



void sort(std::vector<std::pair<double, double>> &table, double x) {	//Сортировка таблица значений относительно расстояния до точки интерполяции
	for (int i = 0; i < table.size(); ++i) {
		for (int j = i + 1; j < table.size(); ++j) {
			if (abs(table[j].first - x) < abs(table[i].first - x)) {
				std::pair<double, double> tmp = table[j];
				table[j] = table[i];
				table[i] = tmp;
			}
		}
	}
}



double Lagrange_poly(unsigned int n, double x, std::vector <std::pair<double, double>> table) {
	double res = 0;
	std::cout << "Lagrange polynomial:\n";
	for (int k = 0; k <= n; ++k) {
		double mult = 1;
		for (int i = 0; i <= n; ++i) {
			if (i != k) { 
				mult *= table[k].first - table[i].first;
			}
		}
		std::cout << table[k].second / mult;
		double w = 1;
		for (int j = 0; j <= n; ++j) {
			if (j != k) {
				w *= x - table[j].first;
				std::cout << "(x-" << table[j].first << ")";
			}
		}
		std::cout << "+";
		res += w * table[k].second / mult;
	}

	std::cout << "\n\n";
	return res;
}


//double Newton_poly(unsigned int n, double x, std::vector <std::pair<double, double>> table) {	// походу дерьмо
//	double res = table[0].second, mult = 1;
//	Polynomial w_p = Polynomial("1x^0");
//	Polynomial newton = Polynomial(std::to_string(table[0].second) + "x^0");
//	for (int i = 0; i < n; ++i) {
//		mult *= (x - table[i].first);
//		w_p *= Polynomial("1x^1-" + std::to_string(table[i].first) + "x^0");
//		Polynomial dw = diff(w_p.getPoly());
//		std::cout << "********\n";
//		w_p.print();
//		dw.print();
//		double A = 1;	//видимо, эта неправильно считается
//		for (int j = 0; j < i + 1; ++j) {
//			A *= table[j].second / value_at_point(dw , table[j].first);
//		}
//		newton += w_p * A;
//		res += A * mult;
//	}
//	std::cout << "Newton polynomial:\n";
//	newton.print();
//	std::cout << "\n";
//	return res;
//}

double Newton_poly_correct(unsigned int n, double x, std::vector <std::pair<double, double>> table) {
	double res = table[0].second, mult = 1;
	std::vector <std::vector<double>> A(n+1, std::vector<double>(n+1));
	std::cout << "Newton polynomial:\n";
	std::cout << res << "+";
	for (int i = 0; i < n; ++i) {
		A[i][0] = table[i].second;
	}
	for (int j = 1; j < n; ++j) {
		for (int i = 0; i < n - j; ++i) {
			A[i][j] = (A[i + 1][j - 1] - A[i][j - 1]) / (table[j+i].first - table[i].first);
		}
	}
	std::string smult;
	for (int i = 0; i < n; ++i) {
		mult *= (x - table[i].first);
		smult += "(x-" + std::to_string(table[i].first) + ")";
		std::cout << A[0][i + 1] << smult << "+";
		res += A[0][i+1] * mult;
	}

	std::cout << "\n\n";
	return res;
}

//Ha! Check for a dumbass has been passed perfectly. Now let's get real value:
int main() {

	SetConsoleTitleA("Algebraic interpolation problem");

	std::cout << std::fixed << std::setprecision(16);

	unsigned int m;	//Кол-во точек в таблице (m = 21)
	std::cout << "Input number of table values: ";
	std::cin >> m;


	double a, b;	//Концы отрезка интерполирования (a = 1, b = 2)
	std::cout << "Input segment boundaries: ";
	std::cin >> a >> b;

	std::cout << "Table of values: \n" << std::setw(15) << "X_i" << std::setw(17) << "f(X_i)\n";
	std::vector <std::pair<double, double>> table_values(m);	//Если задавать рандомно, надо будет компаратор написать, чтобы по иксам сортить
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
		while (x <= -1) {
			std::cout << "Have you ever seen the initial function? You are inputting values out of its range, stupid. Fine, I'm giving you one another try: ";
			std::cin >> x;
		}

		unsigned int n;	//Степень интерполяционного М.Ч. (n = 14)
		std::cout << "Input degree of interpolation polinom (Warning, degree must be less than number of table values, i.e. n < m): ";
		std::cin >> n;
		while (n >= m) {
			std::cout << "Incorrect input, consider condition n < m, try again: ";
			std::cin >> n;
		}

		if (n < m - 1) {
			sort(table_values, x);
			std::cout << "Sorted table of values: \n" << std::setw(15) << "X_i" << std::setw(17) << "f(X_i)\n";
			for (int i = 0; i < m; ++i) {
				std::cout << table_values[i].first << "|" << table_values[i].second << "\n";
			}
		}

		double Lagr_res = Lagrange_poly(n, x, table_values), Newt_res = Newton_poly_correct(n, x, table_values), f_res = f(x);
		std::cout << "Value of the Lagrange polynomial at the interpol. point: " << Lagr_res << "\n" <<
			"Value of absolute error rate: " << abs(Lagr_res - f_res) << "\n";
		std::cout << "Value of the Newton polynomial at the interpol. point: " << Newt_res << "\n" <<
			"Value of absolute error rate: " << abs(Newt_res - f_res) << "\n";
		std::cout << "If you want to try another interpolation point, enter 1, otherwise 0: ";
		std::cin >> flag;
	} while (flag);

	
	return 0;
}