#pragma once
#include <iostream>

double f(double x);	//интегрируемая функция

double df(double x);       //1-4 производные интегрируемой функции
double d2f(double x);
double d3f(double x);
double d4f(double x);

double integr_of_f(double x);	//Ее интеграл


double f_0(double x);             //интегрируемая функция, многочлен 0 степени

double df_0(double x);        //1-4 производные многочлена 0 степени
double d2f_0(double x);
double d3f_0(double x);
double d4f_0(double x);

double integr_0(double x);            //интеграл многочлена 0 степени

double f_1(double x);             //интегрируемая функция, многочлен 1 степени

double df_1(double x);          //1-4 производные многочлена 1 степени
double d2f_1(double x);
double d3f_1(double x);
double d4f_1(double x);

double integr_1(double x);              //интеграл многочлена 1 степени

double f_2(double x);             //интегрируемая функция, многочлен 2 степени

double df_2(double x);         //1-4 производные многочлена 2 степени
double d2f_2(double x);
double d3f_2(double x);
double d4f_2(double x);

double integr_2(double x);            //интеграл многочлена 2 степени

double f_3(double x);             //интегрируемая функция, многочлен 3 степени

double df_3(double x);         //1-4 производные многочлена 3 степени
double d2f_3(double x);
double d3f_3(double x);
double d4f_3(double x);

double integr_3(double x);