#include <windows.h>
#include <ctime>
#include <iomanip>

#include "Header.h"



int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	std::cout << std::fixed << std::setprecision(16);
	SetConsoleTitleA("Computational methods of solving nonlinear equations");
	float A, B;	//������� ������� (-5; 4)
	int n;	//���������� ��������� �������

	std::cout << "������� ������� �������: ";
	std::cin >> A >> B;
	std::cout << "������� ���������� ���������: ";
	std::cin >> n;

	double step = (B - A) / n * 1.0;	//��� �� �������
	std::vector <std::pair<double, double>> interval;

	intervals_detector(A, B, step, interval);
	if (interval.empty()) {
		std::cout << "� ����� " << step << " �� ������� �� ���� ������� �� ������ �����, ���������� ��� ��������: ";
		std::cin >> step;
	}
	else {
		interval = repeat_splitting(interval);
	}



	std::cout << "\n��������� ������\n" << "������� ���������� �����������: ";
	double err_rate;	//1e-9;
	std::cin >> err_rate;
	
	for (int i = 0; i < interval.size(); ++i) {
		std::cout << "\n���������� ����� �� ������� [" << interval[i].first << "; " << interval[i].second << "]\n";
		bisection(interval[i].first, interval[i].second, err_rate);
		Newton(selection_of_x0(interval[i].first, interval[i].second), err_rate);
		Newton_modified(selection_of_x0(interval[i].first, interval[i].second), err_rate);
		secants(interval[i].first, interval[i].second, err_rate);
	}

	return 0;
}