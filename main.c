#include <stdio.h>

#define MAX_SIZE 100

void inputArray(int array[], int size);
void printArray(const int array[], int size);
int findMin(const int array[], int size);
int findMax(const int array[], int size);
int findMinIndex(const int array[], int size);
int findMaxIndex(const int array[], int size);
long long calculateSum(const int array[], int size);
double calculateAverage(const int array[], int size);
void countElements(const int array[], int size);
void printInRange(const int array[], int size, int a, int b);
int longestIncreasingFragment(const int array[], int size);
void performIndividualTask(const int array[], int size);

int main(void)
{
    int array[MAX_SIZE];
    int size;
    int a, b;

    /* Ограничение на массив */
    printf("Введите размер массива (1..%d): ", MAX_SIZE);
    if (scanf("%d", &size) != 1 || size < 1 || size > MAX_SIZE) {
        printf("Ошибка: недопустимый размер массива.\n");
        return 1;
    }

    inputArray(array, size);
    printArray(array, size);
    countElements(array, size);
    performIndividualTask(array, size);
    
    /* Вывод минимального, маскимального, суммы и среднего */
    printf("Минимум: %d (first index: %d)\n",
        findMin(array, size), findMinIndex(array, size));
    printf("Максимум: %d (first index: %d)\n",
        findMax(array, size), findMaxIndex(array, size));
    printf("Сумма: %lld\n", calculateSum(array, size));
    printf("Среднее ариф-е: %.2f\n", calculateAverage(array, size));

    /* Ограничение на границы диапазона и ввод */
    printf("\nВведите границы диапазона a и b: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Ошибка: неверное число элементов\n");
        return 1;
    }
    if (a > b) {
        int temp = a;
        a = b;
        b = temp; /* Поменять границы местами для правильной расстановки */
    }
    printf("Элементы в [%d, %d]: ", a, b);
    printInRange(array, size, a, b);
    
    return 0;
}

/* Ввод элементов массива */
void inputArray(int array[], int size)
{
    int i;
    printf("Введите %d целое число(а):\n", size);
    for (i = 0; i < size; i++) {
        printf("array[%d] = ", i);
        if (scanf("%d", &array[i]) != 1) {
            printf("Элемент массива должен быть целым числом.\n");
        }
    }
}

/* Вывод элементов массива */
void printArray(const int array[], int size)
{
    int i;

    for (i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i + 1 < size) {  /* Условие для отсутствия пробела после последнего эл-а масссива */
            printf(" ");
        }
    }
    printf("\n");
}

/* Минимальный элемент */
int findMin(const int array[], int size)
{
    int min_value = array[0];
    int i;

    for (i = 1; i < size; i++) {
        if (array[i] < min_value) {
            min_value = array[i];
        }
    }
    return min_value;
}

/* Максимальный элемент */
int findMax(const int array[], int size)
{
    int max_value = array[0];
    int i;

    for (i = 1; i < size; i++) {
        if (array[i] > max_value) {
            max_value = array[i];
        }
    }
    return max_value;
}

/* Индекс минимального */
int findMinIndex(const int array[], int size)
{
    int min_index = 0;
    int i;

    for (i = 1; i < size; i++) {
        if (array[i] < array[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}

/* Индекс максимального */
int findMaxIndex(const int array[], int size)
{
    int max_index = 0;
    int i;

    for (i = 1; i < size; i++) {
        if (array[i] > array[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}

/* Сумма элементов */
long long calculateSum(const int array[], int size)
{
    long long sum = 0;
    int i;

    for (i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

/* Среднее арифметич-е */
double calculateAverage(const int array[], int size)
{
    return calculateSum(array, size) / size;
}

/* Вывод кол-ва отриц., полож., нулевых, четных и нечетных элементов */
void countElements(const int array[], int size)
{
    int positive = 0, negative = 0, zero = 0;
    int even = 0, odd = 0;
    int i;

    for (i = 0; i < size; i++) {
        if (array[i] > 0) {
            positive++;
        } else if (array[i] < 0) {
            negative++;
        } else {
            zero++;
        }

        if (array[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }

    printf("Положительные: %d\n", positive);
    printf("Отрицательные: %d\n", negative);
    printf("Нулевые: %d\n", zero);
    printf("Четные: %d\n", even);
    printf("Нечетные: %d\n", odd);
}

/* Вывод чисел из диапазона */
void printInRange(const int array[], int size, int a, int b)
{
    int i;
    int found = 0;

    for (i = 0; i < size; i++) {
        if (array[i] >= a && array[i] <= b) {
            printf("%d ", array[i]);
            found = 1;
        }
    }

    if (found == 0) {
        printf("нет элементов");
    }
    printf("\n");
}

/* Индивидульное задание */
int longestIncreasingFragment(const int array[], int size)
{
    int current_length = 1;
    int maxi_length = 1;
    int i;

    for (i = 1; i < size; i++) {
        if (array[i] > array[i - 1]) {
            current_length++;
        } else {
            current_length = 1;
        }

        if (current_length > maxi_length) {
            maxi_length = current_length;
        }
    }

    return maxi_length;
}

void performIndividualTask(const int array[], int size)
{
    printf("Длина наибольшего строго возрастающего фрагмента: %d\n",
           longestIncreasingFragment(array, size));
}