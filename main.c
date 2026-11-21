/*
 * Студент: Пылинский Даниил Максимович
 * Группа: ПИ 1-1
 * Домашнее задание № 1 (Вариант 3: Локальные максимумы)
 * Назначение: Ввод, статистический анализ одномерного массива и поиск локальных максимумов
 */

#include <stdio.h>

#define MAX_SIZE 100

int inputArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &array[i]) != 1) {
            return 0;
        }
    }
    return 1;
}

void printArray(const int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i + 1 < size) {
            printf(" ");
        }
    }
    printf("\n");
}

int findMin(const int array[], int size) {
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] < array[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int findMax(const int array[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] > array[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

long long calculateSum(const int array[], int size) {
    long long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

double calculateAverage(const int array[], int size) {
    return (double)calculateSum(array, size) / size;
}

void countSignElements(const int array[], int size, int *pos, int *neg, int *zero) {
    *pos = 0;
    *neg = 0;
    *zero = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > 0) {
            (*pos)++;
        } else if (array[i] < 0) {
            (*neg)++;
        } else {
            (*zero)++;
        }
    }
}

void countParityElements(const int array[], int size, int *even, int *odd) {
    *even = 0;
    *odd = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            (*even)++;
        } else {
            (*odd)++;
        }
    }
}

void printElementsInRange(const int array[], int size, int a, int b) {
    int found = 0;
    printf("Элементы в диапазоне [%d, %d]: ", a, b);
    for (int i = 0; i < size; i++) {
        if (array[i] >= a && array[i] <= b) {
            if (found > 0) {
                printf(" ");
            }
            printf("%d", array[i]);
            found++;
        }
    }
    if (found == 0) {
        printf("отсутствуют");
    }
    printf("\n");
}

void printLocalMaxima(const int array[], int size) {
    int found = 0;
    printf("Локальные максимумы (вариант 3): ");
    for (int i = 1; i < size - 1; i++) {
        if (array[i] > array[i - 1] && array[i] > array[i + 1]) {
            if (found > 0) {
                printf(" ");
            }
            printf("%d", array[i]);
            found++;
        }
    }
    if (found == 0) {
        printf("отсутствуют");
    }
    printf("\n");
}

int main(void) {
    int array[MAX_SIZE];
    int size;

    printf("Введите размер массива (от 1 до %d): ", MAX_SIZE);
    if (scanf("%d", &size) != 1) {
        printf("Ошибка ввода: ожидалось целое число.\n");
        return 1;
    }

    if (size < 1 || size > MAX_SIZE) {
        printf("Ошибка: недопустимый размер массива (допустимо от 1 до %d).\n", MAX_SIZE);
        return 1;
    }

    printf("Введите %d целых элементов массива:\n", size);
    if (!inputArray(array, size)) {
        printf("Ошибка ввода: некорректный элемент массива.\n");
        return 1;
    }

    printf("\nИсходный массив: ");
    printArray(array, size);

    int minIdx = findMin(array, size);
    int maxIdx = findMax(array, size);
    printf("Минимальный элемент: %d (первый индекс: %d)\n", array[minIdx], minIdx);
    printf("Максимальный элемент: %d (первый индекс: %d)\n", array[maxIdx], maxIdx);

    long long sum = calculateSum(array, size);
    double avg = calculateAverage(array, size);
    printf("Сумма элементов: %lld\n", sum);
    printf("Среднее арифметическое: %.2f\n", avg);

    int pos, neg, zero;
    countSignElements(array, size, &pos, &neg, &zero);
    printf("Положительных: %d, отрицательных: %d, нулевых: %d\n", pos, neg, zero);

    int even, odd;
    countParityElements(array, size, &even, &odd);
    printf("Чётных: %d, нечётных: %d\n", even, odd);

    int a, b;
    printf("\nВведите границы диапазона [a, b]: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Ошибка ввода границ диапазона.\n");
        return 1;
    }
    if (a > b) {
        printf("Ошибка: левая граница диапазона больше правой (%d > %d).\n", a, b);
        return 1;
    }

    printElementsInRange(array, size, a, b);
    printLocalMaxima(array, size);

    return 0;
}
