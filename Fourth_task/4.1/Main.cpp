#include <iomanip>
#include <iostream>

#include "functions.h"


double Newton_Leibniz(double (*integr)(double x), double a, double b)
{
	return(integr(b) - integr(a));
}


double left_rectangle(double (*f)(double x), double a, double b)
{
	return((b - a) * f(a));
}

double right_rectangle(double (*f)(double x), double a, double b)
{
	return((b - a) * f(b));
}

double middle_rectangle(double (*f)(double x), double a, double b)
{
	return((b - a) * f((a + b) / 2));
}

double trapeze(double (*f)(double x), double a, double b)
{
	return((b - a) / 2 * (f(a) + f(b)));
}


double Simpson(double (*f)(double x), double a, double b)
{
	return((b - a) / 6 * (f(a) + 4 * f((a + b) / 2) + f(b)));
}

double three_eighths(double (*f)(double x), double a, double b)
{
	double h = (b - a) / 3;
	return((b - a) * (0.125 * f(a) + 0.375 * f(a + h) + 0.375 * f(a + 2 * h) + 0.125 * f(b)));
}


void print_all(double (*f)(double x), double (*integr)(double x), double a, double b) {
	std::cout << "Left rectangle: " << left_rectangle(f, a, b) << "\nAbsolute error value: " << abs(left_rectangle(f, a, b) - Newton_Leibniz(integr, a, b)) << "\n\n";
	std::cout << "Right rectangle: " << right_rectangle(f, a, b) << "\nAbsolute error value: " << abs(right_rectangle(f, a, b) - Newton_Leibniz(integr, a, b)) << "\n\n";
	std::cout << "Middle rectangle: " << middle_rectangle(f, a, b) << "\nAbsolute error value: " << abs(middle_rectangle(f, a, b) - Newton_Leibniz(integr, a, b)) << "\n\n";
	std::cout << "Trapeze: " << trapeze(f, a, b) << "\nAbsolute error value: " << abs(trapeze(f, a, b) - Newton_Leibniz(integr, a, b)) << "\n\n";
	std::cout << "Simpson: " << Simpson(f, a, b) << "\nAbsolute error value: " << abs(Simpson(f, a, b) - Newton_Leibniz(integr, a, b)) << "\n\n";
	std::cout << "Three_eighths: " << three_eighths(f, a, b) << "\nAbsolute error value: " << abs(three_eighths(f, a, b) - Newton_Leibniz(integr, a, b)) << "\n\n";
}

int main() {

	std::cout << std::fixed << std::setprecision(16);

	int flag;
	do {
		std::cout << "Input integration confines: ";
		double a, b;    //Пределы интегрирования
		std::cin >> a >> b;

		int switching_fs;
		do {
			std::cout << "Choose function which you want to integrate:\n" <<
				"1. f = ln(x)*x^3\n" << "2. f = 7\n" << "3. f = 4*x - 3\n" << "4. f = -x^2 - 8*x + 1\n" << "5. f = 2*x^3 - 5*x - 2\n";
			int chosen;
			std::cin >> chosen;

			std::cout << "Result by all methods = \n";
			switch (chosen) {
			case 1:
				print_all(f, integr_of_f, a, b);
				break;
			case 2:
				print_all(f_0, integr_0, a, b);
				break;
			case 3:
				print_all(f_1, integr_1, a, b);
				break;
			case 4:
				print_all(f_2, integr_2, a, b);
				break;
			case 5:
				print_all(f_3, integr_3, a, b);
				break;
			}
			std::cout << "If you would like to choose another function, press 1, otherwise 0\n";
			std::cin >> switching_fs;
		} while (switching_fs);

		std::cout << "If you want change integration confines, press 1, otherwise 0\n";
		std::cin >> flag;
	} while (flag);



	return 0;
}