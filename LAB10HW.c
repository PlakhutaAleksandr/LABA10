#define _CRT_SECURE_NO_WARNINGS
#define PI 3.141592653589793
#include <stdio.h>
#include <locale.h>
#include <math.h>

float area_rhomboid(float a, float b, float phi1, float phi2);
void draw_rhomboid(int a, int b, float phi1, float phi2, char sym);
void print_definition();

int main() {
    setlocale(LC_ALL, "Russian");

    float a, b, phi1, phi2;
    int m;
    char sym;

    printf("Введите сторону a (верхняя часть): ");
    scanf("%f", &a);

    printf("Введите сторону b (нижняя часть): ");
    scanf("%f", &b);

    printf("Введите угол phi1 (в градусах): ");
    scanf("%f", &phi1);

    printf("Введите угол phi2 (в градусах): ");
    scanf("%f", &phi2);

    printf("\nВыберите операцию:\n");
    printf("1 - рассчитать площадь\n");
    printf("2 - вывести определение фигуры\n");
    printf("3 - нарисовать фигуру\n");
    printf("Ваш выбор: ");
    scanf("%d", &m);

    printf("\n");

    if (m == 1) {
        float s = area_rhomboid(a, b, phi1, phi2);
        printf("Площадь ромбоида (дельтоида): %.2f\n", s);
    }
    else if (m == 2) {
        print_definition();
    }
    else if (m == 3) {
        printf("Введите символ для рисования: ");
        scanf(" %c", &sym);
        printf("\n");
        draw_rhomboid((int)a, (int)b, phi1, phi2, sym);
    }
    else {
        printf("Неверный пункт меню!\n");
    }

    return 0;
}

float area_rhomboid(float a, float b, float phi1, float phi2) {
    double rad1 = phi1 * PI / 180.0;
    double rad2 = phi2 * PI / 180.0;
    double s1 = 0.5 * a * a * sin(rad1);
    double s2 = 0.5 * b * b * sin(rad2);
    return (float)(s1 + s2);
}

void print_definition() {
    printf("Ромбоид (дельтоид) — четырёхугольник, две пары смежных сторон которого равны (a и b), а диагонали пересекаются под прямым углом.\n");
}

void draw_rhomboid(int a, int b, float phi1, float phi2, char sym) {
    double rad1 = phi1 * PI / 180.0;
    double rad2 = phi2 * PI / 180.0;

    int h1 = (int)(a * cos(rad1 / 2.0) + 0.5);
    int w1 = (int)(a * sin(rad1 / 2.0) + 0.5);
    int h2 = (int)(b * cos(rad2 / 2.0) + 0.5);
    int w2 = (int)(b * sin(rad2 / 2.0) + 0.5);

    if (h1 < 1) h1 = 1;
    if (w1 < 1) w1 = 1;
    if (h2 < 1) h2 = 1;
    if (w2 < 1) w2 = 1;

    int half_w = w1 > w2 ? w1 : w2;

    for (int i = 0; i < h1; i++) {
        int offset = (h1 == 1) ? half_w : (half_w - (i * w1) / (h1 - 1));
        int span = (h1 == 1) ? 0 : (2 * (i * w1) / (h1 - 1));

        for (int j = 0; j < offset; j++) {
            printf(" ");
        }
        printf("%c", sym);

        if (span > 0) {
            for (int k = 0; k < span - 1; k++) {
                printf(" ");
            }
            printf("%c", sym);
        }
        printf("\n");
    }

    for (int i = 1; i <= h2; i++) {
        int offset = half_w - ((h2 - i) * w2) / h2;
        int span = 2 * (((h2 - i) * w2) / h2);

        for (int j = 0; j < offset; j++) {
            printf(" ");
        }
        printf("%c", sym);

        if (span > 0) {
            for (int k = 0; k < span - 1; k++) {
                printf(" ");
            }
            printf("%c", sym);
        }
        printf("\n");
    }
}
