#pragma once
#include "Header.h"



void sort(std::vector<std::pair<double, double>>& table, double x);


double Newton_poly_correct(unsigned int n, double x, std::vector <std::pair<double, double>> table);