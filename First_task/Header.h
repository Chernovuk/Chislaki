#pragma once
#include <vector>
#include <cmath>
#include <iostream>


double f(double x);

double df(double x);

double d2f(double x);


void intervals_detector(double left, double right, double step, std::vector <std::pair<double, double>>& interval);

std::vector <std::pair<double, double>> repeat_splitting(std::vector <std::pair<double, double>>& interval);


double selection_of_x0(double left, double right);



double bisection(double left, double right, double epsilon);

double Newton(double x0, double epsilon);

double Newton_modified(double x0, double epsilon);

double secants(double x0, double x1, double epsilon);