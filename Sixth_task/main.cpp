#include <iostream>
#include <iomanip>
#include <vector>



double f(double y) {
	return 2 * y * y - y + 1;
}

double solution(double x) {		//Посчитано "руками"
	return (sqrt(7) * tan(sqrt(7) * x / 2) + 1) / 4;
}


double Taylor(double x) {	//Посчитано "руками"
	return 0.25 + 0.875 * x + pow(x, 3) * 49.0 / 96.0 + pow(x, 5) * 343.0 / 960.0 + pow(x, 7) * 40817.0 / 161280.0;
}


void Adams(const std::vector <std::pair<double, double>> &Taylor, std::vector <std::pair<double, double>> &Adams, int N) {
	for (int i = 0; i < 5; ++i)
	{
		Adams[i] = Taylor[i];
	}

	for (int i = 5; i < N; ++i) {
		Adams[i].first = Taylor[i].first;
	}

	for (int k = 5; k < N; ++k)
	{
		std::vector<double> l(5, 1.0);

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (i != j) {
					l[i] *= (Adams[k].first - Adams[j].first) / (Adams[i].first - Adams[j].first);
				}
			}
		}

		for (int i = 0; i < 5; ++i)
		{
			Adams[k].second += Adams[i].second * l[i];
		}
	}
}


void RungeKutt(std::vector <std::pair<double, double>>& RungeKutt, double h) {
	double y = 0.25;
	int N = RungeKutt.size();


	for (int i = 0; i < N; ++i) {
		RungeKutt[i].first = i * h;
	}
	RungeKutt[0].second = y;
	for (int i = 1; i < N; ++i)
	{
		double y_prev = RungeKutt[i - 1].second;
		double k1 = h * f(y_prev);
		double k2 = h * f(y_prev + k1 / 2);
		double k3 = h * f(y_prev + k2 / 2);
		double k4 = h * f(y_prev + k3);
		RungeKutt[i].second = y_prev + 1.0 / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);
	}
}


void Euler(std::vector<std::pair<double, double>> &Euler, double h) {

	const int N = Euler.size();
	for (int i = 0; i < N; ++i) {
		Euler[i].first = i * h;
	}
	Euler[0].second = 0.25;

	for (int i = 1; i < N; ++i)
	{
		double y_prev = Euler[i - 1].second;

		Euler[i].second = y_prev + h * f(y_prev);
	}

}

void EulerI(std::vector<std::pair<double, double>> &EulerI, double h)
{
	const int N = EulerI.size();
	for (int i = 0; i < N; ++i) {
		EulerI[i].first = i * h;
	}
	EulerI[0].second = 0.25;

	for (int i = 1; i < N; ++i) {
		double y_prev = EulerI[i - 1].second;
		double y_half = y_prev + h / 2 * f(y_prev);

		EulerI[i].second = y_prev + h * f(y_half);
	}

}

void EulerII(std::vector<std::pair<double, double>> &EulerII, double h)
{
	const int N = EulerII.size();
	for (int i = 0; i < N; ++i) {
		EulerII[i].first = i * h;
	}
	EulerII[0].second = 0.25;

	for (int i = 1; i < N; ++i)
	{
		double y_prev = EulerII[i - 1].second;
		double Y = y_prev + h * f(y_prev);

		EulerII[i].second = y_prev + h / 2 * (f(y_prev) + f(Y));
	}

}

int main() {

	std::cout << std::fixed << std::setprecision(16);

	std::cout << "Input length of step: ";
	double h = 0.1;	//h = 0.1
	//std::cin >> h;

	std::cout << "Input N - number of steps + 2: ";
	int N = 10;	//N = 10
	//std::cin >> N;

	std::cout << "Table of values: \n" << std::setw(15) << "X_i" << std::setw(20) << "Solution(X_i)\n";
	std::vector <std::pair<double, double>> exact_sol(N + 2);
	for (int i = -2; i < N; ++i) {
		exact_sol[i+2].first = i * h;
		exact_sol[i+2].second = solution(exact_sol[i+2].first);
		std::cout << std::setw(19) << exact_sol[i + 2].first << "|" << exact_sol[i + 2].second << "\n";
	}



	std::vector <std::pair<double, double>> Taylor_sol(N + 2);
	std::cout << "\nTable of Taylor values: \n" << std::setw(15) << "X_i" << std::setw(20) << "Taylor(X_i)" << std::setw(34) << "|Taylor(X_i) - Solution(X_i)|\n";
	for (int i = -2; i < N; ++i) {
		Taylor_sol[i + 2].first = i * h;
		Taylor_sol[i + 2].second = Taylor(Taylor_sol[i+2].first);
		std::cout << std::setw(19) << Taylor_sol[i + 2].first << "|" << std::setw(19) << Taylor_sol[i + 2].second << "|" << abs(Taylor_sol[i + 2].second - exact_sol[i + 2].second) << "\n";
	}


	std::vector <std::pair<double, double>> Adams_sol(N + 2);
	std::cout << "\nTable of Adams values: \n" << std::setw(15) << "X_i" << std::setw(20) << "Adams(X_i)" << std::setw(34) << "|Adams(X_i) - Solution(X_i)|\n";
	Adams(Taylor_sol, Adams_sol, N + 2);
	for (int i = -2; i < N; ++i) {
		std::cout << std::setw(19) << Adams_sol[i + 2].first << "|" << std::setw(19) << Adams_sol[i + 2].second << "|" << abs(Adams_sol[i + 2].second - exact_sol[i + 2].second) << "\n";
	}


	std::vector <std::pair<double, double>> RungeKutt_sol(N);
	std::cout << "\nTable of RungeKutt values: \n" << std::setw(15) << "X_i" << std::setw(20) << "RungeKutt(X_i)" << std::setw(34) << "|RungeKutt(X_i) - Solution(X_i)|\n";
	RungeKutt(RungeKutt_sol,h);
	for (int i = 0; i < N; ++i) {
		std::cout << std::setw(19) << RungeKutt_sol[i].first << "|" << std::setw(19) << RungeKutt_sol[i].second << "|" << abs(RungeKutt_sol[i].second - exact_sol[i+2].second) << "\n";
	}


	std::vector <std::pair<double, double>> Euler_sol(N);
	std::cout << "\nTable of Euler values: \n" << std::setw(15) << "X_i" << std::setw(20) << "Euler(X_i)" << std::setw(34) << "|Euler(X_i) - Solution(X_i)|\n";
	Euler(Euler_sol, h);
	for (int i = 0; i < N; ++i) {
		std::cout << std::setw(19) << Euler_sol[i].first << "|" << std::setw(19) << Euler_sol[i].second << "|" << abs(Euler_sol[i].second - exact_sol[i + 2].second) << "\n";
	}


	std::vector <std::pair<double, double>> EulerI_sol(N);
	std::cout << "\nTable of EulerI values: \n" << std::setw(15) << "X_i" << std::setw(20) << "EulerI(X_i)" << std::setw(34) << "|EulerI(X_i) - Solution(X_i)|\n";
	EulerI(EulerI_sol, h);
	for (int i = 0; i < N; ++i) {
		std::cout << std::setw(19) << EulerI_sol[i].first << "|" << std::setw(19) << EulerI_sol[i].second << "|" << abs(EulerI_sol[i].second - exact_sol[i + 2].second) << "\n";
	}


	std::vector <std::pair<double, double>> EulerII_sol(N);
	std::cout << "\nTable of EulerII values: \n" << std::setw(15) << "X_i" << std::setw(20) << "EulerII(X_i)" << std::setw(34) << "|EulerII(X_i) - Solution(X_i)|\n";
	EulerII(EulerII_sol, h);
	for (int i = 0; i < N; ++i) {
		std::cout << std::setw(19) << EulerII_sol[i].first << "|" << std::setw(19) << EulerII_sol[i].second << "|" << abs(EulerII_sol[i].second - exact_sol[i + 2].second) << "\n";
	}

	return 0;
}