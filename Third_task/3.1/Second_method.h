#pragma once
#include <string>

#include "Header.h"


double Newton_poly_corr(unsigned int n, double x, std::vector <std::pair<double, double>> table);


double secants(double x0, double x1, double epsilon, unsigned int n, const std::vector <std::pair<double, double>>& table_values, double F);