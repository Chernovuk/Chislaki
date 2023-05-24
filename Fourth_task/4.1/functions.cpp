#include "functions.h"


double f(double x) {	//интегрируемая функция
	return log(x) * pow(x, 3);
}

double integr_of_f(double x) {	//Ее интеграл
	return pow(x, 4) * (4 * log(x) - 1) / 16;
}


double f_0(double x)             //интегрируемая функция, многочлен 0 степени
{
	return(7);
}

double integr_0(double x)            //интеграл многочлена 0 степени
{
	return(7 * x);
}

double f_1(double x)             //интегрируемая функция, многочлен 1 степени
{
	return(4 * x - 3);
}

double integr_1(double x)              //интеграл многочлена 1 степени
{
	return 2 * pow(x, 2) - 3 * x;
}

double f_2(double x)             //интегрируемая функция, многочлен 2 степени
{
	return(-pow(x, 2) - 8 * x + 1);
}

double integr_2(double x)            //интеграл многочлена 2 степени
{
	return -pow(x, 3) / 3 - 4 * pow(x, 2) + x;
}

double f_3(double x)             //интегрируемая функция, многочлен 3 степени
{
	return 2 * pow(x, 3) - 5 * x - 2;
}

double integr_3(double x)
{
	return pow(x, 4) / 2 - 2.5 * pow(x, 2) - 2 * x;   //интеграл многочлена 3 степени
}