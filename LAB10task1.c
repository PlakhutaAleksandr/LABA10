#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

double fa(double x);
double fb(double x);

int main() {
	setlocale(LC_ALL, "Russian");

	double x;
	int m;

	printf("Введите значение x: ");
	scanf("%lf", &x);

	printf("Выберите действие х: ");
	printf("1 - значение функции F1(x)\n");
	printf("2 - значние функции F2(x)\n");
	printf("3 - оба значения функций\n");
	printf("4 - произведение, разность квадротов и удвоенная сумма\n");
	printf("Ваш выбор: ");
	scanf("%d", &m);

	double a = fa(x);
	double b = fb(x);

	if (m == 1) {
		printf("fa(x)=%lf\n", a);
	}
	else if (m == 2) {
		printf("fb(x)=%lf\n", b);
	}
	else if (m == 3) {
		printf("fa(x)=%lf , fb(x)=%lf \n", a, b);
	}
	else if (m == 4) {
		printf("произведение %lf, разность квадратов %lf, удвоенная сумма %lf\n", a * b, a * a - b * b, 2.0 * (a + b));
	}
	else {
		printf("fa(x)=%lf , fb(x)=%lf \n", a, b);
		printf("произведение %lf, разность квадратов %lf, удвоенная сумма %lf\n", a * b, a * a - b * b, 2.0 * (a + b));
	}
	return 0;

}

double fa(double x) {
	double y;
	if (x <= 3.0) {
		y = x * x - 3.0 * x + 9.0;
	}
	else {
		y = 1.0 / (x * x * x + 3.0);
	}
	return y;

}

double fb(double x) {
	double y;
	y = x * exp(sin(x * x));
	return y;

}


