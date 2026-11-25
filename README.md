# Домашнее задание к работе 10

## Условие задач

Составьте программу, которая для заданной пользователем фигуры, например прямоугольника (треугольника или другой фигуры см. инидивидуальное задание работы 9) предлагает меню выбора одной из операций:
1) рассчитать площадь;
2) вывести определение фигуры;
3) нарисовать фигуру.

Для каждой из операций и фигур реализуйте одну собственную функцию вычисления площади с необходимым числом параметров, например :

float area_round( float a); // для круга

float area_rectangle( float a, float b); // для прямоугольника

float area_triangle( float a, float b, float c); // для треугольника

 и рисования  фигуры символом '*' (размеры сторон фигуры пользователь задает в main):

void draw_rectangle( int a, int b);

или рисования  фигуры (вид символа пользователь задает в main):

void draw_round( char a);

Для вывода параметров фигуры:

int get_radius(); // возвращает радиус круга

Для сравнения двух фигур по площади

int compare_round (int a, int b)// возвращает разницу между двумя кругами с радиусами a и b

<img width="1019" height="200" alt="image" src="https://github.com/user-attachments/assets/105c7d08-6093-47a0-8df4-2f20d0b61345" />


## 1. Алгоритм и блок-схема.

### Алгоритм

1. **Начало**
2. **Объявление переменных и ввод параметров:**
   - Считать значения сторон `a` и `b` (тип `float`) и углов `phi1`, `phi2` в градусах.
3. **Выбор операции через меню:**
   - Запросить у пользователя номер операции `m` (`1`, `2` или `3`).
4. **Обработка выбора пользователя (ветвление `if - else if - else`):**
   - Если `m == 1`: вызвать функцию `area_rhomboid(a, b, phi1, phi2)`, перевести углы в радианы, вычислить площади двух частей и вывести итоговое значение с точностью до двух знаков.
   - Если `m == 2`: вызвать функцию `print_definition()` и вывести определение ромбоида (дельтоида).
   - Если `m == 3`: считать символ `sym` и вызвать функцию `draw_rhomboid(...)`, которая рассчитывает размеры и выводит фигуру с помощью циклов.
   - В остальных случаях: вывести сообщение об ошибке «Неверный пункт меню!».
5. **Конец**

### Блок-схема

<img width="2900" height="12634" alt="gost-flowchart (1)" src="https://github.com/user-attachments/assets/66ed0217-3204-4fdd-93f5-68d5ab6a5247" />


## 2. Реализация программы

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


## 3. Результаты работы программы

<img width="778" height="469" alt="image" src="https://github.com/user-attachments/assets/6a46772e-fb00-4224-a35f-33bc8c70522b" />

<img width="2323" height="488" alt="image" src="https://github.com/user-attachments/assets/08279a95-3a65-4e4a-87fc-b021afb320a8" />

<img width="299" height="1001" alt="image" src="https://github.com/user-attachments/assets/660b0dc1-86d6-4a21-96f3-ab6da49583c2" />



## 4. Информация о разработчике

Плахута Александр Андреевич, бТИИИ-262
