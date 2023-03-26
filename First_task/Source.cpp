#include "Header.h"


double f(double x) {	//����������� �������
	return pow(2, -x) + 0.5 * x * x - 10;
	//return sin(x) + x*x*x - 9 * x + 3;
}


double df(double x) {	//����������� f
	return -log(2) * pow(2, -x) + x;
	//return cos(x) + 3 * x * x - 9;
}


double d2f(double x) {	//������ ����������� f
	return log(2) * log(2) * pow(2, -x) + 1;
	//return -sin(x) + 6 * x;
}



void intervals_detector(double left, double right, double step, std::vector <std::pair<double, double>>& interval) {
	double lBoard = left, rBoard = lBoard + step;

	while (rBoard <= right) {
		if (f(lBoard) * f(rBoard) < 0) {
			std::cout << "�� ���������� [" << lBoard << "; " << rBoard << "] ���� ��� ������� ���� ������.\n";
			interval.push_back(std::make_pair(lBoard, rBoard));
		}
		lBoard = rBoard, rBoard += step;
	}
}



double bisection(double left, double right, double epsilon) {
	std::cout << "\n|����� ��������|\n";
	double middle;
	int count = 0;	//���-�� ��������
	std::cout << "��������� ����������� � �����: " << (right + left) / 2.0 << "\n";
	while (right - left > 2 * epsilon) {
		middle = (right + left) / 2.0;
		if (f(left) * f(middle) <= 0) {
			right = middle;
		}
		else {
			left = middle;
		}

		++count;
	}
	double x_approx = (right + left) / 2.0;
	std::cout << "�� " << count << " ����(��) ��� ������ ������������ ������: " << x_approx <<
		"\n|Xm - Xm-1| = " << right - left <<
		"\n���������� �������� �������: " << abs(f(x_approx)) << "\n";
	return x_approx;
}



double Newton(double x0, double epsilon) {
	std::cout << "\n|����� �������|\n";
	double x_approx = x0, x_last = x0 + epsilon * 2;
	int count = 0;	//���-�� ��������
	std::cout << "��������� ����������� � �����: " << x0 << "\n";
	while (abs(x_approx - x_last) > epsilon) {
		x_last = x_approx;
		x_approx = x_last - f(x_last) / df(x_last);

		++count;
	}

	std::cout << "�� " << count << " ����(��) ��� ������ ������������ ������: " << x_approx <<
		"\n|Xm - Xm-1| = " << abs(x_approx - x_last) <<
		"\n���������� �������� �������: " << abs(f(x_approx)) << "\n";
	return x_approx;
}



double Newton_modified(double x0, double epsilon) {//����������� x_last ������
	std::cout << "\n|���������������� ����� �������|\n";
	double x_approx = x0, x_last = x0 + epsilon * 2, df_x0 = df(x0);
	int count = 0;	//���-�� ��������
	std::cout << "��������� ����������� � �����: " << x0 << "\n";
	while (abs(x_approx - x_last) > epsilon) {
		x_last = x_approx;
		x_approx = x_last - f(x_last) / df_x0;

		++count;
	}

	std::cout << "�� " << count << " ����(��) ��� ������ ������������ ������: " << x_approx <<
		"\n|Xm - Xm-1| = " << abs(x_approx - x_last) <<
		"\n���������� �������� �������: " << abs(f(x_approx)) << "\n";
	return x_approx;
}



double secants(double x0, double x1, double epsilon) {
	std::cout << "\n|����� �������|\n";
	double x_approx = x1, x_before_last = x0, x_last = x1 + epsilon * 2;
	int count = 0;	//���-�� ��������
	std::cout << "��������� ����������� � �����: " << x1 << "\n";
	while (abs(x_approx - x_last) > epsilon) {
		x_before_last = x_last;
		x_last = x_approx;
		x_approx = x_last - f(x_last) * (x_last - x_before_last) / (f(x_last) - f(x_before_last));

		++count;
	}

	std::cout << "�� " << count << " ����(��) ��� ������ ������������ ������: " << x_approx <<
		"\n|Xm - Xm-1| = " << abs(x_approx - x_last) <<
		"\n���������� �������� �������: " << abs(f(x_approx)) << "\n";
	return x_approx;
}



double selection_of_x0(double left, double right) {	//������� ������ �0 ��� ������� �������
	double x0 = left + (right - left) * (double(rand()) /RAND_MAX);
	//std::cout << x0 << "\n";
	
	while (abs(df(x0)) > 1e-8 && f(x0) * d2f(x0) > 0) {
		x0 = left + (right - left) * (double(rand()) / RAND_MAX);
	}
	return x0;
}




std::vector <std::pair<double, double>> repeat_splitting(std::vector <std::pair<double, double>>& interval) {	//������� ��������������� ������� ��������, ���� ��� �� �����. ������������
	std::cout << "���������� " << interval.size() << " ����������(��) � �������, ������� ����������� �� ���������?\n" <<
		"���� ��, ������� 1, ����� 0: ";
	short int switcher;
	std::cin >> switcher;
	switch (switcher) {
	case 1:
	{
		std::cout << "�������, �� ������� ������ ������ ������� ���������� ����������: ";
		int n;
		std::cin >> n;
		std::vector <std::pair<double, double>> new_interval;
		for (int i = 0; i < interval.size(); ++i) {
			std::vector <std::pair<double, double>> i_interval;
			intervals_detector(interval[i].first, interval[i].second, (interval[i].second - interval[i].first) / n, i_interval);
			new_interval.insert(new_interval.end(), i_interval.begin(), i_interval.end());
		}

		interval = repeat_splitting(new_interval);
	}
	break;
	default:
		break;
	}
	return interval;
}