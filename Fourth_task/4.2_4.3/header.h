#pragma once
#include <iostream>


double Leibniz(double (*I)(double x), double a, double b);

double left_rectangle(double (*f)(double x), double a, double b, size_t m);

double right_rectangle(double (*f)(double x), double a, double b, size_t m);

double middle_rectangle(double (*f)(double x), double a, double b, size_t m);

double trapeze(double (*f)(double x), double a, double b, size_t m);

double Simpson(double (*f)(double x), double a, double b, size_t m);


double theor_err_value(double c, double M, double d, double a, double b, size_t m);


double max(double x, double y);

double approx_func_max(double (*f)(double x), double a, double b, size_t m);

void print_all(int switcher, double a, double b, size_t m, size_t l);



double Runge_correction(double I_h, double I_hl, size_t d, size_t l);