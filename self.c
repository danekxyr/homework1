/*
 * Студент: Пылинский Даниил Максимович
 * Группа: ПИ 1-1
 * Лабораторная работа № 18
 * Назначение: Самостоятельная работа. Структура Rectangle и вычисление площади и периметра отдельными функциями
 */

#include <stdio.h>

typedef struct {
    int width;
    int height;
} Rectangle;

long long area(Rectangle r) {
    return (long long)r.width * r.height;
}

long long perimeter(Rectangle r) {
    return 2LL * (r.width + r.height);
}

int main(void) {
    Rectangle rect;

    printf("Enter width and height (1..1000): ");
    if (scanf("%d %d", &rect.width, &rect.height) != 2) {
        puts("Input error");
        return 1;
    }

    if (rect.width < 1 || rect.width > 1000 || rect.height < 1 || rect.height > 1000) {
        puts("Range error");
        return 1;
    }

    printf("Площадь %lld; периметр %lld\n", area(rect), perimeter(rect));
    return 0;
}
