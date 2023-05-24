#include "header.h"
#include "functions.h"

double Newton_Leibniz(double (*integr)(double x), double a, double b)
{
	return integr(b) - integr(a);
}


double left_rectangle(double (*f)(double x), double a, double b, size_t m)
{
	double sum = 0, h = (b - a) / m;

	for (size_t j = 0; j < m; ++j)
	{
		sum += f(a + j * h);
	}

	sum *= h;

	return(sum);
}

double right_rectangle(double (*f)(double x), double a, double b, size_t m)
{
	double sum = 0, h = (b - a) / m;

	for (size_t j = 0; j < m; ++j)
	{
		sum += f(a + (j + 1) * h);
	}

	sum *= h;

	return(sum);
}

double middle_rectangle(double (*f)(double x), double a, double b, size_t m)
{
	double sum = 0, h = (b - a) / m;

	for (size_t j = 0; j < m; ++j)
	{
		sum += f(a + (j + 0.5) * h);
	}

	sum *= h;

	return(sum);
}

double trapeze(double (*f)(double x), double a, double b, size_t m)
{
	double sum = 0, h = (b - a) / m;

	for (size_t j = 1; j < m; ++j)
	{
		sum += f(a + j * h);
	}

	sum *= 2;
	sum += f(a) + f(b);
	sum *= h / 2;

	return(sum);
}

double Simpson(double (*f)(double x), double a, double b, size_t m)	//ACT = 3
{
	double sum = 0, sum_1 = 0, sum_2 = 0, h = (b - a) / m;

	sum += f(a) + f(b);

	for (size_t j = 1; j < m; ++j)
	{
		sum_1 += f(a + j * h);
	}

	sum_1 *= 2;

	for (size_t j = 0; j < m; ++j)
	{
		sum_2 += f(a + (j + 0.5) * h);
	}

	sum_2 *= 4;

	sum += sum_1 + sum_2;

	sum *= h / 6;

	return(sum);
}


double theor_err_value(double c, double M, double d, double a, double b, size_t m)
{
	double h = (b - a) / m;

	return(c * M * (b - a) * pow(h, d + 1));
}


double max(double x, double y) {
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}

double approx_func_max(double (*f)(double x), double a, double b, size_t m) {
	double h = (b - a) / m;
	double maxi = abs(f(a));
	for (size_t i = 1; i <= m; ++i) {
		maxi = max(maxi, abs(f(a + i * h)));
	}
	return maxi;
}

void print_all(int switcher, double a, double b, size_t m, size_t l) {

	const double c1 = 0.5, c2 = 1.0 / 12.0, c3 = 1.0 / 24.0, c4 = 1.0 / 2880.0;

	double left_rectangl, right_rectangl, middle_rectangl, trapez, Simpso;

	double left_ml, right_ml, middle_ml, trap_ml, Simp_ml;

	switch (switcher) {
	case 1:
		left_rectangl = left_rectangle(f, a, b, m), right_rectangl = right_rectangle(f, a, b, m), middle_rectangl = middle_rectangle(f, a, b, m),
			trapez = trapeze(f, a, b, m), Simpso = Simpson(f, a, b, m);
		left_ml = left_rectangle(f, a, b, m * l), right_ml = right_rectangle(f, a, b, m * l), middle_ml = middle_rectangle(f, a, b, m * l),
			trap_ml = trapeze(f, a, b, m * l), Simp_ml = Simpson(f, a, b, m * l);

		std::cout << "Left rectangle: " << left_rectangl << "\nAbsolute error value: " << abs(left_rectangl - Newton_Leibniz(integr_of_f, a, b)) <<
			"\nTheoretical error value: " << theor_err_value(c1, approx_func_max(df, a, b, m), 0, a, b, m) <<
			"\nRunge correction: " << Runge_correction(left_rectangl, left_ml, 0, l) <<
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 0, l) - Newton_Leibniz(integr_of_f, a, b)) << "\n\n";

		std::cout << "Right rectangle: " << right_rectangl << "\nAbsolute error value: " << abs(right_rectangl - Newton_Leibniz(integr_of_f, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c1, approx_func_max(df, a, b, m), 0, a, b, m) <<
			"\nRunge correction: " << Runge_correction(right_rectangl, right_ml, 0, l) <<
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 0, l) - Newton_Leibniz(integr_of_f, a, b)) << "\n\n";

		std::cout << "Middle rectangle: " << middle_rectangl << "\nAbsolute error value: " << abs(middle_rectangl - Newton_Leibniz(integr_of_f, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c3, approx_func_max(df, a, b, m), 0, a, b, m) <<
			"\nRunge correction: " << Runge_correction(middle_rectangl, middle_ml, 0, l) <<
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 0, l) - Newton_Leibniz(integr_of_f, a, b)) << "\n\n";

		std::cout << "Trapeze: " << trapez << "\nAbsolute error value: " << abs(trapez - Newton_Leibniz(integr_of_f, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c2, approx_func_max(d2f, a, b, m), 1, a, b, m) <<
			"\nRunge correction: " << Runge_correction(trapez, trap_ml, 1, l) <<
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 1, l) - Newton_Leibniz(integr_of_f, a, b)) << "\n\n";

		std::cout << "Simpson: " << Simpso << "\nAbsolute error value: " << abs(Simpso - Newton_Leibniz(integr_of_f, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c4, approx_func_max(d4f, a, b, m), 3, a, b, m) <<
			"\nRunge correction: " << Runge_correction(Simpso, Simp_ml, 3, l) <<
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 3, l) - Newton_Leibniz(integr_of_f, a, b)) << "\n\n";
		break;
	case 2:
		left_rectangl = left_rectangle(f_0, a, b, m), right_rectangl = right_rectangle(f_0, a, b, m), middle_rectangl = middle_rectangle(f_0, a, b, m),
			trapez = trapeze(f_0, a, b, m), Simpso = Simpson(f_0, a, b, m);
		left_ml = left_rectangle(f_0, a, b, m * l), right_ml = right_rectangle(f_0, a, b, m * l), middle_ml = middle_rectangle(f_0, a, b, m * l),
			trap_ml = trapeze(f_0, a, b, m * l), Simp_ml = Simpson(f_0, a, b, m * l);

		std::cout << "Left rectangle: " << left_rectangl << "\nAbsolute error value: " << abs(left_rectangl - Newton_Leibniz(integr_0, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c1, approx_func_max(df_0, a, b, m), 0, a, b, m) <<
			"\nRunge correction: " << Runge_correction(left_rectangl, left_ml, 0, l) <<
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 0, l) - Newton_Leibniz(integr_0, a, b)) << "\n\n";

		std::cout << "Right rectangle: " << right_rectangl << "\nAbsolute error value: " << abs(right_rectangl - Newton_Leibniz(integr_0, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c1, approx_func_max(df_0, a, b, m), 0, a, b, m) <<
			"\nRunge correction: " << Runge_correction(right_rectangl, right_ml, 0, l) <<
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 0, l) - Newton_Leibniz(integr_0, a, b)) << "\n\n";

		std::cout << "Middle rectangle: " << middle_rectangl << "\nAbsolute error value: " << abs(middle_rectangl - Newton_Leibniz(integr_0, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c3, approx_func_max(df_0, a, b, m), 0, a, b, m) <<
			"\nRunge correction: " << Runge_correction(middle_rectangl, middle_ml, 0, l) <<
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 0, l) - Newton_Leibniz(integr_0, a, b)) << "\n\n";

		std::cout << "Trapeze: " << trapez << "\nAbsolute error value: " << abs(trapez - Newton_Leibniz(integr_0, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c2, approx_func_max(d2f_0, a, b, m), 1, a, b, m) <<
			"\nRunge correction: " << Runge_correction(trapez, trap_ml, 1, l) <<
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 1, l) - Newton_Leibniz(integr_0, a, b)) << "\n\n";

		std::cout << "Simpson: " << Simpso << "\nAbsolute error value: " << abs(Simpso - Newton_Leibniz(integr_0, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c4, approx_func_max(d4f_0, a, b, m), 3, a, b, m) <<
			"\nRunge correction: " << Runge_correction(Simpso, Simp_ml, 3, l) <<
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 3, l) - Newton_Leibniz(integr_0, a, b)) << "\n\n";
		break;
	case 3:
		left_rectangl = left_rectangle(f_1, a, b, m), right_rectangl = right_rectangle(f_1, a, b, m), middle_rectangl = middle_rectangle(f_1, a, b, m),
			trapez = trapeze(f_1, a, b, m), Simpso = Simpson(f_1, a, b, m);
		left_ml = left_rectangle(f_1, a, b, m * l), right_ml = right_rectangle(f_1, a, b, m * l), middle_ml = middle_rectangle(f_1, a, b, m * l),
			trap_ml = trapeze(f_1, a, b, m * l), Simp_ml = Simpson(f_1, a, b, m * l);

		std::cout << "Left rectangle: " << left_rectangl << "\nAbsolute error value: " << abs(left_rectangl - Newton_Leibniz(integr_1, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c1, approx_func_max(df_1, a, b, m), 0, a, b, m) <<
			"\nRunge correction: " << Runge_correction(left_rectangl, left_ml, 0, l) <<
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 0, l) - Newton_Leibniz(integr_1, a, b)) << "\n\n";

		std::cout << "Right rectangle: " << right_rectangl << "\nAbsolute error value: " << abs(right_rectangl - Newton_Leibniz(integr_1, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c1, approx_func_max(df_1, a, b, m), 0, a, b, m) <<
			"\nRunge correction: " << Runge_correction(right_rectangl, right_ml, 0, l) <<
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 0, l) - Newton_Leibniz(integr_1, a, b)) << "\n\n";

		std::cout << "Middle rectangle: " << middle_rectangl << "\nAbsolute error value: " << abs(middle_rectangl - Newton_Leibniz(integr_1, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c3, approx_func_max(df_1, a, b, m), 0, a, b, m) <<
			"\nRunge correction: " << Runge_correction(middle_rectangl, middle_ml, 0, l) <<
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 0, l) - Newton_Leibniz(integr_1, a, b)) << "\n\n";

		std::cout << "Trapeze: " << trapez << "\nAbsolute error value: " << abs(trapez - Newton_Leibniz(integr_1, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c2, approx_func_max(d2f_1, a, b, m), 1, a, b, m) <<
			"\nRunge correction: " << Runge_correction(trapez, trap_ml, 1, l) <<
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 1, l) - Newton_Leibniz(integr_1, a, b)) << "\n\n";

		std::cout << "Simpson: " << Simpso << "\nAbsolute error value: " << abs(Simpso - Newton_Leibniz(integr_1, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c4, approx_func_max(d4f_1, a, b, m), 3, a, b, m) <<
			"\nRunge correction: " << Runge_correction(Simpso, Simp_ml, 3, l) <<
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 3, l) - Newton_Leibniz(integr_1, a, b)) << "\n\n";
		break;
	case 4:
		left_rectangl = left_rectangle(f_2, a, b, m), right_rectangl = right_rectangle(f_2, a, b, m), middle_rectangl = middle_rectangle(f_2, a, b, m),
			trapez = trapeze(f_2, a, b, m), Simpso = Simpson(f_2, a, b, m);
		left_ml = left_rectangle(f_2, a, b, m * l), right_ml = right_rectangle(f_2, a, b, m * l), middle_ml = middle_rectangle(f_2, a, b, m * l),
			trap_ml = trapeze(f_2, a, b, m * l), Simp_ml = Simpson(f_2, a, b, m * l);

		std::cout << "Left rectangle: " << left_rectangl << "\nAbsolute error value: " << abs(left_rectangl - Newton_Leibniz(integr_2, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c1, approx_func_max(df_2, a, b, m), 0, a, b, m) <<
			"\nRunge correction: " << Runge_correction(left_rectangl, left_ml, 0, l) <<
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 0, l) - Newton_Leibniz(integr_2, a, b)) << "\n\n";

		std::cout << "Right rectangle: " << right_rectangl << "\nAbsolute error value: " << abs(right_rectangl - Newton_Leibniz(integr_2, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c1, approx_func_max(df_2, a, b, m), 0, a, b, m) <<
			"\nRunge correction: " << Runge_correction(right_rectangl, right_ml, 0, l) <<
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 0, l) - Newton_Leibniz(integr_2, a, b)) << "\n\n";

		std::cout << "Middle rectangle: " << middle_rectangl << "\nAbsolute error value: " << abs(middle_rectangl - Newton_Leibniz(integr_2, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c3, approx_func_max(df_2, a, b, m), 0, a, b, m) <<
			"\nRunge correction: " << Runge_correction(middle_rectangl, middle_ml, 0, l) <<
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 0, l) - Newton_Leibniz(integr_2, a, b)) << "\n\n";

		std::cout << "Trapeze: " << trapez << "\nAbsolute error value: " << abs(trapez - Newton_Leibniz(integr_2, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c2, approx_func_max(d2f_2, a, b, m), 1, a, b, m) <<
			"\nRunge correction: " << Runge_correction(trapez, trap_ml, 1, l) <<
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 1, l) - Newton_Leibniz(integr_2, a, b)) << "\n\n";

		std::cout << "Simpson: " << Simpso << "\nAbsolute error value: " << abs(Simpso - Newton_Leibniz(integr_2, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c4, approx_func_max(d4f_2, a, b, m), 3, a, b, m) <<
			"\nRunge correction: " << Runge_correction(Simpso, Simp_ml, 3, l) <<
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 3, l) - Newton_Leibniz(integr_2, a, b)) << "\n\n";
		break;
	case 5:
		left_rectangl = left_rectangle(f_3, a, b, m), right_rectangl = right_rectangle(f_3, a, b, m), middle_rectangl = middle_rectangle(f_3, a, b, m),
			trapez = trapeze(f_3, a, b, m), Simpso = Simpson(f_3, a, b, m);
		left_ml = left_rectangle(f_3, a, b, m * l), right_ml = right_rectangle(f_3, a, b, m * l), middle_ml = middle_rectangle(f_3, a, b, m * l),
			trap_ml = trapeze(f_3, a, b, m * l), Simp_ml = Simpson(f_3, a, b, m * l);

		std::cout << "Left rectangle: " << left_rectangl << "\nAbsolute error value: " << abs(left_rectangl - Newton_Leibniz(integr_3, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c1, approx_func_max(df_3, a, b, m), 0, a, b, m) <<
			"\nRunge correction: " << Runge_correction(left_rectangl, left_ml, 0, l) <<
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 0, l) - Newton_Leibniz(integr_3, a, b)) << "\n\n";

		std::cout << "Right rectangle: " << right_rectangl << "\nAbsolute error value: " << abs(right_rectangl - Newton_Leibniz(integr_3, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c1, approx_func_max(df_3, a, b, m), 0, a, b, m) <<
			"\nRunge correction: " << Runge_correction(right_rectangl, right_ml, 0, l) <<
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 0, l) - Newton_Leibniz(integr_3, a, b)) << "\n\n";

		std::cout << "Middle rectangle: " << middle_rectangl << "\nAbsolute error value: " << abs(middle_rectangl - Newton_Leibniz(integr_3, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c3, approx_func_max(df_3, a, b, m), 0, a, b, m) <<
			"\nRunge correction: " << Runge_correction(middle_rectangl, middle_ml, 0, l) << 
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 0, l) - Newton_Leibniz(integr_3, a, b)) << "\n\n";

		std::cout << "Trapeze: " << trapez << "\nAbsolute error value: " << abs(trapez - Newton_Leibniz(integr_3, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c2, approx_func_max(d2f_3, a, b, m), 1, a, b, m) << 
			"\nRunge correction: "<< Runge_correction(trapez, trap_ml, 1, l) << 
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 1, l) - Newton_Leibniz(integr_3, a, b)) << "\n\n";

		std::cout << "Simpson: " << Simpso << "\nAbsolute error value: " << abs(Simpso - Newton_Leibniz(integr_3, a, b)) << 
			"\nTheoretical error value: " << theor_err_value(c4, approx_func_max(d4f_3, a, b, m), 3, a, b, m) << 
			"\nRunge correction: " << Runge_correction(Simpso, Simp_ml, 3, l) << 
			"\nRunge correction error value: " << abs(Runge_correction(Simpso, Simp_ml, 3, l) - Newton_Leibniz(integr_3, a, b)) << "\n\n";
		break;
	}
}



double Runge_correction(double integr_step_m, double integr_step_ml, size_t d, size_t l)
{
	return((pow(l, d + 1) * integr_step_ml - integr_step_m) / (pow(l, d + 1) - 1));
}