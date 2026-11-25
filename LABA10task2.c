#define _CRT_SECURE_NO_WARNINGS
#define PI 3.141592653589793
#include <stdio.h>
#include <locale.h>
#include <math.h>

double acos_n(double x, int N);
double acos_eps(double x, double eps);

int main() {
	setlocale(LC_ALL, "Russian");

	double x, eps;
	int N;

	printf("Введите значение х=|x| < 1:");
	scanf("%lf", &x);

	if (fabs(x) >= 1.0) {
		printf("Ошибка: должно выполняться условие |x| < 1.\n");
		return 1;

	}

	printf("Введите число слагаемых ряда N: ");
	scanf("%d", &N);
	
	printf("Введите точность вычислений eps: ");
	scanf("%lf", &eps);

	double res_std = acos(x);
	double res_n = acos_n(x, N);
	double res_eps = acos_eps(x, eps);

	printf("\nСравнение результатов для х = %.6lf:\n", x);
	printf("1) Сандартная функция acos(x) = %.10lf\n", res_std);
	printf("2) По ряду (N = %d)     = %.10lf(разница: %e)\n", N, res_n, fabs(res_std - res_n));
	printf("3) По ряду (eps = %g)  = %.10lf(разница: %e)\n,", eps, res_eps, fabs(res_std - res_eps));


	return 0;

}

double acos_n(double x, int N) {
	double sum = x;
	double p = x;

	for (int n = 1; n <= N;n++) {
		p = p * x * x * (2 * n - 1) / (2 * n);
		sum += p / (2 * n + 1);
	}
	return PI / 2.0 - sum;
}

double acos_eps(double x, double eps) {
	double sum = x;
	double p = x;
	double term = x;
	int n = 1;

	while (fabs(term) >= eps) {
		p = p * x * x * (2 * n - 1) / (2 * n);
		term = p / (2 * n + 1);
		sum += term;
		n++;
	}

	return PI / 2.0 - sum;

}