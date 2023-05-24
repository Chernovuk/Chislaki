#include "functions.h"


double f(double x) {	//интегрируемая функция
	return log(x) * pow(x, 3);
}

double df(double x) {       //1-4 производные интегрируемой функции
	return pow(x, 2) * (3 * log(x) + 1);
}
double d2f(double x) {
	return x * (6 * log(x) + 5);
}
double d3f(double x) {
	return 6 * log(x) + 11;
}
double d4f(double x) {
	return 6 / x;
}


double integr_of_f(double x) {	//Ее интеграл
	return pow(x, 4) * (4 * log(x) - 1) / 16;
}


double f_0(double x)             //интегрируемая функция, многочлен 0 степени
{
	return(7);
}

double df_0(double x) {        //1-4 производные многочлена 0 степени
	return 0;
}
double d2f_0(double x) {
	return 0;
}
double d3f_0(double x) {
	return 0;
}
double d4f_0(double x) {
	return 0;
}

double integr_0(double x)            //интеграл многочлена 0 степени
{
	return(7 * x);
}


double f_1(double x)             //интегрируемая функция, многочлен 1 степени
{
	return(4 * x - 3);
}

double df_1(double x) {          //1-4 производные многочлена 1 степени
	return 4;
}
double d2f_1(double x) {
	return 0;
}
double d3f_1(double x) {
	return 0;
}
double d4f_1(double x) {
	return 0;
}

double integr_1(double x)              //интеграл многочлена 1 степени
{
	return 2 * pow(x, 2) - 3 * x;
}


double f_2(double x)             //интегрируемая функция, многочлен 2 степени
{
	return(-pow(x, 2) - 8 * x + 1);
}

double df_2(double x) {         //1-4 производные многочлена 2 степени
	return -2 * x - 8;
}
double d2f_2(double x) {
	return -2;
}
double d3f_2(double x) {
	return 0;
}
double d4f_2(double x) {
	return 0;
}

double integr_2(double x)            //интеграл многочлена 2 степени
{
	return -pow(x, 3) / 3 - 4 * pow(x, 2) + x;
}


double f_3(double x)             //интегрируемая функция, многочлен 3 степени
{
	return 2 * pow(x, 3) - 5 * x - 2;
}

double df_3(double x) {         //1-4 производные многочлена 3 степени
	return 6 * pow(x, 2) - 5;
}
double d2f_3(double x) {
	return 12 * x;
}
double d3f_3(double x) {
	return 12;
}
double d4f_3(double x) {
	return 0;
}

double integr_3(double x)
{
	return pow(x, 4) / 2 - 2.5 * pow(x, 2) - 2 * x;   //интеграл многочлена 3 степени
}